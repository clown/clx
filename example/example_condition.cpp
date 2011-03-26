/* ------------------------------------------------------------------------- */
/*
 *  example_condition.cpp
 *
 *  Copyright (c) 2004 - 2008, clown. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    - Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    - Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    - No names of its contributors may be used to endorse or promote
 *      products derived from this software without specific prior written
 *      permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  Last-modified: Wed 13 Aug 2008 11:53:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "clx/thread.h"

/* ------------------------------------------------------------------------- */
//  trivial_queue
/* ------------------------------------------------------------------------- */
template <class Type>
class trivial_queue {
public:
	typedef Type value_type;
	
	trivial_queue() : list_(), mutex_(), not_empty_() {}
	virtual ~trivial_queue() {}
	
	void enqueue(const value_type& x) {
		clx::mutex::scoped_lock lock(mutex_);
		std::cout << "PSH: " << x << " (rest " << list_.size();
		list_.push_back(x);
		std::cout << " -> " << list_.size() << ")" << std::endl;
		not_empty_.notify_one();
	}
	
	value_type dequeue() {
		clx::mutex::scoped_lock lock(mutex_);
		while (list_.empty()) {
			std::cout << "empty buffer" << std::endl;
			not_empty_.wait(lock);
		}
		value_type tmp = list_.front();
		std::cout << "POP: " << tmp << " (rest " << list_.size();
		list_.pop_front();
		std::cout << " -> " << list_.size() << ")" << std::endl;
		return tmp;
	}
	
	void reset() {
		clx::mutex::scoped_lock lock(mutex_);
		list_.clear();
	}
	
private:
	std::list<value_type> list_;
	clx::mutex mutex_;
	clx::condition not_empty_;
};

trivial_queue<std::string> data_;
clx::once_flag once_ = CLX_ONCE_INIT;

/* ------------------------------------------------------------------------- */
//  init_data
/* ------------------------------------------------------------------------- */
void init_data() {
	std::cout << "reset data queue" << std::endl;
	data_.reset();
}

/* ------------------------------------------------------------------------- */
//  send_something
/* ------------------------------------------------------------------------- */
void send_something() {
	for (int i = 0; i < 10; i++) {
		clx::call_once(once_, init_data); // call_once test
		std::stringstream ss;
		ss << "element[" << i << "]";
		data_.enqueue(ss.str());
	}
}

/* ------------------------------------------------------------------------- */
//  recv_something
/* ------------------------------------------------------------------------- */
void recv_something() {
	std::string s;
	for (int i = 0; i < 10; i++) {
		clx::call_once(once_, init_data); // call_once test
		s = data_.dequeue();
	}
}

/* ------------------------------------------------------------------------- */
//  main
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[]) {
	clx::thread enq_th[2];
	clx::thread deq_th[2];
	
	/*
	 * TODO: 2009/06/03
	 *
	 * detach 属性の場合に頻繁に core dump が発生する．
	 * 恐らく clx::exit() に問題があると思われるので，要調査．
	 */
#if 0
	// 第2引数がtrueの場合は，detach属性（joinで後処理を行う必要がない）
	for (size_t i = 0; i < 2; i++) enq_th[i].start(send_something, true);
	for (size_t i = 0; i < 2; i++) deq_th[i].start(recv_something, true);
	
	/*
	 * detach属性の場合，作成したスレッドが仕事を終える前にメインスレッドが
	 * 終了する可能性があるので，clx::exit(0)で待つ．
	 */
	clx::exit(0);
#endif
	
	for (size_t i = 0; i < 2; i++) enq_th[i].start(send_something);
	for (size_t i = 0; i < 2; i++) deq_th[i].start(recv_something);
	
	for (size_t i = 0; i < 2; i++) enq_th[i].join();
	for (size_t i = 0; i < 2; i++) deq_th[i].join();
	
	std::cout << "end of main thread" << std::endl;
	
	return 0;
}

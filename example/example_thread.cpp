/* ------------------------------------------------------------------------- */
/*
 *  example_thread.cpp
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
 *  Last-modified: Wed 13 Aug 2008 13:00:04 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/thread.h"

clx::mutex m_;

class exfunctor {
public:
	exfunctor() : c_('a') {}
	explicit exfunctor(char c) : c_(c) {}
	
	virtual ~exfunctor() {}
	
	void operator()() {
		for (int i = 0; i < 10; i++) {
			clx::mutex::scoped_lock lk(m_);
			for (int j = 0; j < i+5; j++) std::cout << c_ << std::flush;
			std::cout << '\n' << std::flush;
		}
	}

private:
	char c_;
};

int main(int argc, char* argv[]) {
	try {
		clx::thread t1(exfunctor('A'));
		clx::thread t2(exfunctor('B'));
		
		t1.join();
		t2.join();
	}
	catch (clx::system_error &e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	
	std::cout << std::endl;
	std::cout << "end of main thread" << std::endl;
	
	return 0;
}

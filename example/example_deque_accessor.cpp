/* ------------------------------------------------------------------------- */
/*
 *  example_deque_generator.cpp
 *
 *  Copyright (c) 2009, clown. All rights reserved.
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
 *  Last-modified: Thu 08 Oct 2009 16:19:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <deque>
#include "clx/config.h"
#include "clx/container_generator.h"
#include "clx/container_accessor.h"

/* ------------------------------------------------------------------------- */
//  exdeque
/* ------------------------------------------------------------------------- */
class exdeque :
	private clx::container_generator<std::deque<std::string> >,
	public clx::random_accessor<std::deque<std::string> > {
private:
	typedef clx::container_generator<std::deque<std::string> > generator;
	typedef clx::random_accessor<std::deque<std::string> > accessor;
	
public:
	exdeque() :
		generator(), accessor(member) {}
	
	virtual ~exdeque() throw() {}
	
	void do_something() {
		member.push_back("Hello, world!");
		member.push_back("foo");
		member.push_back("hoge");
		member.push_back("Bye bye.");
	}
};

/* ------------------------------------------------------------------------- */
//  main
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[]) {
	exdeque v;
	v.do_something();
	
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "--" << std::endl;
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;
	
	v.push_back("new element");
	
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "--" << std::endl;
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}

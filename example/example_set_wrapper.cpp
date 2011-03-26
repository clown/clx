/* ------------------------------------------------------------------------- */
/*
 *  example_map_accessor.cpp
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
#include <set>
#include "clx/container_wrapper.h"

/* ------------------------------------------------------------------------- */
//  exset
/* ------------------------------------------------------------------------- */
class exset : public clx::set_wrapper<std::string> {
public:
	exset() : clx::set_wrapper<std::string>() {}
	
	virtual ~exset() throw() {}
	
	void do_something() {
		member.insert("Hello, world!");
		member.insert("foo");
		member.insert("hoge");
		member.insert("Bye bye.");
	}
};

/* ------------------------------------------------------------------------- */
//  main
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[]) {
	exset v;
	v.do_something();
	
	// std::map が持っているメソッドを使用する．
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "--" << std::endl;
	for (exset::const_iterator pos = v.begin(); pos != v.end(); ++pos) {
		std::cout << *pos << std::endl;
	}
	std::cout << std::endl;
	
	if (v.find("Hello, world!") != v.end()) {
		std::cout << "find: Hello, world!" << std::endl;
	}
	std::cout << std::endl;
	
	// equal_range のテスト．
	std::cout << "test equal_range" << std::endl;
	std::cout << "--" << std::endl;
	std::pair<exset::const_iterator, exset::const_iterator> r;
	r = v.equal_range("foo");
	for (exset::const_iterator pos = r.first; pos != r.second; ++pos) {
		std::cout << *pos << std::endl;
	}
	
	return 0;
}


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
#include <map>
#include "clx/container_generator.h"
#include "clx/container_accessor.h"

/* ------------------------------------------------------------------------- */
//  exmap
/* ------------------------------------------------------------------------- */
class exmap :
	private clx::comparable_container_generator<std::map<int, std::string> >,
	public clx::map_accessor<std::map<int, std::string> > {
private:
	typedef clx::comparable_container_generator<std::map<int, std::string> > generator;
	typedef clx::map_accessor<std::map<int, std::string> > accessor;
	
public:
	exmap() : generator(), accessor(member) {}
	
	virtual ~exmap() throw() {}
	
	void do_something() {
		member[0] = "Hello, world!";
		member[1] = "foo";
		member[2] = "hoge";
		member[3] = "Bye bye.";
	}
};

/* ------------------------------------------------------------------------- */
//  main
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[]) {
	exmap v;
	v.do_something();
	
	// std::map が持っているメソッドを使用する．
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "--" << std::endl;
	for (exmap::iterator pos = v.begin(); pos != v.end(); ++pos) {
		std::cout << pos->first << ": " << pos->second << std::endl;
	}
	std::cout << std::endl;
	
	if (v.find(0) != v.end()) {
		std::cout << "find: " << v[0] << std::endl;
	}
	std::cout << std::endl;
	
	// equal_range のテスト．
	std::cout << "test equal_range" << std::endl;
	std::cout << "--" << std::endl;
	std::pair<exmap::const_iterator, exmap::const_iterator> r;
	r = v.equal_range(0);
	for (exmap::const_iterator pos = r.first; pos != r.second; ++pos) {
		std::cout << pos->first << ": " << pos->second << std::endl;
	}
	
	return 0;
}

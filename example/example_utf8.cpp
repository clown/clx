/* ------------------------------------------------------------------------- */
/*
 *  example_utf8.cpp
 *
 *  Copyright (c) 2004 - 2009, clown. All rights reserved.
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
 *  Last-modified: Tue 11 Aug 2009 19:16:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <vector>
#include "clx/utf8.h"

int main(int argc, char* argv[]) {
	std::string s = "はろーわーるど！ This is a UTF-8 test program.";
	std::cout << "size: " << s.size() << std::endl;
	std::cout << "char count: " << clx::utf8::distance(s) << std::endl;
	
	std::string::iterator pos = s.begin();
	int n = 0;
	while (pos != s.end()) {
		clx::utf8::advance(pos, 1);
		clx::utf8::advance(pos, -1);
		clx::utf8::advance(pos, 1);
		++n;
	}
	std::cout << "char count: " << std::dec << n << std::endl;
	
	pos = s.begin();
	while (pos != s.end()) {
		std::string dest;
		clx::utf8::get(pos, s.end(), std::insert_iterator<std::string>(dest, dest.end()));
		for (size_t i = 0; i < dest.size(); ++i) {
			std::cout << "<" << std::hex << (static_cast<size_t>(dest.at(i)) & 0xff) << ">";
		}
		std::cout << std::endl;
	}
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_ini.cpp
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
 *  Last-modified: Wed 28 Mar 2007 16:14:09 JST
 */
/* ------------------------------------------------------------------------- */
#define CLX_USE_WCHAR
#include <iostream>
#include "clx/ini.h"

int main(int argc, char* argv[]) {
	if (argc < 2) std::exit(-1);
	
	try {
		clx::ini ini(argv[1]);
		
		ini.insert("hoge");
		ini["hoge"]["fuga"] = "foo";
		for (clx::ini::iterator p = ini.begin(); p != ini.end(); p++) {
			std::cout << "***" << p->first << "***" << std::endl;
			for (clx::ini::sub_iterator q = p->second.begin(); q != p->second.end(); q++) {
				std::cout << '<' << q->first << "><" << q->second << '>' << std::endl;
			}
		}
		
		if (ini.exist("Settings", "AnonymousRecipient")) {
			std::cout << "found!" << std::endl;
		}
	}
	catch (clx::syntax_error& e) {
		std::cerr << argv[1] << ':' << e.line() << ": error: " << e.what() << std::endl;
		std::exit(-1);
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	
	return 0;
}

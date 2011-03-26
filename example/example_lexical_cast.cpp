/* ------------------------------------------------------------------------- */
/*
 *  example_lexical_cast.cpp
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
 *  Last-modified: Fri 11 Jul 2008 08:33:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <cstdlib>
#include <iostream>
#include <string>
#include "clx/lexical_cast.h"

int main(int argc, char* argv[]) {
	std::string s1 = "326";
	std::string s2 = "0xf2a";
	std::string serr = "nonum";
	
	try {
		int a = clx::lexical_cast<int>(s1, std::ios::oct);
		int b = clx::lexical_cast<int>(s2, std::ios::showbase);
		
		std::cout << "str " << s1 << ", val " << a << std::endl;
		std::cout << "str " << s2 << ", val " << b << std::endl;
		
		std::string s3 = clx::lexical_cast<std::string>(a, std::ios::hex);
		std::cout << "val " << a << ", str " << s3 << std::endl;
		
		std::string s4 = clx::lexical_cast<std::string>(s3);
		std::cout << "str1 " << s3 << ", str2 " << s4 << std::endl;
		
		int c = clx::lexical_cast<int>(serr);
		std::cout << "str " << serr << ", val " << c << std::endl;
	}
	catch (clx::bad_lexical_cast e) {
		std::cerr << "exeption: " << e.what() << std::endl;
		std::exit(-1);
	}
	
	return 0;
}


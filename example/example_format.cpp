/* ------------------------------------------------------------------------- */
/*
 *  example_format.cpp
 *
 *  Copyright (c) 2004 - 2010, clown. All rights reserved.
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
 *  Last-modified: Fri 30 Jul 2010 20:37:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <cstdio>
#include "clx/format.h"

int main(int argc, char* argv[]) {
	double pi = 3.141592684;
	std::string hello = "Hello, world. This is a test program";
	std::string test = "Output pi with two kinds of format";
	std::string fmt = "%s.\n%s: %#+10.7f, %.5e.";
	
	std::cout << "Output by using formatter class." << std::endl;
	std::cout << "---" << std::endl;
	std::cout << clx::format(fmt) % hello % test % pi % pi << std::endl;
	std::cout << std::endl;
	
	// compared with the printf() function
	std::printf("Output by using printf function\n");
	std::printf("---\n");
	std::printf(fmt.c_str(), hello.c_str(), test.c_str(), pi, pi);
	std::printf("\n\n");
	
	std::cout << "Test of str() function" << std::endl;
	std::cout << "---" << std::endl;
	std::string dest = clx::str(clx::format(fmt) % hello % test % pi % pi);
	std::cout << dest << std::endl;
	
	return 0;
}

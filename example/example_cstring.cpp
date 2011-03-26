/* ------------------------------------------------------------------------- */
/*
 *  example_cstring.cpp
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
 *  Last-modified: Wed 15 Oct 2008 14:23:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/cstring.h"

int main(int argc, char* argv[]) {
	char s1[256] = "Hello, world!";
	char s2[256] = "Hello, world.";
	char s3[256] = "3.1415926";
	
	std::cout << "string: " << s1 << std::endl;
	if (clx::strcmp(s1, s2) == 0) std::cout << "strcmp: match" << std::endl;
	else std::cout << "strcmp: unmatch" << std::endl;
	
	std::cout << "strlen: " << clx::strlen(s1) << std::endl;
	
	clx::strcat(s1, s2);
	std::cout << "strcat: " << s1 << std::endl;
	
	char* last = NULL;
	double pi = clx::strtod(s3, &last);
	std::cout << "strtod: " << pi << std::endl;
	
	return 0;
}

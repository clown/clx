/* ------------------------------------------------------------------------- */
/*
 *  example_md5.cpp
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
 *  Last-modified: Tue 02 Sep 2008 11:41:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "clx/md5.h"

int main(int argc, char* argv[]) {
	std::string s1 = "";
	std::string s2 = "a";
	std::string s3 = "abc";
	std::string s4 = "message digest";
	std::string s5 = "abcdefghijklmnopqrstuvwxyz";
	std::string s6 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	
	clx::md5 md;
	
	std::cout << "str: " << s1 << std::endl;
	std::cout << "md5: " << md.encode(s1).to_string() << std::endl;
	std::cout << std::endl;
	
	std::cout << "str: " << s2 << std::endl;
	std::cout << "md5: " << md.encode(s2).to_string() << std::endl;
	std::cout << std::endl;
	
	std::cout << "str: " << s3 << std::endl;
	std::cout << "md5: " << md.encode(s3).to_string() << std::endl;
	std::cout << std::endl;
	
	std::cout << "str: " << s4 << std::endl;
	std::cout << "md5: " << md.encode(s4).to_string() << std::endl;
	std::cout << std::endl;
	
	std::cout << "str: " << s5 << std::endl;
	std::cout << "md5: " << md.encode(s5).to_string() << std::endl;
	std::cout << std::endl;
	
	std::cout << "str: " << s6 << std::endl;
	std::cout << "md5: " << md.encode(s6).to_string() << std::endl;
	std::cout << std::endl;
	
	return 0;
}

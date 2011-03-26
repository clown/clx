/* ------------------------------------------------------------------------- */
/*
 *  example_sha1.cpp
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
#include <cstdlib>
#include "clx/sha1.h"

int main(int argc, char* argv[]) {
	std::string s1 = "abc";
	std::string s2 = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
	std::string s3 = "a";
	std::string s4 = "0123456701234567012345670123456701234567012345670123456701234567";
	
	clx::sha1 hash;
	
	std::cout << "str: " << s1 << std::endl;
	std::cout << "sha1: " << hash.encode(s1).to_string() << std::endl;
	std::cout << std::endl;
	
	std::cout << "str: " << s2 << std::endl;
	std::cout << "sha1: " << hash.encode(s2).to_string() << std::endl;
	std::cout << std::endl;
	
	std::cout << "str: " << s3 << std::endl;
	hash.reset();
	for (int i = 0; i < 1000000; i++) {
		hash.update(s3.c_str(), s3.size());
	}
	hash.finish();
	std::cout << "sha1: " << hash.to_string() << std::endl;
	std::cout << std::endl;
	
	std::cout << "str: " << s4 << std::endl;
	hash.reset();
	for (int i = 0; i < 10; i++) {
		hash.update(s4.c_str(), s4.size());
	}
	hash.finish();
	std::cout << "sha1: " << hash.to_string() << std::endl;
	std::cout << std::endl;
	
	return 0;
}

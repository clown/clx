/* ------------------------------------------------------------------------- */
/*
 *  example_hmac_sha1.cpp
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
 *  Last-modified: Fri 26 Dec 2008 21:42:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/hmac.h"
#include "clx/sha1.h"

int main(int argc, char* argv[]) {
	// test_case = 1
	char key1[21];
	char dat1[9] = "Hi There";
	
	for (size_t i = 0; i < sizeof(key1) - 1; ++i) key1[i] = 0x0b;
	std::cout << "case 1: "
		<< clx::hmac<clx::sha1>(key1, sizeof(key1) - 1, dat1, sizeof(dat1) - 1).to_string()
		<< std::endl;
	
	// test_case = 2
	char key2[5] = "Jefe";
	char dat2[29] = "what do ya want for nothing?";
	
	std::cout << "case 2: "
		<< clx::hmac<clx::sha1>(key2, sizeof(key2) - 1, dat2, sizeof(dat2) - 1).to_string()
		<< std::endl;
	
	// test_cast = 3
	char key3[21];
	char dat3[51];
	
	for (size_t i = 0; i < sizeof(key3) - 1; ++i) key3[i] = 0xaa;
	for (size_t i = 0; i < sizeof(dat3) - 1; ++i) dat3[i] = 0xdd;
	std::cout << "case 3: "
		<< clx::hmac<clx::sha1>(key3, sizeof(key3) - 1, dat3, sizeof(dat3) - 1).to_string()
		<< std::endl;
	
	// test_cast = 4
	char key4[26];
	char dat4[51];
	
	for (size_t i = 0; i < sizeof(key4) - 1; ++i) key4[i] = i + 1;
	for (size_t i = 0; i < sizeof(dat4) - 1; ++i) dat4[i] = 0xcd;
	std::cout << "case 4: "
		<< clx::hmac<clx::sha1>(key4, sizeof(key4) - 1, dat4, sizeof(dat4) - 1).to_string()
		<< std::endl;
	
	// test_cast = 5
	char key5[21];
	char dat5[21] = "Test With Truncation";
	
	for (size_t i = 0; i < sizeof(key5) - 1; ++i) key5[i] = 0x0c;
	std::cout << "case 5: "
		<< clx::hmac<clx::sha1>(key5, sizeof(key5) - 1, dat5, sizeof(dat5) - 1).to_string()
		<< std::endl;
	
	// test_case = 6
	char key6[81];
	char dat6[55] = "Test Using Larger Than Block-Size Key - Hash Key First";
	
	for (size_t i = 0; i < sizeof(key6) - 1; ++i) key6[i] = 0xaa;
	std::cout << "case 6: "
		<< clx::hmac<clx::sha1>(key6, sizeof(key6) - 1, dat6, sizeof(dat6) - 1).to_string()
		<< std::endl;
	
	// test_case = 7
	char key7[81];
	char dat7[74] = "Test Using Larger Than Block-Size Key and Larger Than One Block-Size Data";
	
	for (size_t i = 0; i < sizeof(key7) - 1; ++i) key7[i] = 0xaa;
	std::cout << "case 7: "
		<< clx::hmac<clx::sha1>(key7, sizeof(key7) - 1, dat7, sizeof(dat7) - 1).to_string()
		<< std::endl;
	
	return 0;
}

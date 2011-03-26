/* ------------------------------------------------------------------------- */
/*
 *  example_reverse.cpp
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
 *  Last-modified: Fri 30 Jul 2010 22:16:03 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/memory.h"

int main(int argc, char* argv[]) {
	unsigned char test1 = 0x12;
	std::cout << std::hex << std::showbase << "char: " << static_cast<int>(test1)
		<< ", " << static_cast<int>(clx::reverse_copy(test1)) << std::endl;
	
	unsigned short test2 = 0x1234;
	std::cout << std::hex << std::showbase << "short: " << test2 << ", "
		<< clx::reverse_copy(test2) << std::endl;
	
	unsigned int test3 = 0xfedcba98;
	std::cout << std::hex << std::showbase << "int: " << test3 << ", "
		<< clx::reverse_copy(test3) << std::endl;
	
#if !defined(__BORLANDC__)
	unsigned long long test4 = 0xfedcba9876543210ull;
	std::cout << std::hex << std::showbase << "long long: " << test4 << ", "
		<< clx::reverse_copy(test4) << std::endl;
#endif
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_code_convert_2.cpp
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
 *  Last-modified: Thu 17 Dec 2009 23:54:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "clx/code_convert.h"
#include "clx/hexdump.h"

void convert(const std::basic_string<char>& src) {
	std::cout << "source: " << src << std::endl;
	std::cout << "hexdump: " << clx::convert(src, clx::hex_encoder("0x", " ")) << std::endl;
	
	std::basic_string<wchar_t> s1 = clx::widen(src);
	std::cout << "widen: ";
	for (size_t i = 0; i < s1.size(); ++i) {
		std::cout << "0x" << std::hex << static_cast<std::size_t>(s1.at(i)) << " ";
	}
	std::cout << std::endl;
	
	std::basic_string<char> s2 = clx::narrow(s1);
	std::cout << "narrow: " << clx::convert(s2, clx::hex_encoder("0x", " ")) << std::endl;
}

int main(int argc, char* argv[]) {
	std::basic_string<char> ascii = "Hello, world!";
	convert(ascii);
	
	return 0;
}

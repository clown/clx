/* ------------------------------------------------------------------------- */
/*
 *  example_base64.cpp
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
 *  Last-modified: Sat 30 Aug 2008 21:31:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "clx/base64.h"

int main(int argc, char* argv[]) {
	// 入力ストリームからデータを受け取る場合
	std::istreambuf_iterator<char> input(std::cin);
	std::istreambuf_iterator<char> last;
	
	std::string code;
	std::insert_iterator<std::string> ss(code, code.begin());
	clx::base64::encode(input, last, ss);
	
	std::cout << "from std::cin" << std::endl;
	std::cout << "encode: " << code << std::endl;
	std::cout << "decode: ";
	std::ostreambuf_iterator<char> output(std::cout);
	clx::base64::decode(code.begin(), code.end(), output);
	std::cout << std::endl;
	std::cout << std::endl;
	
	// 文字列からデータを受け取る場合
	std::string src = "Hello, world!";
    code = clx::base64::encode(src);
    std::cout << "from std::string" << std::endl;
	std::cout << "encode: " << code << std::endl;
	std::cout << "decode: " << clx::base64::decode(code) << std::endl;
	
	return 0;
}

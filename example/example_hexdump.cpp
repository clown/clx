/* ------------------------------------------------------------------------- */
/*
 *  example_hexdump.h
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
 *  Last-modified: Mon 01 Mar 2010 19:50:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <iterator>
#include <locale>
#include "clx/hexdump.h"

int main(int argc, char* argv[]) {
	std::string s = "Hello, world";
	std::cout << clx::hexdump(s) << std::endl;
	std::cout << clx::convert(s, clx::hex_encoder(false)) << std::endl;
	
#ifdef CLX_USE_WCHAR
	std::wcout.imbue(std::locale("japanese"));
	std::wstring ws = L"ハローワールド。This is a test with wchar_t.";
	std::wcout << clx::hexdump(ws) << std::endl;
#endif
	
	std::istreambuf_iterator<char> input(std::cin);
	std::istreambuf_iterator<char> last;
	std::ostreambuf_iterator<char> out(std::cout);
	clx::convert(input, last, out, clx::hex_encoder("#", " "));
	std::cout << std::endl;
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_code_convert.cpp
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
 *  Last-modified: Fri 29 Aug 2008 02:17:00 JST
 */
/* ------------------------------------------------------------------------- */
#ifndef CLX_USE_WCHAR
#define CLX_USE_WCHAR
#endif // CLX_USE_WCHAR

#include <iostream>
#include <string>
#include "clx/code_convert.h"

int main(int argc, char* argv[]) {
	try {
		std::cout.imbue(std::locale("japanese"));
		std::wcout.imbue(std::locale("japanese"));
		
		// char -> wchar_t
		std::string s = "はろーわーるど";
		std::wstring wcvt = clx::code_convert<wchar_t>(s, std::locale("japanese"));
		
		std::wcout << L"char -> wchar_t" << std::endl;
		std::wcout << L"-----" << std::endl;
		std::cout << "original: " << s << " (" << s.size() << ")" << std::endl;
		std::wcout << L"convert: " << wcvt << L" (" << wcvt.size() << L")" << std::endl;
		std::wcout << std::endl;
		
		// wchar_t -> char
		std::wstring ws = L"ハローワールド";
		std::string cvt = clx::code_convert<char>(ws, std::locale("japanese"));
		
		std::cout << "wchar_t -> char" << std::endl;
		std::cout << "-----" << std::endl;
		std::wcout << L"original: " << ws << L" (" << ws.size() << L")" << std::endl;
		std::cout << "convert: " << cvt << " (" << cvt.size() << ")" << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	
	return 0;
}

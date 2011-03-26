/* ------------------------------------------------------------------------- */
/*
 *  example_json.cpp
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
 *  Last-modified: Fri 29 Aug 2008 01:28:00 JST
 */
/* ------------------------------------------------------------------------- */

// ワイド文字関連のCLXライブラリを使用するために必要
#ifndef CLX_USE_WCHAR
#define CLX_USE_WCHAR
#endif

#include <iostream>
#include <string>
#include "clx/http.h"
#include "clx/uri.h"
#include "clx/code_convert.h"
#include "clx/json.h"

int main(int argc, char* argv[]) {
	if (argc < 3) std::exit(-1);
	
	clx::http session(clx::uri::encode(argv[1]));
	if (!session.get(clx::uri::encode(argv[2]))) {
		std::cerr << "failed to get response" << std::endl;
		std::exit(-1);
	}
	
	/*
	 * parse a hatena bookmark entry.
	 * はてなのJSONは()で括られているので，その部分は除外．
	 */
	std::wstring body = clx::code_convert<wchar_t>(session.body());
	clx::wjson hateb(body.begin() + 1, body.end() - 1);
	
	std::wcout.imbue(std::locale("japanese"));
	for (clx::wjson::iterator pos = hateb.begin(); pos != hateb.end(); pos++) {
		std::wcout << pos->first << L": " << pos->second << std::endl;
	}
	std::wcout << std::endl;
	
	// parse and print the detail of "bookmarks"
	clx::wjson_array bk(hateb[L"bookmarks"]);
	if (bk.empty()) return 0;
	
	std::wcout << L"bookmarks have " << bk.objects().size() << L" object, "
		<< bk.strings().size() << L" string" << std::endl;
	std::wcout << L"-----" << std::endl;
	for (size_t i = 0; i < bk.objects().size(); i++) {
		std::wcout << L"object " << i << L":" << std::endl;
		for (clx::wjson::iterator pos = bk.object(i).begin(); pos != bk.object(i).end(); pos++) {
			std::wcout << L"\t" << pos->first << L": " << pos->second << std::endl;
		}
	}
	
	return 0;
}

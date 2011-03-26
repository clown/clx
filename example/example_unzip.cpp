/* ------------------------------------------------------------------------- */
/*
 *  example_unzip.cpp
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
 *  Last-modified: Mon 01 Jun 2009 13:47:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "clx/unzip.h"
#include "clx/utility.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << argv[0] << " filename" << std::endl;
		std::exit(-1);
	}
	
	std::string path(argv[1]);
	std::string password;
	if (argc > 2) password = argv[2];
	clx::unzip uz(path, password);
	
	// zip アーカイブ内の各ファイル/ディレクトリへ順にアクセスする場合．
	for (clx::unzip::iterator pos = uz.begin(); pos != uz.end(); ++pos) {
		std::cout << pos->path() << std::endl;
		
		std::string buf;
		// 最初の 10 行を表示
		for (size_t i = 0; i < 10; ++i) {
			if (!std::getline(*pos, buf)) break;
			std::cout << "\t" << buf << std::endl;
		}
		std::cout << std::endl;
	}
	
	// zip アーカイブ内のある 1 つのファイルにアクセスする場合．
	clx::unzip::iterator target = uz.find("document/index.html");
	if (target != uz.end()) {
		std::cout << target->path() << " is found." << std::endl;
	}
	
	return 0;
}

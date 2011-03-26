/* ------------------------------------------------------------------------- */
/*
 *  example_smtp.cpp
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
 *  Last-modified: Wed 22 Oct 2008 15:11:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <sstream>
#include "clx/ftp.h"

int main(int argc, char* argv[]) {
	if (argc < 4) {
		std::cerr << "usage " << argv[0] << " host id pass" << std::endl;
		std::exit(-1);
	}
	
	try {
		clx::ftp session(argv[1], 21);
		
		// 各種コマンドのテスト
		session.login(argv[2], argv[3]);
		session.status();
		session.system();
		session.command("HELP");
		session.cd("/public_html");
		session.pwd();
		session.mkdir("tmp");
		session.rmdir("tmp");
		
		/*
		 * list(), retrieve(), store() はデータコネクションを使用する．
		 * データコネクションを用いるメソッドは，最後の引数に
		 * アクティブ接続 (clx::ftp::active) かパッシブ接続 (clx::ftp::passive)
		 * を指定する．尚，省略時はパッシブ接続．
		 */
		session.list("/public_html");
		session.retrieve("/public_html/index.html", "./result.txt", clx::ftp::binary);
		session.store("./example_ftp.cpp", "/public_html/example_ftp.cpp");
		
		session.remove("/public_html/example_ftp.cpp");
		session.finish();
		
		// print message log
		clx::ftp::response_array::reverse_iterator pos;
		for (pos = session.responses().rbegin(); pos != session.responses().rend(); ++pos) {
			std::cout << pos->second << std::endl;
			std::cout << std::endl;
		}
	}
	catch (clx::ftp_error& e) {
		std::cerr << e.code() << ": " << e.what() << std::endl;
		std::exit(-1);
	}
	catch (clx::socket_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	
	return 0;
}

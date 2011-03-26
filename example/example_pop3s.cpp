/* ------------------------------------------------------------------------- */
/*
 *  example_pop3s.cpp
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
 *  Last-modified: Sun 26 Oct 2008 21:59:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "clx/pop3s.h"

int main(int argc, char* argv[]) {
	if (argc < 4) std::exit(-1);
	
	try {
		clx::pop3s session(argv[1], 995);
		
		// APOP が使用できるなら APOP 認証を用いる．
		session.login(argv[2], argv[3], session.apop_support());
		
		std::cout << "status: " << session.status() << std::endl;
		
		// LIST コマンド
		clx::pop3s::list_type list = session.list();
		std::cout << "mail list" << std::endl;
		std::cout << "-----" << std::endl;
		for (size_t i = 0; i < list.size(); ++i) {
			std::cout << list[i] << std::endl;
		}
		std::cout << "-----" << std::endl;
		
		// TOP コマンド
		std::cout << "top [1]" << std::endl;
		std::cout << "-----" << std::endl;
		std::cout << session.top(1, 0) << std::endl;
		std::cout << "-----" << std::endl;
		
		session.finish();
	}
	catch (clx::pop3_error& e) {
		std::cerr << e.what() << std::endl;
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

/* ------------------------------------------------------------------------- */
/*
 *  example_wsse.cpp
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
 *  Last-modified: Tue 02 Sep 2008 11:41:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/http.h"
#include "clx/uri.h"
#include "clx/wsse.h"

int main(int argc, char* argv[]) {
	if (argc < 5) {
		std::cerr << "usage " << argv[0] << " domain path user_id password" << std::endl;
		std::exit(-1);
	}
	
	try {
		clx::http session(clx::uri::encode(argv[1]));
		
		std::map<std::string, std::string> heads;
		heads["X-WSSE"] = clx::wsse(argv[3], argv[4]);
		session.get(clx::uri::encode(argv[2]), heads);
		
		std::cout << "code: " << session.code() << std::endl;
		std::cout << std::endl;
		
		std::cout << "head" << std::endl;
		std::cout << "--" << std::endl;
		for (clx::http::head_iterator pos = session.head().begin(); pos != session.head().end(); pos++) {
			std::cout << pos->first << ": " << pos->second << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "body" << std::endl;
		std::cout << "--" << std::endl;
		std::cout << session.body() << std::endl;
	}
	catch (clx::socket_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_ssl_server.cpp
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
 *  Last-modified: Wed 22 Oct 2008 14:50:03 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "clx/ssl.h"

int recv(clx::ssl::socket& sock);

int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
	try {
		clx::ssl::acceptor s(clx::lexical_cast<int>(argv[1]));
		
		while (1) {
			clx::ssl::socket clt = s.accept("public.key", "private.key");
			std::cout << clt.address().ipaddr() << ':' << clt.address().port()
				<< " Connection was established" << std::endl;
			
			if (recv(clt) == -1) break;
			else {
				std::cout << clt.address().ipaddr() << ':' << clt.address().port()
					<< " Connection was closed" << std::endl;
				clt.close();
			}
		}
	}
	catch (clx::socket_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	catch (clx::sockaddress_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	
	return 0;
}

int recv(clx::ssl::socket& sock)
{
	clx::ssl::sockstream ss(sock);
	std::string msg;
	while (1) {
		std::string buf;
		ss >> buf;
		if (buf.empty()) break;
		msg += buf;
	}
	std::cout << "Receive messages: " << msg << std::endl;
	return 0;
}

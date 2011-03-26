/* ------------------------------------------------------------------------- */
/*
 *  example_tcp_server.cpp
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
 *  Last-modified: Wed 09 Jul 2008 12:23:03 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <ios>
#include <string>
#include "clx/tcp.h"

int recv(clx::tcp::socket sock);

int main(int argc, char* argv[]) {
	if (argc < 2) std::exit(-1);
	try {
		clx::tcp::acceptor s(clx::tcp::port(argv[1]));
		
		while (1) {
			clx::tcp::socket clt = s.accept();
			std::cout << clt.address().ipaddr() << ':' << clt.address().port()
				<< " Connection was established" << std::endl;
			
			if (recv(clt) == -1) break;
			else {
				std::cout << clt.address().ipaddr() << ':' << clt.address().port()
					<< " Connection was closed" << std::endl;
				clt.close();
			}
		}
		s.close();
	}
	catch (clx::socket_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	catch (clx::sockaddress_error& e) {
		std::cerr << e.what() << std::endl;
		std::exit(-1);
	}
	
	return 0;
}

int recv(clx::tcp::socket sock) {
	clx::tcp::sockstream ss(sock);
	std::string buf;
	while (std::getline(ss, buf)) {
		std::cout << buf << std::endl;
	}
	
	return 0;
}

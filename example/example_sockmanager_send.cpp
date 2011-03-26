/* ------------------------------------------------------------------------- */
/*
 *  example_sockmanager_send.cpp
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
 *  Last-modified: Mon 14 Jul 2008 07:19:10 JST
 */
/* ------------------------------------------------------------------------- */
#include <cstdio>
#include <iostream>
#include <string>
#include "clx/tcp.h"

/* ------------------------------------------------------------------------- */
//  send_msg
/* ------------------------------------------------------------------------- */
bool send_msg(clx::tcp::rawsocket* s, clx::tcp::sockmanager& sm) {
	// read string from std::cin
	std::string buf;
	if (!std::getline(std::cin, buf)) {
		sm.stop();
		return false;
	}
	
	// write string to the socket
	for (clx::tcp::sockmanager::iterator pos = sm.begin(); pos != sm.end(); pos++) {
		if (sm.socket(pos)->socket() == s->socket()) continue;
		clx::tcp::sockstream* ss = dynamic_cast<clx::tcp::sockstream*>(sm.socket(pos));
		*ss << buf << std::endl;
	}
	return true;
}

/* ------------------------------------------------------------------------- */
//  recv_msg
/* ------------------------------------------------------------------------- */
bool recv_msg(clx::tcp::rawsocket* s, clx::tcp::sockmanager& sm) {
	clx::tcp::sockstream* ss = dynamic_cast<clx::tcp::sockstream*>(s);
	
	std::string buf;
	if (!std::getline(*ss, buf)) {
		ss->close();
		return false;
	}
	std::cout << buf << std::endl;
	return true;
}

/* ------------------------------------------------------------------------- */
//  main
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "usage: " << argv[0] << " host" << std::endl;
		return -1;
	}
	
	try {
		clx::tcp::sockmanager sm;
		int port = clx::tcp::port(argv[2]);
		sm.add(new clx::tcp::sockstream(argv[1], port), recv_msg);
		sm.add(new clx::tcp::rawsocket(0), send_msg); // for std::cin
		sm.start();
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

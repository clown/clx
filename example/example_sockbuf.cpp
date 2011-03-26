/* ------------------------------------------------------------------------- */
/*
 *  example_sockbuf.cpp
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
 *  Last-modified: Wed 03 Sep 2008 20:22:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "clx/tcp.h"

int main(int argc, char* argv[])
{
	if (argc < 3) return -1;
	
	try {
		clx::tcp::socket s(argv[1], 80);
		
		// sockbuf ‚Æ iostream ‚ð—p‚¢‚Ä sockstream ‚ð¶¬‚·‚é•û–@D
		clx::tcp::sockbuf sbuf(s, 2048);
		std::iostream ss(&sbuf);
		
		std::stringstream query;
		query << "GET /" << argv[2] << " HTTP/1.1\r\n";
		query << "Host: " << argv[1] << "\r\n";
		query << "\r\n";
		ss << query.str() << std::flush;
		
		std::string buf;
		while (std::getline(ss, buf)) std::cout << buf << std::endl;
	}
	catch (clx::socket_error& e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	catch (clx::sockaddress_error& e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	
	return 0;
}

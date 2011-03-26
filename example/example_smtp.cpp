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
#include "clx/smtp.h"
#include "clx/date_time.h"

int main(int argc, char* argv[]) {
	if (argc < 6) {
		std::cerr << "usage " << argv[0] << " host id pass from to" << std::endl;
		std::exit(-1);
	}
	
	try {
		clx::smtp session(argv[1], 25);
		
		/*
		 * 第3引数でSMTP-AUTH の方法を指定する．
		 *   - clx::smtp_auth::plain
		 *   - clx::smtp_auth::login
		 *   - clx::smtp_auth::cram_md5
		 *
		 * clx::smtp_auth::none を指定すると SMTP-AUTH は行わずに EHLO パケット
		 * を送信するのみ．clx::smtp_auth::best を指定すると，
		 * cram_md5 -> plain -> login の順番でサーバがサポートしているかどうか
		 * 調べ，最初にサポートしていた方式で認証を行う．いずれにも対応していない
		 * 場合は，clx::smtp_auth::none を指定した場合と同じ．
		 * 
		 * 第3引数の省略時は，clx::smtp_auth::best．
		 */
		session.login(argv[2], argv[3]);
		
		std::string from(argv[4]);
		std::string to(argv[5]);
		
		// create a sample message
		std::stringstream msg;
		clx::date_time now;
		msg << "Date: " << now.to_string<char>("%a, %d %b %Y %H:%M:%S +0900") << "\r\n";
		msg << "From: " << from << "\r\n";
		msg << "To: " << to << "\r\n";
		msg << "Subject: SMTP test mail\r\n";
		msg << "\r\n";
		msg << "This ia test mail for clx::smtp class.\r\n";
		msg << ".\r\n";
		session.mail(from, to, msg.str());
		session.finish();
		
		// print message log
		clx::smtp::response_array::reverse_iterator pos;
		for (pos = session.responses().rbegin(); pos != session.responses().rend(); ++pos) {
			std::cout << pos->second << std::endl;
			std::cout << std::endl;
		}
	}
	catch (clx::smtp_error& e) {
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

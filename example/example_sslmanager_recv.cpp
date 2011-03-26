/* ------------------------------------------------------------------------- */
/*
 *  example_sockmanager_recv.cpp
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
#include <iostream>
#include <cstring>
#include "clx/ssl.h"

/* ----------------------------------------------------------------- */
//  accept_handler
/* ----------------------------------------------------------------- */
template <class Socket, class Service>
class accept_handler {
public:
	typedef Socket socket_type;
	typedef clx::ssl::acceptor acceptor_type;
	typedef Service service_handler;
	
	explicit accept_handler(const std::string& pub, const std::string& priv) :
		public_(pub), private_(priv) {}
	
	explicit accept_handler(const char* pub, const char* priv) :
		public_(pub), private_(priv) {}
	
	virtual ~accept_handler() throw() {}
	
	template <class T, class SockManager>
	bool operator()(T* s, SockManager& sm) {
		acceptor_type* server = dynamic_cast<acceptor_type*>(s);
		socket_type* client = new socket_type(server->accept(public_, private_));
		if (client == NULL) throw std::bad_alloc();
		
		sm.add(client, service_handler(server->socket()));
		return true;
	}
	
private:
	std::string public_;
	std::string private_;
};

/* ------------------------------------------------------------------------- */
//  chat_service
/* ------------------------------------------------------------------------- */
class chat_service {
public:
	typedef clx::ssl::sockstream socket_type;
	
	chat_service(socket_int s) : accid_(s) {}
	
	template <class SockT, class SockManager>
	bool operator()(SockT* s, SockManager& sm) {
		socket_type* ss = dynamic_cast<socket_type*>(s);
		
		std::string ipaddr = ss->address().ipaddr();
		int port = ss->address().port();
		std::string buf;
		if (!std::getline(*ss, buf)) {
			std::cout << ipaddr << ':' << port << ": connection was closed" << std::endl;
			ss->close();
			return false;
		}
		
		/*
		 * 接続されている全クライアントに受信したメッセージを
		 * message (xxx.xxx.xxx.xxx:port)
		 * という形で送信する．ただし，sockmanager には接続確立用の
		 * ソケットも登録されてあるため，そのソケットには送らないように
		 * 注意する．コンストラクタで接続確立用のソケットのソケット番号
		 * を知らせてもらっている (accid_) ので，その値を基に判断する．
		 */
		buf += " (" + ipaddr + ":" + clx::lexical_cast<std::string>(port) + ")";
		for (typename SockManager::iterator pos = sm.begin(); pos != sm.end(); pos++) {
			if (sm.socket(pos)->socket() == accid_) continue;
			socket_type* os = dynamic_cast<socket_type*>(sm.socket(pos));
			*os << buf << std::endl;
		}
		
		return true;
	}
	
private:
	socket_int accid_; // acceptorのソケット番号
};

/* ------------------------------------------------------------------------- */
//  main
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[]) {
	typedef accept_handler<clx::ssl::sockstream, chat_service> handler_type;
	
	try {
		clx::ssl::sockmanager s;
		int port = clx::ssl::port(argv[1]);
		s.add(new clx::ssl::acceptor(port), handler_type("public.key", "private.key"));
		s.start();
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

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
#include "clx/tcp.h"
#include "clx/sockhandler.h"

/* ------------------------------------------------------------------------- */
//  chat_service
/* ------------------------------------------------------------------------- */
class chat_service {
public:
	typedef clx::tcp::sockstream socket_type;
	
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
		 * �ڑ�����Ă���S�N���C�A���g�Ɏ�M�������b�Z�[�W��
		 * message (xxx.xxx.xxx.xxx:port)
		 * �Ƃ����`�ő��M����D�������Csockmanager �ɂ͐ڑ��m���p��
		 * �\�P�b�g���o�^����Ă��邽�߁C���̃\�P�b�g�ɂ͑���Ȃ��悤��
		 * ���ӂ���D�R���X�g���N�^�Őڑ��m���p�̃\�P�b�g�̃\�P�b�g�ԍ�
		 * ��m�点�Ă�����Ă��� (accid_) �̂ŁC���̒l����ɔ��f����D
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
	socket_int accid_; // acceptor�̃\�P�b�g�ԍ�
};

/* ------------------------------------------------------------------------- */
//  main
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[]) {
	typedef clx::tcp::accept_handler<clx::tcp::sockstream, chat_service> handler_type;
	
	try {
		clx::tcp::sockmanager s;
		int port = clx::tcp::port(argv[1]);
		s.add(new clx::tcp::acceptor(port), handler_type());
		s.start();
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

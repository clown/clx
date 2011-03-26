/* ------------------------------------------------------------------------- */
/*
 *  example_icmp.cpp
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
 *  Last-modified: Sun 27 Jul 2008 12:12:03 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include "clx/icmp.h"
#include "clx/timer.h"
#include "clx/argument.h"
#include "clx/format.h"

int main(int argc, char* argv[]) {
	clx::argument arg(argc, argv);
	if (arg.head().empty()) {
		std::cerr << "usage " << argv[0] << " hostname [-l data_bytes]" << std::endl;
		return -1;
	}
	
	/* bufは送受信兼用バッファ．
	 *   -send()メソッド: payload + ICMPヘッダ長
	 *   -recv()メソッド: payload + IPヘッダ長 + ICMPヘッダ長
	 * 以上を考慮して大きめに領域を確保する．
	 */
	clx::icmp::packet_header hdr;
	int payload = 56;
	arg("l,length", payload);
	int packetsize = payload + hdr.icmp_size();
	int buffsize = packetsize + 1024;
	std::auto_ptr<char> buf(new char[buffsize]);
	
	try {
		clx::icmp::socket s(arg.head().at(0));
		std::cout << clx::format("ICMP ECHO %s (%s): %d data bytes")
			% arg.head().at(0) % s.to().ipaddr() % payload
		<< std::endl;
		
		int seq = 0;
		while (1) {
			std::memset(buf.get(), 'a', packetsize);
			
			// sending ICMP echo request
			hdr.reset();
			hdr.icmp()->type = ICMP_ECHO_REQUEST;
			hdr.icmp()->sequence = seq;
			std::memcpy(buf.get(), (char*)hdr.icmp(), hdr.icmp_size());
			s.send(buf.get(), packetsize);
			clx::timer t;
			
			// receiving ICMP echo packet
			std::memset(buf.get(), 0, buffsize);
			int len = s.recv(buf.get(), buffsize);
			if (len < 0) return -1;
			double recv = t.total_elapsed();
			
			// print information
			hdr = buf.get();
			if (hdr.icmp()->type == ICMP_ECHO_REPLY) {
				std::cout << clx::format("%d bytes from %s: icmp_seq=%d ttl=%d time=%d ms")
					% len % s.from().ipaddr()
					% static_cast<int>(hdr.icmp()->sequence)
					% static_cast<int>(hdr.ip()->ttl)
					% static_cast<int>(recv * 1000)
				<< std::endl;
				seq = hdr.icmp()->sequence + 1;
			} else {
				std::cerr << clx::format("received ICMP packet (type: %d) from %s")
					% static_cast<int>(hdr.icmp()->type) % s.from().ipaddr()
				<< std::endl;
			}
			
			clx::sleep(1.0);
		}
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

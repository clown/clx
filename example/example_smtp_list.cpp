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
 *  Last-modified: Fri 14 Nov 2008 02:55:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "clx/smtp.h"
#include "clx/date_time.h"

/* ------------------------------------------------------------------------- */
/*
 *  sendmail
 *
 *  From, To, Cc, Bcc, Subject, および本文を登録しておき，メール送信時
 *  に整形して送信するためのクラス．
 */
/* ------------------------------------------------------------------------- */
enum { mailto = 0, mailcc, mailbcc };
class sendmail {
public:
	typedef char char_type;
	typedef std::basic_string<char_type> string_type;
	typedef std::list<string_type> mailing_list;
	
	sendmail() : to_(), cc_(), bcc_(),
		from_(), subject_(), message_() {}
		
	virtual ~sendmail() {}
	
	sendmail& add(const string_type& addr, int type = mailto) {
		switch (type) {
		case mailto:
			to_.push_back(addr);
			break;
		case mailcc:
			cc_.push_back(addr);
			break;
		case mailbcc:
			bcc_.push_back(addr);
			break;
		default:
			break;
		}
		
		return *this;
	}
	
	sendmail& from(const string_type& addr) {
		from_ = addr;
		return *this;
	}
	
	sendmail& subject(const string_type& s) {
		subject_ = s;
		return *this;
	}
	
	sendmail& message(const string_type& s) {
		message_ = s;
		return *this;
	}
	
	template <class OutputStream>
	void operator()(OutputStream& sout) {
		std::basic_stringstream<char_type> ss;
		clx::date_time now;
		ss << "Date: " << now.to_string<char>("%a, %d %b %Y %H:%M:%S +0900") << "\r\n";
		ss << "From: " << from_ << "\r\n";
		
		if (!to_.empty()) {
			ss << "To: ";
			this->xmake(ss, to_);
		}
		
		if (!cc_.empty()) {
			ss << "Cc: ";
			this->xmake(ss, cc_);
		}
		
		if (!bcc_.empty()) {
			ss << "Bcc: ";
			this->xmake(ss, bcc_);
		}
		
		ss << "Subject: " << subject_ << "\r\n";
		ss << "\r\n";
		ss << message_ << "\r\n";
		ss << ".\r\n";
		
		sout << ss.str();
	}
	
private:
	mailing_list to_;
	mailing_list cc_;
	mailing_list bcc_;
	
	string_type from_;
	string_type subject_;
	string_type message_;
	
	template <class OutputStream, class MailingList>
	void xmake(OutputStream& sout, const MailingList& lst) {
		if (lst.size() == 1) sout << lst.front() << "\r\n";
		else {
			for (typename MailingList::const_iterator pos = lst.begin(); pos != lst.end(); ++pos) {
				sout << *pos << ", ";
			}
			sout << "\r\n";
		}
	}
};

/* ------------------------------------------------------------------------- */
/*
 *  main
 *
 *  Subject と本文は決めうち．Cc は From に指定されたアドレスを指定する．
 */
/* ------------------------------------------------------------------------- */
int main(int argc, char* argv[]) {
	if (argc < 6) {
		std::cerr << "usage " << argv[0] << " host id pass from to" << std::endl;
		std::exit(-1);
	}
	
	std::string from(argv[4]);
	std::string to(argv[5]);
	
	sendmail f;
	
	f.from(from);
	f.add(to, mailto);
	f.add(from, mailcc);
	f.subject(std::string("SMTP test mail"));
	f.message(std::string("This is a test mail for clx::smtp class."));
	
	try {
		clx::smtp session(argv[1], 25);
		session.login(argv[2], argv[3]);
		
		std::list<std::string> lst;
		lst.push_back(to);		// To
		lst.push_back(from);	// Cc
		session.mail(from, lst, f);
		session.finish();
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

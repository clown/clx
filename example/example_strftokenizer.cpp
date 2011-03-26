/* ------------------------------------------------------------------------- */
/*
 *  example_strftokenizer.cpp
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
 *  Last-modified: Tue 21 Feb 2006 23:34:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/tokenizer.h"

int main(int argc, char* argv[]) {
	std::string s = "23:30:25.030254  IP  192.168.1.2.100 > 192.168.1.3.200: . ack 12 win 256 <XXX>";
	std::string fmt = "%s:%s:%s.%s IP %s > %s: %s ack %s win %s <%s>";
	
	/*
	 * memo:
	 * clx::strftokenizer tok(clx::format_separator<char>(fmt));
	 * と記述すると，下の行のtok.assign(s)，tok.size()でコンパイルエラーになる．
	 * 原因が分からないので保留．
	 * gcc version 3.4.4 (cygming special)
	 */
	clx::format_separator<char> f(fmt);
	clx::strftokenizer tok(f);
	
	tok.assign(s);
	std::cout << "Member: " << tok.size() << std::endl;
	for (unsigned int i = 0; i < tok.size(); i++) {
		std::cout << '<' << tok[i] << "> ";
	}
	std::cout << std::endl;
	
	return 0;
}

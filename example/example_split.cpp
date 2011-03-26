/* ------------------------------------------------------------------------- */
/*
 *  example_split.cpp
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
 *  Last-modified: Mon 22 Oct 2007 17:22:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <vector>
#include "clx/salgorithm.h"

int main(int argc, char* argv[]) {
	std::string s = "apple orange,strawberry pineapple,,,";
	std::cout << "original: " << s << std::endl;
	
	/*
	 * スペース，タブ文字，コンマを区切り文字として分割する．
	 * ただし，空のトークンは認めない（無視する）．
	 */
	std::cout << "split: ";
	std::vector<std::string> tok;
	clx::split_if(s, tok, clx::is_any_of(" \t,"));
	for (unsigned int i = 0; i < tok.size(); i++) {
		std::cout << '<' << tok.at(i) << "> ";
	}
	std::cout << std::endl;
	
	std::string result;
	clx::join(tok, result, "=");
	std::cout << "join: " << result << std::endl;
	
	return 0;
}

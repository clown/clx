/* ------------------------------------------------------------------------- */
/*
 *  example_istream_utility.cpp
 *
 *  Copyright (c) 2004 - 2010, clown. All rights reserved.
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
 *  Last-modified: Wed 13 Jan 2010 13:35:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "clx/utility.h"

int main(int argc, char* argv[]) {
	if (argc < 2) std::exit(-1);
	
	std::fstream fs(argv[1]);
	
	std::string s;
	if (!clx::read(fs, s)) std::cout << "error: something is wrong." << std::endl;
	else std::cout << "file size: " << s.size() << std::endl;
	
	fs.clear(); // EOF フラグ等をクリア
	fs.seekg(0);
	
	char buf[256];
	std::size_t n = clx::read(fs, buf);
	if (n == 0) std::cout << "empty" << std::endl;
	else std::cout << std::string(buf, std::min(n, sizeof(buf))) << std::endl;
	
	return 0;
}

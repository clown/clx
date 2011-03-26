/* ------------------------------------------------------------------------- */
/*
 *  example_filesystem.cpp
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
 *  Last-modified: Wed 20 Jan 2010 10:21:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "clx/filesystem.h"

int main(int argc, char* argv[]) {
	std::string from(argc < 2 ? "example_filesystem.cpp" : argv[1]);
	if (clx::filesystem::exists(from)) {
		std::cout << from << ": create a backup file." << std::endl;
		std::string to(from);
		to += ".bak";
		clx::filesystem::copy(from, to);
	}
	else std::cout << from << ": cannot find the file." << std::endl;
	
	std::string root(".");
	std::vector<std::string> v;
	clx::filesystem::list(root, std::back_inserter(v));
	std::cout << "list " << v.size() << " files and directories." << std::endl;
	std::cout << "-----" << std::endl;
	for (std::vector<std::string>::iterator pos = v.begin(); pos != v.end(); ++pos) {
		std::cout << *pos << std::endl;
	}
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  range_iterator.h
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
 *  Last-modified: Wed 06 Jan 2010 13:42:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <iterator>
#include <vector>
#include "clx/range.h"

int main(int argc, char* argv[]) {
	std::vector<int> a;
	a.push_back(1);
	a.push_back(5);
	a.push_back(3);
	std::cout << "size: " << clx::size(a) << std::endl;
	std::copy(clx::begin(a), clx::end(a), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	if (clx::empty(a)) std::cout << "empty!" << std::endl;
	std::cout << std::endl;
	
	int b[5];
	b[0] = 2;
	b[1] = 4;
	b[2] = 6;
	b[3] = 8;
	b[4] = 10;
	std::cout << "size: " << clx::size(b) << std::endl;
	std::copy(clx::begin(b), clx::end(b), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	if (clx::empty(b)) std::cout << "empty!" << std::endl;
	std::cout << std::endl;
	
	return 0;
}

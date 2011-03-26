/* ------------------------------------------------------------------------- */
/*
 *  example_vstream.cpp
 *
 *  Copyright (c) 2004 - 2009, clown. All rights reserved.
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
 *  Last-modified: Mon 01 Jun 2009 13:47:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <iterator>
#include <vector>
#include "clx/vstream.h"

template <class InStream, class Type>
bool getdata(InStream& in, Type& dest) {
	typedef typename InStream::char_type char_type;
	in.read(reinterpret_cast<char_type*>(&dest), sizeof(Type));
	if (in.gcount() <= 0) return false;
	return true;
}

int main(int argc, char* argv[]) {
	std::vector<int> v;
	for (int i = 0; i < 100; ++i) v.push_back(i);
	clx::ivstream vs(v);
	
	int data;
	vs.seekg(80);
	vs.seekg(-40, std::ios_base::end);
	while (getdata(vs, data)) std::cout << data << " ";
	std::cout << std::endl;
	
	return 0;
}

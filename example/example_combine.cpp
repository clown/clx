/* ------------------------------------------------------------------------- */
/*
 *  example_combine.cpp
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
 *  Last-modified: Mon 21 Dec 2009 15:41:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include "clx/utility.h"
#include "clx/mpl.h"

template <unsigned char X1, unsigned char X2>
struct hoge {
	static const std::size_t value = (X2 << CHAR_BIT) | X1;
};

int main(int argc, char* argv[]) {
	std::cout << "normal test." << std::endl;
	std::cout << "--" << std::endl;
	
	char x1 = 0xa2;
	char x2 = 0x77;
	char x3 = 0x3d;
	char x4 = 0x84;
	short x5 = 0xb59c;
	
	std::cout << std::hex << clx::combine(x1, x2) << std::endl;
	std::cout << std::hex << clx::combine(x1, x5) << std::endl;
	std::cout << std::hex << clx::combine(x3, x4, x5) << std::endl;
	std::cout << std::hex << clx::combine(x1, x2, x3, x4) << std::endl;
	std::cout << std::endl;
	
	std::cout << "container test." << std::endl;
	std::cout << "--" << std::endl;
	
	std::vector<char> v;
	v.push_back(0x35);
	v.push_back(0xf2);
	v.push_back(0x4a);
	v.push_back(0xcb);
	
	std::cout << std::hex << clx::combine(v) << std::endl;
	
	char ar[3];
	ar[0] = 0x32;
	ar[1] = 0xbd;
	ar[2] = 0xe5;
	
	std::cout << std::hex << clx::combine(ar) << std::endl;
	std::cout << std::endl;
	
	std::cout << "meta function test." << std::endl;
	std::cout << "--" << std::endl;
	
	std::size_t hoge = clx::combine('h', 'e', 'l', 'o');
	switch (hoge) {
	case clx::mpl::combine4<'h', 'o', 'g', 'e'>::value:
		std::cout << "hoge" << std::endl;
		break;
	case clx::mpl::combine3<'f', 'o', 'o'>::value:
		std::cout << "foo" << std::endl;
		break;
	case clx::mpl::combine4<'h', 'e', 'l', 'o'>::value:
		std::cout << "Hello, world!" << std::endl;
		break;
	case clx::mpl::combine2<'l', 's'>::value:
		std::cout << "ls" << std::endl;
		break;
	default:
		std::cout << "???" << std::endl;
		break;
	}
	
	std::size_t normal = clx::mpl::combine4<'h', 'e', 'l', 0>::value;
	std::cout << std::hex << normal << std::endl;
	std::size_t dirty = clx::mpl::combine4<'h', 'e', 'l', 0xfe98>::value;
	std::cout << std::hex << dirty << std::endl;
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_combine_2.cpp
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
 *  Last-modified: Mon 21 Dec 2009 17:07:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include "clx/utility.h"
#include "clx/mpl.h"

int main(int argc, char* argv[]) {
	if (argc < 2) std::exit(-1);
	
	std::ifstream ifs(argv[1], std::ios::binary);
	
	// ビットマップファイルは，最初の 2Byte が 'B', 'M'．
	unsigned short magic = 0;
	clx::get(ifs, magic, clx::endian::big);
	if (magic == clx::mpl::combine2<'B', 'M'>::value) {
		std::cout << "Bitmap file." << std::endl;
		return 0;
	}
	ifs.seekg(0);
	
	/*
	 * GIF ファイルは，最初の 3Byte が 'G', 'I', 'F'．
	 * その次の 3Byte がバージョン情報であり，現在有効なバージョンは
	 * '8', '7', 'a' と '8', '9', 'a' の 2 種類．
	 */
	unsigned char sig[3];
	clx::read(ifs, sig);
	if (clx::combine(sig[0], sig[1], sig[2]) == clx::mpl::combine3<'G', 'I', 'F'>::value) {
		unsigned char ver[3];
		clx::read(ifs, ver);
		switch (clx::combine(ver[0], ver[1], ver[2])) {
		case clx::mpl::combine3<'8', '7', 'a'>::value:
			std::cout << "GIF version 87a." << std::endl;
			break;
		case clx::mpl::combine3<'8', '9', 'a'>::value:
			std::cout << "GIF version 89a." << std::endl;
			break;
		default:
			std::cout << "GIF unknown version." << std::endl;
			break;
		}
		return 0;
	}
	
	std::cout << "Unknown file." << std::endl;
	return 0;
}

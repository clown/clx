/* ------------------------------------------------------------------------- */
/*
 *  example_argument.cpp
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
 *  Last-modified: Thu 17 Aug 2006 02:06:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/argument.h"

int main(int argc, char* argv[]) {
	/*
	 * 解析するcmdlineのBNF記法
	 * <program> [<nokey_param>]* (['-'[<key>]+] | ['-'+<key> [<param>]*])*
	 */
	clx::argument p;
	p.assign(argc, argv);
	
	int x, y;
	
	std::cout << "head paramters" << std::endl;
	std::cout << "------------------------------" << std::endl;;
	for (size_t i = 0; i < p.head().size(); i++) std::cout << p.head().at(i) << std::endl;
	std::cout << std::endl;
	
	/*
	 * <key>に対応する<param>へアクセスする場合．
	 * 第一引数には，<key>を指定する．カンマ(',')区切りで複数の<key>を指定する
	 * ことが可能で，最初にヒットした<key>に対応する<param>の値を格納する．
	 *
	 * 第三引数は，<key>に対応する<param>のリストのうち，何番目の<param>を
	 * 格納するか指定する．省略時には，0番目の<param>が格納される．
	 */
	p("s,space", x)('y', y, 2);
	std::cout << "s,space: " << x << std::endl;
	std::cout << "y[2]: " << y << std::endl;
	std::cout << std::endl;
	
	/*
	 * '-'に続く文字列は，それぞれが一つの引数として扱われるため，
	 * p.exist("abc")ではなく，p.exist("b")の条件文と一致する．
	 */
	if (p.exist("abc")) std::cout << "the abc parameter exists." << std::endl;
	if (p.exist('b')) std::cout << "the b parameter exists." << std::endl;
	
	return 0;
}

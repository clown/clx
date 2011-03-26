/* ------------------------------------------------------------------------- */
/*
 *  example_table.cpp
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
 *  Last-modified: Mon 20 Feb 2006 04:10:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <iterator>
#include "clx/table.h"
#include "clx/tokenizer.h"

int main(int argc, char* argv[]) {
	/*
	 * create_tokenizer()は，下記の場合，
	 * clx::basic_tokenizer<clx::char_separator<char>, double>
	 * という型宣言を省略するための補助関数．
	 */
	clx::char_separator<char> sep(','); // 文字列分割のためのポリシークラス
	clx::table<double> v(std::cin, clx::create_tokenizer<double>(sep));
	
	for (size_t i = 0; i < v.size(); i++) {
		double sum = 0.0;
		for (size_t j = 0; j < v[i].size(); j++) sum += v[i][j];
		std::cout << "line " << i + 1 << ": num " << v[i].size()
			<< ", sum " << sum << ", average " << sum / v[i].size() << std::endl;
	}
	
	return 0;
}

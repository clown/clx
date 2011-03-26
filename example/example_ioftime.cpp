/* ------------------------------------------------------------------------- */
/*
 *  example_ioftime.cpp
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
 *  Last-modified: Fri 02 Nov 2007 23:18:23 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "clx/date_time.h"

int main(int argc, char* argv[]) {
	std::string str = "Sat 17 Mar 2007 19:56:19 JST";
	std::string infmt = "%a %d %b %Y %H:%M:%S JST";
	std::cout << "Input string: " << str << std::endl;
	std::cout << "Input format: " << infmt << std::endl;
	std::cout << std::endl;
	
	// 文字列strをinfmtにしたがって解析する．
	clx::date_time input;
	input.from_string(str, infmt);
	
	/*
	 * 時刻をoutfmtのフォーマットで出力する．
	 * iftime::data()は，date_timeクラスの形で解析した時刻を返す．
	 * oftimeには，C標準のstruct tm，time_tを引数に指定することも可能．
	 */
	std::string outfmt = "%x %X";
	std::cout << "Output format: " << outfmt << std::endl;
	std::cout << "Result: " << input.to_string<char>(outfmt) << std::endl;
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_date_time.cpp
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
 *  Last-modified: Fri 02 Nov 2007 23:03:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/format.h"
#include "clx/time.h"

int main(int argc, char* argv[]) {
	std::string fmt = "%a %d %b %Y %H:%M:%S JST";
	
	/*
	 * 現在時刻の取得．
	 * デフォルトコンストラクタは，現在時刻でdate_timeクラスを初期化する．
	 */
	clx::date_time now;
	std::cout << now.to_string<char>(fmt) << std::endl;
	
	// 現在時刻から5年3ヶ月後の時刻を取得．
	clx::date_time t1 = now + clx::years(5) + clx::months(3);
	std::cout << "5 years 3 months passed from now ... ";
	std::cout << t1.to_string<char>(fmt) << std::endl;
	
	std::cout << clx::format("%d days have passed since %d/01/01")
		% now.totaldays() % now.year() << std::endl;
	
	return 0;
}

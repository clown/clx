/* ------------------------------------------------------------------------- */
/*
 *  example_unit.cpp
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
 *  Last-modified: Thu 04 Sep 2008 17:10:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/unit.h"

int main(int argc, char* argv[]) {
	std::cout << clx::nano(1) << ", ";
	std::cout << clx::micro(1) << ", ";
	std::cout << clx::milli(1) << ", ";
	std::cout << clx::kilo(1) << ", ";
	std::cout << clx::mega(1) << ", ";
	std::cout << clx::giga(1) << std::endl;
	
	std::cout << "2M + 34k = " << clx::mega(2) + clx::kilo(34) << std::endl;
	
	// 時間単位の入力値の合計を秒単位で出力
	typedef clx::unit<3600> hour;
	hour sum;
	for (int i = 0; i < 10; i++) sum += i;
	std::cout << sum.value() << " hours -> " << sum << " seconds" << std::endl;
	
	// 分->時間単位への変換
	typedef clx::unit<60> minute;
	minute minutes(1440);
	hour test = clx::unit_cast<hour>(minutes);
	std::cout << minutes.value() << " minutes -> " << test.value() << " hours" << std::endl;
	
	return 0;
}

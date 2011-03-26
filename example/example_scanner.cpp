/* ------------------------------------------------------------------------- */
/*
 *  example_scanner.cpp
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
 *  Last-modified: Fri 31 Mar 2006 13:13:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include "clx/scanner.h"
#include "clx/lexical_cast.h"

class my_assign {
public:
	template <class ValueT>
	void operator()(const std::string& s, ValueT& dest) {
		dest = clx::lexical_cast<ValueT>(s) + 1000;
	}
};

int main(int argc, char* argv[]) {
	std::string fmt = "%s/%s/%s %s:%s:%s";
	std::string s = "2006/03/31 13:00:30";
	int year, mon, day, hour, min, sec;
	
	// scan from string
	clx::scanner(s, fmt) % year % mon % day % hour % min % sec;
	std::cout << "Today is " << day << ' ' << mon << ", " << year << std::endl;
	
	hour = 0;
	min = 0;
	sec = 0;
	
	// scan from cin
	std::cout << "Date: ";
	clx::scanner(std::cin, fmt)(5, sec)(4, min)(3, hour, my_assign());
	std::cout << "Now, it is " << hour << ':' << min << ':' << sec << std::endl;
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_tokenmap.cpp
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
 *  Last-modified: Wed 07 Jun 2006 21:09:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <vector>
#include "clx/tokenmap.h"

typedef clx::basic_tokenmap<clx::format_separator<char> > date_map;

int main(int argc, char* argv[]) {
	std::string dateset = "ymdHMS";
	std::string infmt = "%04y/%02m/%02d %2H:%02M:%02S";
	std::string sdate = "2006/06/06 17:27:00";
	std::cout << "Input format: " << infmt << std::endl;
	std::cout << "Sample: " << sdate << std::endl;
	
	// analyze time string.
	clx::format_separator<char> f(infmt, dateset);
	date_map m(f);
	m.assign(sdate);
	
	// print time with output format.
	std::cout << std::endl;
	std::cout << "Result" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (date_map::const_iterator p = m.begin(); p != m.end(); p++) {
		std::cout << "map[" << p->first << "] = " << p->second << std::endl;
	}
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_any.cpp
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
 *  Distributed under the Boost Software License, Version 1.0. (See
 *  accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 *
 *  Last-modified: Mon 09 Nov 2009 02:15:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "clx/any.h"

struct foo {};

int main(int argc, char* argv[]) {
	clx::any val = 3;
	val = foo();
	
	if (val.type() == typeid(int)) std::cout << val.cast<int>() << std::endl;
	else std::cout << "foo class." << std::endl;
	
	std::vector<clx::any> v;
	v.push_back(3);
	v.push_back(foo());
	v.push_back(std::string("Hello, world!"));
	
	for (std::vector<clx::any>::iterator pos = v.begin(); pos != v.end(); ++pos) {
		if (pos->type() == typeid(int)) std::cout << pos->cast<int>() << std::endl;
		else if (pos->type() == typeid(std::string)) std::cout << pos->cast<std::string>() << std::endl;
		else std::cout << "foo class." << std::endl;
	}
	
	return 0;
}

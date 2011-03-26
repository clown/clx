/* ------------------------------------------------------------------------- */
/*
 *  example_constrained_value.cpp
 *
 *  Copyright (c) 2004 - 2010, clown. All rights reserved.
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
 *  Last-modified: Fri 30 Jul 2010 21:30:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/constrained_value.h"

int main(int argc, char* argv[])
{
	clx::constrained_value<clx::ranged_integer<0, 100> > x;
	clx::constrained_value<clx::ranged_integer<0, 100> > y;
	clx::constrained_value<clx::ranged_integer<0, 50> > z;
	
	/*
	 * MFC や BCC では x.value() や y.value() の代わりに
	 * 単に x, y と記述しても良い．
	 */
	try {
		std::cout << "1st example." << std::endl;
		x = 32;
		std::cout << "x = " << x.value() << std::endl;
		y = 8;
		std::cout << "y = " << y.value() << std::endl;
		y += x + 51 - (2 * 4);
		std::cout << "y = " << y.value() << std::endl;
	}
	catch (std::range_error& e) {
		std::cerr << "exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	try {
		std::cout << "2nd example." << std::endl;
		x = 32;
		std::cout << "x = " << x.value() << std::endl;
		z = 8;
		std::cout << "z = " << z.value() << std::endl;
		z += z.value() + 51 - (2 * 4);
		std::cout << "z = " << z.value() << std::endl;
	}
	catch (std::range_error& e) {
		std::cerr << "exception: " << e.what() << std::endl;
	}
	
	return 0;
}

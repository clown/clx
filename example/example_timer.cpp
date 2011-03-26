/* ------------------------------------------------------------------------- */
/*
 *  example_timer.cpp
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
 *  Last-modified: Thu 07 Sep 2006 00:15:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/timer.h"

int main(int argc, char* argv[]) {
	clx::timer t;
	
	std::cout << "precision: " << t.precision() << " sec." << std::endl;
	std::cout << "start sleep(5.5)" << std::endl;
	clx::sleep(5.5);
	std::cout << "total: " << t.total_elapsed() << " sec." << std::endl;
	std::cout << "latest: " << t.update() << " sec." << std::endl;
	std::cout << std::endl;
	
	std::cout << "start sleep(3.12)" << std::endl;
	clx::sleep(3.12);
	std::cout << "total: " << t.total_elapsed() << " sec." << std::endl;
	std::cout << "latest: " << t.elapsed() << " sec." << std::endl;
	
	return 0;
}

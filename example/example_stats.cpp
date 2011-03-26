/* ------------------------------------------------------------------------- */
/*
 *  example_stats.cpp
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
 *  Last-modified: Fri 02 Nov 2007 21:20:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <iterator>
#include "clx/stats.h"

int main(int argc, char* argv[]) {
	// ïWèÄì¸óÕÇ©ÇÁì«Ç›çûÇﬁ
	std::istream_iterator<int> input(std::cin);
	std::istream_iterator<int> last;
	std::vector<int> v;
	std::copy(input, last, std::inserter(v, v.begin()));
	
	std::cout << "sample: " << v.size() << std::endl;
	std::cout << "mean: " << clx::mean(v.begin(), v.end()) << std::endl;
	std::cout << "stddev: " << clx::stddev(v.begin(), v.end()) << std::endl;
	
	std::pair<double, double> ci = clx::confidence_interval(v.begin(), v.end(), 2.06);
	std::cout << "95% confidence interval: [" << ci.first << ',' << ci.second << ']' << std::endl;
	
	return 0;
}

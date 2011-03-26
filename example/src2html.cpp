/* ------------------------------------------------------------------------- */
/*
 *	src2html.cpp
 *
 *	Copyright (c) 2004 - 2009, clown. All rights reserved.
 *
 *	Redistribution and use in source and binary forms, with or without
 *	modification, are permitted provided that the following conditions
 *	are met:
 *
 *	  - Redistributions of source code must retain the above copyright
 *		notice, this list of conditions and the following disclaimer.
 *	  - Redistributions in binary form must reproduce the above copyright
 *		notice, this list of conditions and the following disclaimer in the
 *		documentation and/or other materials provided with the distribution.
 *	  - No names of its contributors may be used to endorse or promote
 *		products derived from this software without specific prior written
 *		permission.
 *
 *	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *	OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *	TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *	PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *	LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *	Last-modified: Mon 23 Nov 2009 19:23:23 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <iterator>
#include <string>
#include <map>

template <class InIter, class OutIter>
OutIter src2html(InIter first, InIter last, OutIter result) {
	typedef InIter input_iterator;
	typedef typename input_iterator::char_type char_type;
	typedef typename input_iterator::traits_type traits_type;
	typedef std::basic_string<char_type, traits_type> string_type;
	typedef std::map<char_type, string_type> escmap;
	
	escmap esc;
	
	esc['&'] = "&amp;";
	esc['"'] = "&quot;";
	esc['<'] = "&lt;";
	esc['>'] = "&gt;";
	
	while (first != last) {
		char_type c = *first++;
		typename escmap::iterator pos = esc.find(c);
		if (pos != esc.end()) {
			result = std::copy(pos->second.begin(), pos->second.end(), result);
		}
		else *result++ = c;
	}
	
	return result;
}

int main(int argc, char* argv[]) {
	std::ostreambuf_iterator<char> result(std::cout);
	std::istreambuf_iterator<char> input(std::cin);
	std::istreambuf_iterator<char> last;
	
	src2html(input, last, result);
	
	return 0;
}

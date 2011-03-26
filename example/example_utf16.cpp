/* ------------------------------------------------------------------------- */
/*
 *  example_utf16.cpp
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
 *  Last-modified: Wed 10 Mar 2010 22:44:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include <iomanip>
#include "clx/utf16.h"

template <class InIter>
void utf16_to_unicode(InIter first, InIter last) {
	InIter pos = first;
	std::cout << "UTF-16: ";
	while (pos != last) {
		std::cout << "<" << std::hex << static_cast<clx::uint16_t>(*pos) << ">";
		++pos;
	}
	std::cout << std::endl;
	
	pos = first;
	std::cout << "UTF-32: ";
	while (pos != last) {
		std::cout << "<" << clx::utf16::get_unicode(pos, last) << ">";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	const char16_t s1[] = { 0xd842, 0xdf9f, 0x308b }; // 「𠮟る」の UTF-16 表記
	utf16_to_unicode(s1, s1 + sizeof(s1) / sizeof(wchar_t));
	
	return 0;
}

/* ------------------------------------------------------------------------- */
/*
 *  example_resolver.cpp
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
 *  Last-modified: Mon 20 Feb 2006 12:45:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/resolver.h"

int main(int argc , char *argv[]) {
	if (argc < 2) return -1;
	
	clx::resolver addr;
	if (!addr.lookup(argv[1])) {
		std::cerr << "Cannot find " << argv[1] << ": Non-existent domain" << std::endl;
		return -1;
	}
	
	std::cout << "Name: " << addr.hostname() << std::endl;
	
	// print addresses
	if (!addr.addresses().empty()) std::cout << "Address: " << inet_ntoa(addr.addresses().at(0));
	for (size_t i = 1; i < addr.addresses().size(); i++) {
		std::cout << ", " << inet_ntoa(addr.addresses().at(i));
	}
	std::cout << std::endl;
	
	// print aliaseses
	if (!addr.aliases().empty()) std::cout << "Alias: " << addr.aliases().at(0);
	for (size_t i = 1; i < addr.aliases().size(); i++) {
		std::cout << ", " << addr.aliases().at(i);
	}
	std::cout << std::endl;
	
	return 0;
}

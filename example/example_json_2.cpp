/* ------------------------------------------------------------------------- */
/*
 *  example_json_2.cpp
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
 *  Last-modified: Fri 29 Aug 2008 01:28:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <iostream>
#include "clx/http.h"
#include "clx/uri.h"
#include "clx/json.h"

int main(int argc, char* argv[]) {
	clx::http session(clx::uri::encode("search.twitter.com"), 80);
	if (!session.get(clx::uri::encode("/search.json?q=from:tt_clown&rpp=2"))) {
		std::cerr << "failed to get response" << std::endl;
		std::exit(-1);
	}
	
	clx::json response(session.body());
	for (clx::json::iterator pos = response.begin(); pos != response.end(); ++pos) {
		std::cout << pos->first << ": " << pos->second << std::endl;
	}
	
	clx::json_array results(response["results"]);
	for (std::size_t i = 0; i < results.objects().size(); ++i) {
		std::cout << "object " << i << ": size=" << results.object(i).size() << std::endl;
		for (clx::json::iterator pos = results.object(i).begin(); pos != results.object(i).end(); ++pos) {
			std::cout << "\t" << pos->first << ": " << pos->second << std::endl;
		}
	}
	
	return 0;
}

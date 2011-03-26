/* ------------------------------------------------------------------------- */
/*
 *  example_filetype.cpp
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
 *  Last-modified: Mon 11 Jan 2010 04:05:00 JST
 */
/* ------------------------------------------------------------------------- */
#include <cstdlib>
#include <iostream>
#include "clx/filetype.h"

int main(int argc, char* argv[]) {
	if (argc < 2) std::exit(-1);
	
	std::string path(argv[1]);
	std::string type;
	if (clx::is_bmp(path, clx::bmptype::os2)) type = "BMP (OS/2 1.x)";
	else if (clx::is_bmp(path, clx::bmptype::win)) type = "BMP (Windows)";
	else if (clx::is_png(path)) type = "PNG";
	else if (clx::is_gif(path)) type = "GIF";
	else if (clx::is_jpg(path)) type = "JPEG";
	else if (clx::is_wmf(path)) type = "WMF (APM)";
	else if (clx::is_wmf(path, false)) type = "WMF (Windows)";
	else if (clx::is_emf(path)) type = "EMF";
	else if (clx::is_pdf(path)) type = "PDF";
	else if (clx::is_doc(path)) type = "DOC (Binary)";
	else if (clx::is_xls(path)) type = "XLS (Binary)";
	else if (clx::is_ppt(path)) type = "PPT (Binary)";
	else if (clx::is_docx(path)) type = "DOCX (OpenXML)";
	else if (clx::is_xlsx(path)) type = "XLSX (OpenXML)";
	else if (clx::is_pptx(path)) type = "PPTX (OpenXML)";
	else if (clx::is_ttf(path)) type = "TrueType font";
	else if (clx::is_ttc(path)) type = "TrueType font collection";
	else type = "unknown file type";
	
	std::cout << argv[1] << ": " << type << std::endl;
	return 0;
}

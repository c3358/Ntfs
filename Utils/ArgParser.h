#pragma once

/********************************************************************************
* The MIT License (MIT)
*
* Copyright (c) 2015, Aaron M. Bray, aaron.m.bray@gmail.com

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*********************************************************************************/

#include <Windows.h>
#include <string>
#include <iostream>
#include <regex>
#include <map>
#include <codecvt>
#include <vector>


// Contains all valid help request strings.
static WCHAR* helpOpts[] = {
	L"-h",
	L"--help",
	L"/?",
	NULL,
};

// Regex containing valid prefixes for command line arguments.
static WCHAR* delimExp = L"^(--|-|/)";

class ArgParser {
public:
	ArgParser(WCHAR** argv, int argc);
	ArgParser(CHAR** argv, int argc);
	~ArgParser();
	bool helpRequested();
	
	bool getAttribute(std::wstring attrib, std::wstring& out);
	bool getAttribute(std::wstring attrib);

	bool getAttribute(std::string attrib, std::string& out);
	bool getAttribute(std::string attrib);

	bool stripDelims(std::wstring& arg);
	int parseArgs(std::vector<std::wstring>& argv);
	const std::map<std::wstring, std::wstring>& getArgs();

private:
	std::map<std::wstring, std::wstring> args;
	bool help;

	bool hasDelim(std::wstring& arg, std::wstring* storage=NULL);
	bool isHelpOpt(std::wstring& arg);
	bool locate(std::wstring& needle, std::wstring* out = NULL);
};
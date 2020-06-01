#include <iostream>
#include <Windows.h>

#include "TextEncodeChanger.h"

void SampleCode()
{
	// Set charset to UTF-8 for console
	system("chcp 65001");

	TextEncodeChanger tec(std::wstring(L"‚±‚ê‚ÍƒTƒ“ƒvƒ‹‚Å‚·BThis is sample."));

	std::cout << tec.toString(TextEncodeChanger::CODEPAGE_UTF8) << std::endl;

}

int main(int argc, char* argv[])
{
	SampleCode();

	getchar();

	return 0;
}
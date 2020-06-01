#pragma once
#include <string>
#include <Windows.h>

class TextEncodeChanger
{
	using String = std::string;
	using WString = std::wstring;
public:
	TextEncodeChanger() {};
	TextEncodeChanger(WString ws):wstr(ws) {};
	TextEncodeChanger(String st, UINT codePage)
	{
		unsigned int size = MultiByteToWideChar(codePage, 0, st.data(), -1,
																							NULL, NULL);

		wchar_t* buffer = new wchar_t[size];

		MultiByteToWideChar(codePage, 0, st.data(), size, buffer, size);

		wstr = buffer;

		delete[] buffer;
	}
	~TextEncodeChanger() {};
	String toString(UINT codePage)
	{
		unsigned int size = WideCharToMultiByte(codePage, 0, wstr.data(), -1,
																							NULL, NULL, NULL, NULL);
		char* buffer = new char[size];

		WideCharToMultiByte(codePage, 0, wstr.data(), size, buffer, size,
													NULL, NULL);

		String s = buffer;

		delete[] buffer;

		return s;
	}
	WString toWString() { return wstr; };

	const static UINT CODEPAGE_SHIFT_JIS = 932;
	const static UINT CODEPAGE_UTF16_LE = 1200;
	const static UINT CODEPAGE_UTF16_BE = 1201;
	const static UINT CODEPAGE_UTF32_LE = 12000;
	const static UINT CODEPAGE_UTF32_BE = 12001;
	const static UINT CODEPAGE_EUC_JP = 20932;
	const static UINT CODEPAGE_UTF7 = 65000;
	const static UINT CODEPAGE_UTF8 = 65001;
private:
	WString wstr;
};
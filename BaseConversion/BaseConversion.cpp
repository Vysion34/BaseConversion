// BaseConversion.cpp : Defines the entry point for the console application.

/* Dean Hartfield

1-13-2016

Module 02 Activity - Base Conversion

Write a computer program using the C Language which reads any base-10 number 
from the standard input (keyboard) and writes its binary and hexadecimal 
representation to the standard output (monitor).

*/

#include "stdafx.h"
#include <string>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void setConsoleFont() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 20;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int main()
{ 
	setConsoleFont();

	cout << "Enter a base 10 number: ";

	unsigned long number;
	if (cin >> number) {
		// Create a bitset from the number the user entered
		bitset<sizeof(long) * CHAR_BIT> bs(number);

		cout << endl;

		// Output the binary value
		cout << "Binary value: ";
		cout << "0b" << bs.to_string() << endl;

		// Output the hexadecimal value
		cout << "Hexadecimal value: ";
		cout << "0x" << setfill('0') << setw(sizeof(long) * 2) << hex << number << endl;
	}
	else {
		cout << endl;

		// Error not a number
		cerr << "Not a base 10 number." << endl;
	}

	cout << endl;
	system("pause");
    return 0;
}


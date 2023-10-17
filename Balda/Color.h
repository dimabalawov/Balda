#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
class Color
{
public:
	void red(string str, bool mode)//мод отвечает за переход на новую строку
	{
		printf("\033[1;31m");
		cout << str;
		printf("\033[0m");
		if (mode)
			cout << endl;
	}
	void blue(string str, bool mode)
	{
		printf("\033[1;34m");
		cout << str;
		printf("\033[0m");
		if (mode)
			cout << endl;
	}

};


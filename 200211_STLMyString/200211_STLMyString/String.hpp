#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
namespace dongyu
{
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		cout << "���캯��" << endl;

	}

	String(const String& str)
		:_str(new char[strlen(str._str) + 1])
	{
		strcpy(_str, str._str);
		cout << "��������" << endl;
	}

	String& operator=(String str)
	{
		swap(_str, str._str);
		cout << "��ֵ������" << endl;
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};
}
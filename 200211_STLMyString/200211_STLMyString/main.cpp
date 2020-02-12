#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "String.hpp"
using namespace dongyu;

String test(String s)
{
	cout << "test" << endl;
	return s;
}

int main()
{
	String s1("hehe");
	String s2(s1);
	test(s1);
	String s3("haha");
	s2 = s3;
	return 0;
}

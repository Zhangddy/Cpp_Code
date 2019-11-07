#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;



int main2()
{
	string s1("");
	string s2("");

	getline(cin, s1);

	int front;
	int back;

	
	while (s1.find(' ') != s1.npos)
	{
		back = s1.size();
		front = s1.rfind(' ');
		s2.append(s1, front, back);
		s1.resize(front);
	}
	s2 += ' ';
	s2.append(s1);

	int size = s2.size();
	for (size_t i = 0; i < s2.size() - 1; ++i)
	{
		s2[i] = s2[i + 1];
	}
	s2.resize(size - 1);
	cout << s2 << endl;

	system("pause");
	return 0;
}
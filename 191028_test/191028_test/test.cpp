#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;



int main1()
{
	string String;
	int N;
	stack<char> Stack;
	cin >> String >> N;
	bool status = true;

	for (size_t i = 0; i < String.size(); i++)
	{
		if (String[i] == '(')
		{
			Stack.push(String[i]);
		}
		else if (String[i] == ')')
		{
			if (Stack.size() == 0 || Stack.top() != '(')
			{
				status = false;
			}
			else
			{
				Stack.pop();
			}
		}
	}
	if (Stack.size() != 0)
	{
		status = false;
	}
	cout << status << endl;
	system("pause");
	return 0;
}
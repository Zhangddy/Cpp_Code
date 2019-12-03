#include <iostream> 
#include <stdlib.h>
using namespace std;

//1、分别使用引用和宏完成交换方法（使用内联），体会两者异同
//2、按照指定的函数声明，完成函数：
//a、将一个字符串转换为数字，返回值用来校验转换是否成功
//bool strtoi(const char *, int &);
//b、将一个数字通过指定进制按位逆序（直接覆盖原数）
//void sysReverse(int &, int);

// bool strtoi(const char *str, int &n)
//{
//	bool status = false;
//	
//	n = atoi(str);
//
//	if (n)
//	{
//		status = true;
//	}
//	return status;
//}
//

bool strtoi(const char *str, int &n)
{
	if (!str)
	{
		return false;
	}
	while (*str <= ' ')
	{
		str++;
	}
	int flag = 1;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	
	if (*str > '9' || *str < '0')
	{
		return false;
	}
	int sum = 0, tmp;
	int i;
	for (i = 0; str[i] <= '9' && str[i] >= '0'; i++)
	{
		tmp = str[i] - '0';
		sum = sum * 10 + tmp;
	}
	n = sum * flag;
	return true;
}

//指定进制数位遍历
void sysReverse(int &num, int hex)
{
	int i;
	int sum = 0, tmp;
	for (i = num; i; i /= hex)
	{
		tmp = i % hex;
		sum = sum * hex + tmp;
	}
	num = sum;
}
int main() { 

	char s[] = "153";
	int n = 0;
	int num = 1101;
	int hex = 2;
	
	cout << n << endl;
	cout << strtoi(s, n) << endl;
	sysReverse(num, hex);
	cout << num << endl;
	int* p = nullptr;
	cout << n << endl;
	system("pause");
	return 0; 
}

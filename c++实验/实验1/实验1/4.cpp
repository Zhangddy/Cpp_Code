#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//1.对于类MyString, 要求重载‘ + ’运算符后可以计算表达式:a = b + c; 
//表示两个字符串连接。其中a, b, c都是类MyString的对象。

class MyString
{
public:
	string str;
	MyString(string s = "hehe"):
		str(s)
	{
	}
	MyString operator+(MyString s2)
	{
		MyString tmpString;

		tmpString.str = str + s2.str;
		return tmpString;
	}
};

int test4()
{
	MyString s1("hehe");
	MyString s2("haha");
	MyString s3 = s1 + s2;
	system("pause");
	return 0;
}

//使用虚函数编写程序求球体和圆柱体的体积及表面积。
//由于球体和圆柱体都可以看作由圆继承而来，所以可以定义圆类Circle作为基类。
//在Circle类中定义一个数据成员radius和两个虚函数area()和volume()。
//由Circle类派生Sphere类和Column类。
//在派生类中对虚函数area()和volume()重新定义，分别求球体和圆柱体的体积及表面积。

class Circle
{
protected:
	double radius;
	double PAI = 3.14;
public:
	virtual double area() = 0;
	virtual double volume() = 0;
	Circle(double r):
		radius(r)
	{

	}
};

class Sphere : public Circle
{
public:
	Sphere(double r = 0.0):
		Circle(r)
	{

	}
	double area()
	{
		return 4 * PAI * radius * radius;
	}
	double volume()
	{
		return (4 * PAI * radius * radius * radius )/ 3.0;
	}
};
class Column : public Circle
{
	double h; // 高
public:
	Column(double r = 0.0, double dh = 0.0):
		Circle(r),
		h(dh)
	{

	}
	double area()
	{
		return 4 * PAI * radius * radius + h * PAI * 2 * radius;
	}
	double volume()
	{
		return 2 * PAI * radius * radius * h;
	}
};

int main4()
{
	Column c(3, 10);

	cout << c.area() << endl;
	cout << c.volume() << endl;

	system("pause");
	return 0;
}

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//1.������MyString, Ҫ�����ء� + �����������Լ�����ʽ:a = b + c; 
//��ʾ�����ַ������ӡ�����a, b, c������MyString�Ķ���

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

//ʹ���麯����д�����������Բ�����������������
//���������Բ���嶼���Կ�����Բ�̳ж��������Կ��Զ���Բ��Circle��Ϊ���ࡣ
//��Circle���ж���һ�����ݳ�Աradius�������麯��area()��volume()��
//��Circle������Sphere���Column�ࡣ
//���������ж��麯��area()��volume()���¶��壬�ֱ��������Բ�����������������

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
	double h; // ��
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

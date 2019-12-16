//1. 一圆型游泳池如图1所示，现在需在其周围建一圆型过道，并在其四周围上栅栏。
//栅栏价格为35元 / 米，过道造价为20元 / 平方米。
//过道宽度为3米，游泳池半径由键盘输入。要求编程计算并输出过道和栅栏的造价。

//2. 有三个学生组队参加某比赛，每个学生信息包含准考证号，姓名，个人成绩，另团队有一总成绩。
//1)	请写一学生类完成其定义实现。注意其中准考证号的不可变性，团队成绩的共享性；
//2)	编写主程序模拟生成三个学生给其赋值、完成相关信息的输出。

#include <iostream>
#include <vector>
#include <string>
#define PI 3.14

using namespace std;

class Student
{
private:
	const int m_registrationNumber;
	string m_name;
	double m_personalAchievement;
	static double m_teamAchievement;
public:
	Student(int registrationNumbew, string name, double personalAchievement)
		: m_registrationNumber(registrationNumbew)
	{
		m_name = name;
		m_personalAchievement = personalAchievement;
		m_teamAchievement += m_personalAchievement;
	}

	void PrintStudentInfo()
	{
		cout << m_registrationNumber << endl
			<< m_name << endl
			<< m_personalAchievement << endl
			<< m_teamAchievement << endl;
	}
};

double Student::m_teamAchievement = 0.0;

class CalculatePrice
{
	double m_radius;	// 游泳池半径
	double m_fenceCost = 35.0; // 栅栏造价
	double m_corridorCost = 20.0;	// 过道造价
	double m_corridorWidth = 3.0;	// 过道宽度
	double m_corridorPrice;	// 过道价格
	double m_fencePrice;	// 栅栏价格
public:
	CalculatePrice()
	{
		m_radius = 0;
	}

	CalculatePrice(double radius)
	{
		m_radius = radius;
		m_fencePrice = PI * 2 * (m_radius + 3) * m_fenceCost;
		m_corridorPrice = (PI * (m_radius + 3) * (m_radius + 3) - PI * m_radius * m_radius) * m_corridorCost;
	}

	void PrintPrice()
	{	 
		cout << "过道价格: " << m_corridorPrice << "\n栅栏价格: " << m_fencePrice << endl;
	}
};

int main2()
{
	double r;
	cin >> r;
	CalculatePrice c(r);
	c.PrintPrice();
	
	Student s1(1, "张新栋", 3);
	Student s2(2, "萝莉人", 9);
	Student s3(3, "王晨", 10);
	s1.PrintStudentInfo();
	system("pause");
	return 0;
}

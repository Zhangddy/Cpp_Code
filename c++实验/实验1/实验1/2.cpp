//1. һԲ����Ӿ����ͼ1��ʾ��������������Χ��һԲ�͹���������������Χ��դ����
//դ���۸�Ϊ35Ԫ / �ף��������Ϊ20Ԫ / ƽ���ס�
//�������Ϊ3�ף���Ӿ�ذ뾶�ɼ������롣Ҫ���̼��㲢���������դ������ۡ�

//2. ������ѧ����Ӳμ�ĳ������ÿ��ѧ����Ϣ����׼��֤�ţ����������˳ɼ������Ŷ���һ�ܳɼ���
//1)	��дһѧ��������䶨��ʵ�֡�ע������׼��֤�ŵĲ��ɱ��ԣ��Ŷӳɼ��Ĺ����ԣ�
//2)	��д������ģ����������ѧ�����丳ֵ����������Ϣ�������

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
	double m_radius;	// ��Ӿ�ذ뾶
	double m_fenceCost = 35.0; // դ�����
	double m_corridorCost = 20.0;	// �������
	double m_corridorWidth = 3.0;	// �������
	double m_corridorPrice;	// �����۸�
	double m_fencePrice;	// դ���۸�
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
		cout << "�����۸�: " << m_corridorPrice << "\nդ���۸�: " << m_fencePrice << endl;
	}
};

int main2()
{
	double r;
	cin >> r;
	CalculatePrice c(r);
	c.PrintPrice();
	
	Student s1(1, "���¶�", 3);
	Student s2(2, "������", 9);
	Student s3(3, "����", 10);
	s1.PrintStudentInfo();
	system("pause");
	return 0;
}

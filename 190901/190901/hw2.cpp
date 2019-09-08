#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//设计一个日期类，包含以下功能：
//1、只能通过传入年月日初始化。
//2、可以加上一个数字n，返回一个该日期后推n天之后的日期。

class Date
{
	int m_year;
	int m_month;
	int m_day;
	
public:
	Date(int year, int month, int day) :
		m_year(year),
		m_month(month),
		m_day(day)
		{

		}

	void settime(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	void showtime()
	{
		cout << m_year << "-" << m_month << "-" << m_day << endl;
	}

	Date operator +(int delay) const;
	Date operator -(int delay) const;

	bool operator <(const Date & d) const;
	bool operator >(const Date & d) const;
	bool operator <=(const Date & d) const;
	bool operator >=(const Date & d) const;
	bool operator ==(const Date & d) const;
	bool operator !=(const Date & d) const;


	friend ostream &operator << (ostream & os, Date & d);
};

ostream & operator << (ostream & os, Date & d)
{
	os << d.m_year << '-' << d.m_month << '-' << d.m_day;
	return os;
}

Date Date::operator + (int delay) const
{
	Date res = *this;
	int month_arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((res.m_year % 4) == 0 && (res.m_year % 100 != 0) || res.m_year % 400 == 0)
	{
		month_arr[1] = 29;
	}
	while (1)
	{
		if (res.m_day + delay > month_arr[res.m_month - 1])
		{
			if (res.m_month - 1 < 11)
			{
				delay = delay - (month_arr[res.m_month - 1] - m_day);
				res.m_day = 0;
				res.m_month++;
			}
			else 
			{
				res.m_year++;
				if ((res.m_year % 4) == 0 && (res.m_year % 100 != 0) || res.m_year % 400 == 0)
				{
					month_arr[1] = 29;
				}
				else
				{
					month_arr[1] = 28;
				}
				delay = delay - (month_arr[11] - res.m_day);
				res.m_day = 0;
				res.m_month = 1;
			}
		}
		else
		{
			res.m_day += delay;
			break;
		}
	}
	return res;
}

Date Date::operator - (int ahead) const
{
	Date res = *this;
	int month_arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((res.m_year % 4) == 0 && (res.m_year % 100 != 0) || res.m_year % 400 == 0)
	{
		month_arr[1] = 29;
	}
	while (1)
	{
		if (res.m_day - ahead <= 0)
		{
			if (res.m_month - 1 > 0)
			{
				ahead = ahead - res.m_day;
				res.m_month--;
				res.m_day = month_arr[res.m_month - 1];
				
			}
			else
			{
				res.m_year--;
				if ((res.m_year % 4) == 0 && (res.m_year % 100 != 0) || res.m_year % 400 == 0)
				{
					month_arr[1] = 29;
				}
				else
				{
					month_arr[1] = 28;
				}
				ahead = ahead - res.m_day;
				res.m_month = 12;
				res.m_day = month_arr[res.m_month - 1];

			}
		}
		else
		{
			res.m_day -= ahead;
			break;
		}
	}
	return res;
}

bool Date::operator <(const Date & d) const
{
	bool status = false;

	if (m_year < d.m_year)
	{
		status = true;
	}
	if (m_year == d.m_year && m_month < d.m_month)
	{
		status = true;
	}
	if (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day)
	{
		status = true;
	}
	return status;
}

bool Date::operator >(const Date & d) const
{
	bool status = false;

	if (m_year > d.m_year)
	{
		status = true;
	}
	if (m_year == d.m_year && m_month > d.m_month)
	{
		status = true;
	}
	if (m_year == d.m_year && m_month == d.m_month && m_day > d.m_day)
	{
		status = true;
	}
	return status;
}

bool Date::operator <=(const Date & d) const
{
	return !(*this > d);
}
bool Date::operator >=(const Date & d) const
{
	return !(*this < d);
}
bool Date::operator ==(const Date & d) const
{
	if (m_year == d.m_year && m_month == d.m_month && m_day == d.m_day)
	{
		return true;
	}
	return false;
}
bool Date::operator !=(const Date & d) const
{
	return !(*this == d);
}
int main()
{
	Date d(2019, 9, 8);
	Date c(2019, 9, 8);
	d = d + 500;
	c = c - 20;
	cout << c << endl;
	cout << d << endl;
	//int flag = 0;
	//if (c != d)
	//{
	//	flag = 1;
	//}
	//printf("%d", flag);
	system("pause");
	return 0;
}
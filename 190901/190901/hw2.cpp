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

	Date operator + (int delay) const;
	Date operator - (int ahead) const;
	//TODO
	int operator - (const Date & d) const;

	Date& operator ++ ();//左++
	Date operator ++ (int);//右++
	Date operator -- ();//左--
	Date operator -- (int);//右--

	//为左值才用给返回值引用, 如[],=;
	bool operator < (const Date & d) const;
	bool operator > (const Date & d) const;
	bool operator <= (const Date & d) const;
	bool operator >= (const Date & d) const;
	bool operator == (const Date & d) const;
	bool operator != (const Date & d) const;

	friend ostream& operator << (ostream & os, const  Date & d);
};

Date& Date::operator ++ ()
{
	*this = *this + 1;
	return *this;
}

Date Date::operator ++ (int)
{
	Date tmp = *this;
	*this = *this + 1;
	return tmp;
}

Date Date::operator -- ()
{
	*this = *this - 1;
	return *this;
}

Date Date::operator --(int)
{
	Date tmp = *this;
	*this = *this - 1;
	return tmp;
}

ostream & operator << (ostream & os,const Date & d)
{
	os << d.m_year << '-' << d.m_month << '-' << d.m_day;
	return os;
}

 Date Date:: operator + (int delay) const
 {
	 Date res = *this;
	 int month_arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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

int Date::operator - (const Date & d) const
{
	int month_arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date big = *this;
	Date small = d;
	if (*this < d)
	{
		Date tmp = big;
		big = small;
		small = tmp;
	}
	int dif = 0;
	int i, j, k;

	for (i = small.m_year, j = big.m_year; i < j; i++)
	{
		if ((i % 4) == 0 && (i % 100 != 0) || i % 400 == 0)
		{
			month_arr[1] = 29;
		}
		for (k = 0; k < 12; k++)
		{
			dif += month_arr[k];
		}
	}

	if ((small.m_year % 4) == 0 && (small.m_year % 100 != 0) || small.m_year % 400 == 0)
	{
		month_arr[1] = 29;
	}
	if ((big.m_year % 4) == 0 && (big.m_year % 100 != 0) || big.m_year % 400 == 0)
	{
		month_arr[1] = 29;
	}

	int predate = 0;
	for (i = 0; i < small.m_month - 1; i++)
	{
		predate += month_arr[i];
	}
	predate += small.m_day;
	
	int delaydate = 0;
	for (i = 0; i < big.m_month - 1; i++)
	{
		delaydate += month_arr[i];
	}
	delaydate += big.m_day;

	dif = dif + delaydate - predate;

	return dif;
}


bool Date::operator < (const Date & d) const
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

bool Date::operator > (const Date & d) const
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

bool Date::operator <= (const Date & d) const
{
	return !(*this > d);
}
bool Date::operator >= (const Date & d) const
{
	return !(*this < d);
}
bool Date::operator == (const Date & d) const
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
	Date d(2019, 9, 10);
	Date c(1999, 12, 31);
	c++;
	cout << c ;
	system("pause");
	return 0;
}
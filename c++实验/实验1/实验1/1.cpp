//1. 设计程序找出1 - 100间的质数，显示出来。
//2. 把有10个整数元素的数组用冒泡排序法按由小到大升序排列。

//3. 二维数组：M个同学N门课成绩处理，字符数组存放姓名。
//	 运用二维数组能熟练对学生成绩进行输入，查找，排序，输出等功能

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void PrintPrime()
{
	int flag = 1;
	for (int i = 2; i <= 100; ++i)
	{
		flag = 1;
		for (int j = 2; j <= i; ++j)
		{
			if (i % j == 0 && i != j)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			cout << i << " ";
		}
	}
}

void BubleSort(double a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

#define M 3
#define N 3

class Stu
{
	vector<string> stuName;
	vector<vector<double>> stuScore;
	double stuTotalScore[M] = { 0 };
	  
public:
	void PutGrade()
	{
		cout << "请输入" << M << "个名字: \n";
		for (int i = 0; i < M; ++i)
		{
			string s;
			cin >> s;
			stuName.push_back(s);
		}
		for (int i = 0; i < M; ++i)
		{
			vector<double> v;
			cout << "请输入第 " << i + 1 << " 个学生的成绩" << N << "个成绩:\n";
			for (int j = 0; j < N; ++j)
			{
				double s;
				cin >> s;
				v.push_back(s);
				stuTotalScore[i] += v[j];
			}
			stuScore.push_back(v);
		}
	}

	void PrintScore()
	{
		system("cls");
		for (int i = 0; i < M; ++i)
		{
			cout << stuName[i] << "	";
			for (int j = 0; j < N; ++j)
			{
				cout << stuScore[i][j] << "	";
			}
			cout << stuTotalScore[i] << '\n';
		}
	}

	void FindScore() 
	{
		PrintScore();
		cout << "请输入要查询的学生姓名" << endl;
		string tmp;
		cin >> tmp;
		int i = -1;
		for (int j = 0; j < stuName.size(); ++j)
		{
			if (stuName[j] == tmp)
			{
				i = j;
				break;
			}
		}
		if (i != -1)
		{
			cout << "查询结果:" << endl;

			cout << stuName[i] << "	";
			for (int j = 0; j < N; ++j)
			{
				cout << stuScore[i][j] << "	";
			}
			cout << stuTotalScore[i] << '\n';
		}
		else
		{
			cout << "查无此人!" << endl;
		}


	}

	void ScoreSort()
	{
		for (int i = 0; i < M - 1; ++i)
		{
			for (int j = 0; j < M - i - 1; ++j)
			{
				if (stuTotalScore[j] > stuTotalScore[j + 1])
				{
					swap(stuTotalScore[j], stuTotalScore[j + 1]);
					swap(stuScore[j], stuScore[j + 1]);
					swap(stuName[j], stuName[j + 1]);
				}
			}
		}
		PrintScore();
	}
};


int main1()
{ 

	Stu s;
	s.PutGrade();
	s.PrintScore();
	s.ScoreSort();
	s.FindScore();

	return 0;
}



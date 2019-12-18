//1. ��Ƴ����ҳ�1 - 100�����������ʾ������
//2. ����10������Ԫ�ص�������ð�����򷨰���С�����������С�

//3. ��ά���飺M��ͬѧN�ſγɼ������ַ�������������
//	 ���ö�ά������������ѧ���ɼ��������룬���ң���������ȹ���

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
		cout << "������" << M << "������: \n";
		for (int i = 0; i < M; ++i)
		{
			string s;
			cin >> s;
			stuName.push_back(s);
		}
		for (int i = 0; i < M; ++i)
		{
			vector<double> v;
			cout << "������� " << i + 1 << " ��ѧ���ĳɼ�" << N << "���ɼ�:\n";
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
		cout << "������Ҫ��ѯ��ѧ������" << endl;
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
			cout << "��ѯ���:" << endl;

			cout << stuName[i] << "	";
			for (int j = 0; j < N; ++j)
			{
				cout << stuScore[i][j] << "	";
			}
			cout << stuTotalScore[i] << '\n';
		}
		else
		{
			cout << "���޴���!" << endl;
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



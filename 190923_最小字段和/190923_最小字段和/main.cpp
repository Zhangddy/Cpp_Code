#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int dealGreatestSum(vector<int> &array, int begin, int end)
{
	if (begin == end)
	{
		return array[begin];
	}

	int mid = (begin + end) / 2;
	int leftmax = dealGreatestSum(array, begin, mid);
	int rightmax = dealGreatestSum(array, mid + 1, end);

	int crossmax = 0;

	int i;
	int sum = 0;
	int tmpmax = array[mid];
	for (i = mid; i >= begin; i--)
	{
		sum += array[i];
		if (sum > tmpmax)
		{
			tmpmax = sum;
		}
	}
	crossmax += tmpmax;

	sum = 0;
	tmpmax = array[mid + 1];
	for (i = mid + 1; i <= end; i++)
	{
		sum += array[i];
		if (sum > tmpmax)
		{
			tmpmax = sum;
		}
	}
	crossmax += tmpmax;

	return max(max(leftmax, rightmax), crossmax);
}

int FindGreatestSumOfSubArrayWay3(vector<int> array)
{
	return dealGreatestSum(array, 0, array.size() - 1);
}

int FindGreatestSumOfSubArrayWay2(vector<int> data)
{
	int maxSum = data[0];
	int tmp = data[0];

	for (size_t i = 1; i < data.size(); i++)
	{
		if (tmp >= 0)
		{
			tmp += data[i];
		}
		else
		{
			tmp = data[i];
		}

		if (maxSum < tmp)
		{
			maxSum = tmp;
		}
	}
	return maxSum;
}

int FindGreatestSumOfSubArrayWay1(vector<int> data)
{
	int sum = 0;
	int thisSum = 0;
	for (size_t i = 0; i < data.size(); i++)
	{
		thisSum = 0;
		for (size_t j = i; j < data.size(); j++)
		{
			thisSum += data[j];
			if (thisSum > sum)
			{
				sum = thisSum;
			}
		}
	}
	return sum;
}

int main()
{
	int array[8] = { 1, 2, -2, 1, -2 , 1, 3, -5};

	vector<int> data(array, array + 8);

//	cout << FindGreatestSumOfSubArrayWay1(data);
//	cout << FindGreatestSumOfSubArrayWay2(data);
//	cout << FindGreatestSumOfSubArrayWay3(data);
	system("pause");
	return 0;
}
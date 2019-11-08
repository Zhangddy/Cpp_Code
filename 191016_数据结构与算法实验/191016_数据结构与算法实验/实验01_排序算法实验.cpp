#include <iostream>
#include <cstdlib>
#include <ctime>
#include "heap.h"
#include <ctime>
using namespace std;
#define NUM 200000

void PrintArray(double* array, int num)
{
	for (int i = 0; i < num; ++i)
	{
		cout << array[i] << ' ';
	}
}

void InitArray(double* array, int num)
{
	for (int i = 0; i < num; ++i)
	{
		array[i] = ((rand() % 100) * 0.2) - 10;
	}
}

void BubbleSort(double* array, int num)
{
	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = 0; j < num - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}

void SelectSort(double* array, int num)
{
	int i, j;
	int min;
	for (i = 0; i < num; i++)
	{
		min = i;
		for (j = i; j < num; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		swap(array[min], array[i]);
	}
}

void InsertSort(double* array, int num)	//越有序,速度越快
{
	int i, j;
	double tmp;

	for (i = 1; i < num; i++)
	{
		tmp = array[i];

		for (j = i; j > 0 && array[j - 1] > tmp; j--)
		{
			array[j] = array[j - 1];
		}

		array[j] = tmp;
	}
}

void ShellSort(double* array, int num)	//了解
{
	double tmp;
	int gap;
	int i, j, k;
	for (gap = num / 2; gap; gap /= 2)
	{
		for (k = 0; k < gap; k++)
		{
			for (i = gap + k; i < num; i += gap)
			{
				tmp = array[i];
				j = i;
				for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				{
					array[j] = array[j - gap];
				}
				array[j] = tmp;
			}
		}
	}
}

int doublePointerWay(double* array, int start, int end)
{
	int a = start, b = end;
	int flag = 0;


	while (array[b] > array[a])
	{
		b--;
	}

	while (a < b)
	{
		swap(array[b], array[a]);
		flag = !flag;

		while (b >= 0 && a <= end && array[b] >= array[a])	 //  b >= 0 && a <= end &&
		{
			flag ? a++ : b--;
		}
	}
	return flag ? b : a;
}

void dealQuickSort(double* array, int start, int end)
{
	int mid;
	if (start + 8 < end)	//
	{
		mid = doublePointerWay(array, start, end);

		dealQuickSort(array, start, mid - 1);
		dealQuickSort(array, mid + 1, end);
	}
	else
	{
		InsertSort(array + start, end - start + 1);
	}
}

void QuickSort(double* array, int num)
{
	dealQuickSort(array, 0, num - 1);
}

void dealMergeSort(double* array, double* tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int mid = (start + end) / 2;
	dealMergeSort(array, tmp, start, mid);
	dealMergeSort(array, tmp, mid + 1, end);

	int a = start;
	int b = mid + 1;
	int c = start;
	while (a <= mid && b <= end)
	{
		if (array[a] < array[b])
		{
			tmp[c] = array[a];
			a++;
		}
		else
		{
			tmp[c] = array[b];
			b++;
		}
		c++;
	}

	for (; a <= mid; a++, c++)
	{
		tmp[c] = array[a];
	}

	for (; b <= end; b++, c++)
	{
		tmp[c] = array[b];
	}

	int i;
	for (i = start; i <= end; i++)
	{
		array[i] = tmp[i];
	}
}

void MergeSort(double* array, int num)	//归并排序
{
	double* tmp = (double*)malloc(num * sizeof(double));
	dealMergeSort(array, tmp, 0, num - 1);	//入口
	free(tmp);
}

void HeapSort(double* array, int num)
{
	Heap hp;
	HeapInit(&hp, array, num);
	dealHeapSort(&hp);
//	HeapPrint(&hp);
//	HeapPrintS(&hp);
	int i;
	for (i = 0; i < hp.size; i++)
	{
		array[i] = hp.data[i];
	}
	HeapDestory(&hp);
}
int main()
{
	srand((unsigned)time(NULL));

	double* array = (double*)malloc(NUM * sizeof(double));
	InitArray(array, NUM);
	clock_t start = clock();

//	BubbleSort(array, NUM);
//	SelectSort(array, NUM);
//	InsertSort(array, NUM);
//	ShellSort(array, NUM);
	QuickSort(array, NUM);
//	MergeSort(array, NUM);
//	HeapSort(array, NUM);

	PrintArray(array, NUM);
	clock_t end = clock();
	double runtime = ((double)end - (double)start) / CLOCKS_PER_SEC;
	printf("\nRun Time: %.3f s\n", runtime);
	free(array);
	system("pause");
	return 0;
}
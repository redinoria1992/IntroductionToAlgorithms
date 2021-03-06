// MergeSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void merge(int a[], int p, int q, int r);

void merge_sort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

void merge(int a[], int p, int q, int r)
{
	int i, j;
	int n, m;
	n = q - p + 1;
	m = r - q;
	int* Left = new int[n + 1];
	int* Right = new int[m + 1];

	for (i = 0; i < n; i++)
		Left[i] = a[p + i];
	for (j = 0; j < m; j++)
		Right[j] = a[q + j + 1];
	Left[i] = Right[j] = INT_MAX;

	i = j = 0;
	for (int k = p; k <= r; k++)
	{
		if (Left[i] < Right[j])
		{
			a[k] = Left[i++];
		}
		else
		{
			a[k] = Right[j++];
		}
	}

	delete Left;
	delete Right;
}


int main()
{
    return 0;
}


// QuickSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void display(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int partition(int a[],int p,int r)
{
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] < a[r])
		{
			swap(a[++i], a[j]);
		}
	}
	swap(a[++i], a[r]);

	if (i == (r - 1))
	{
		return (p + r) / 2;
	}
	else
	{
		return i;
	}
}

void quick_sort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = partition(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
}

int main()
{
	int a[100];
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		quick_sort(a, 0, n - 1);
		display(a, n);
	}
	return 0;
	return 0;
}


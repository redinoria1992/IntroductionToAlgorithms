// CountingSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>  
using namespace std;

void display(int a[], int n);
int max(int a[], int n);
void counting_sort(int a[], int b[], int n, int k);

int main()
{
	int a[100];
	int b[100];
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int k = max(a, n);
		counting_sort(a, b, n, k);
		display(b, n);
	}
	return 0;
}

void display(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int max(int a[], int n)
{
	int m = a[0];
	for (int i = 1; i < n; i++)
	{
		if (m < a[i])
			m = a[i];
	}
	return m;
}

/*这里数组a和b的下标都是从0开始的*/
void counting_sort(int a[], int b[], int n, int k)
{
	int* c = new int[k + 1];
	for (int i = 0; i <= k; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		c[a[i]]++;
	for (int i = 1; i <= k; i++)
		c[i] = c[i] + c[i - 1];
	for (int i = n - 1; i >= 0; i--) //反过来遍历会失去计数排序的稳定性  
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}
	delete[] c;
}

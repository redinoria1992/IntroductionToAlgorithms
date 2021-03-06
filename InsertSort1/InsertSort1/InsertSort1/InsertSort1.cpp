// Insertsort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
using namespace std;

void display(int a[], int n);
void insert_sort(int a[], int n);

int main()
{
	int a[100];
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		insert_sort(a, n);
		display(a, n);
	}
	return 0;
}

void insert_sort(int a[], int n)
{
	int key;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		int j = i - 1;
		while ((j > -1) && (key < a[j]))  //查找前N-1个元素  
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		display(a, n);  //用于输出每次遍历后数组的情况，以便观察  
	}
}

void display(int a[], int n)  //输出当前数组所有元素  
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
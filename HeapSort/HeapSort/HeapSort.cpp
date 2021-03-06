// HeapSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream> 

using namespace std;

int heap_size;

inline int LEFT(int i)
{
	return 2 * i + 1;
}

inline int RIGHT(int i)
{
	return 2 * (i + 1);
}

void display(int a[], int n);
void swap(int& n, int& m);
void max_heapify(int a[], int i);
void bulid_max_heap(int a[], int n);
void heap_sort(int a[], int n);

int main()
{
	int a[100];
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		heap_sort(a, n);
		display(a, n);
	}
	return 0;
}

void display(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void swap(int& n, int& m)
{
	int temp;
	temp = n;
	n = m;
	m = temp;
}

void max_heapify(int a[], int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;

	if ((l < heap_size) && a[l] > a[i])
		largest = l;
	else
		largest = i;

	if ((r < heap_size) && a[r] > a[largest])
		largest = r;

	if (largest != i)
	{
		swap(a[largest], a[i]);
		max_heapify(a, largest);
	}
}

void build_max_heap(int a[], int n)
{
	heap_size = n;
	for (int i = (n - 1) / 2; i >= 0; i--)
		max_heapify(a, i);
}

void heap_sort(int a[], int n)
{
	build_max_heap(a, n);
	for (int i = n - 1; i >= 1; i--)
	{
		swap(a[i], a[0]);
		heap_size--;
		max_heapify(a, 0);
	}
}


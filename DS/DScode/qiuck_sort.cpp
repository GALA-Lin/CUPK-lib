#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void quick_sort(int a[], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int x = a[low], i = low, j = high;
	while (i < j)
	{
		while (a[i] > x)
		{
			i++; // low
		}
		while (a[j] < x)
		{
			j--; // high
		}
		if (i < j)
		{
			std::swap(a[i], a[j]);
		}
	}
	quick_sort(a, low, i);
	quick_sort(a, i + 1, high);
}


int main()
{
	int i, n;
	int a[101];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	quick_sort(a, 0, n - 1);
	cout << endl;
	for (i = n - 1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

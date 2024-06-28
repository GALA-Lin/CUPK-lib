#include <stdio.h>
#include <stdlib.h>

int n;

/*
 * 冒泡排序
 */
void BubbleSort(int *array)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int i;
	int *array;
	scanf("%d", &n);
	array = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	BubbleSort(array);

	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
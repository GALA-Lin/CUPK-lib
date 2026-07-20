#include <stdio.h>
#include <stdlib.h>

int n;

/*
 * 选择排序
 */
void SelectSort(int *array){
	int i, j, k, temp;
	for (i = 0; i < n; i++){
		k = i;
		for (j = i + 1; j < n; j++){
			if (array[j] < array[k]){
				k = j;
			}
		}
		if (k != i){
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
		}
	}
}

int main(){
	int i;
	int *array;

	scanf("%d", &n);
	array = (int*) malloc(sizeof(int) * n);

	for (i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
	SelectSort(array);

	for (i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
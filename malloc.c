/*#include<stdio.h>
#include<stdlib.h>
int main() {
	int *arr, size;
	printf("Enter the no of elements you want to enter: ");
	scanf("%d", &size);
	
	arr = (int*) malloc(size * sizeof(int));
	if(arr == NULL){
		printf("Memory allocation failed.!");
		return 1;
	}

	printf("Enter %d elements:\n", size);
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	printf("Entered elements are:\n");
	for(int i = 0; i < size; i++)
		printf("%d, ", arr[i]);

	return 0;
}*/

#include <stdio.h>

enum { SIZE = 5 };

int main() {
    int arr[SIZE] = {10, 20, 30, 40, 50};

    for (int i = 0; i < SIZE; i++)
        printf("%d .", arr[i]);

    return 0;
}
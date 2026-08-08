#include<stdio.h>
#include<stdlib.h>
int main() {
	int *arr, size, *temp, newSize;

	printf("Enter the no of elements you want to enter: ");
	scanf("%d", &size);

	arr = (int*) malloc(size * sizeof(int));
	if(arr == NULL){
		printf("Memory allocation failed.!");
		return 1;
	}
	
	printf("Enter %d numbers:\n", size);
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}

	printf("Entered numbers are:\n");
	for(int i = 0; i < size; i++){
		printf("%d, ", arr[i]);
	}

	printf("Enter the new size: ");
	scanf("%d", &newSize);
	
	temp = (int*) realloc(arr, newSize * sizeof(int));
	
	if(temp == NULL){
		printf("Memory allocation failed.!");
		return 1;
	}
	
	arr = temp;
	printf("Enter %d numbers:\n", newSize);
	for(int i = 0; i < newSize; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Entered numbers are:\n");
	for(int i = 0; i < newSize; i++){
		printf("%d, ", arr[i]);
	}

	return 0;
	
}
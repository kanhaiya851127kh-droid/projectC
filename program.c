#include<stdio.h>

void display (int arr[], int n) { 
    int i;
    for (i = 0; i < n; i++)  // that a loop to display the array elements
        printf("%d", arr[i]); // output the array elements

    }

int  main (){  // integar type main function
    int a[5] = {1,2,3,4,5};
    display(a,5);
    return 0;     
}
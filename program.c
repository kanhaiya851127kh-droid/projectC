#include<stdio.h>

void display (int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) 
        printf("%d", arr[i]);

    }

int  main (){
    int a[5] = {1,2,3,4,5};
    display(a,5);
    return 0;     // that over  that program
}
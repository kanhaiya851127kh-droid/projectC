
#include<stdio.h>
int main(){
    int num ,queb ;
    printf("enter a first num ");
    queb = num *num*num ;

    printf("the queb of %d is : ", num,queb);

    return 0;
}


#include<stdio.h>
int main(){
    int num ,queb ;
    printf("enter a first num ");
    queb = num *num*num ;

    printf("the queb of %d is : ", num,queb);

    return 0;
}
#include<stdio.h>
int main(){
    int num ,queb ;
    printf("enter a first num ");
    queb = num *num*num ;

    printf("the queb of %d is : ", num,queb);

    return 0;
}
#include<stdio.h>
int main(){
    int num ,queb ;
    printf("enter a first num ");
    queb = num *num*num ;

    printf("the queb of %d is : ", num,queb);

    return 0;


    #include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0, max = 0;

    // Find longest consecutive even numbers
    for(i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            count++;
            if(count > max)
                max = count;
        } else {
            count = 0;
        }
    }

    printf("%d", max);

    return 0;
}
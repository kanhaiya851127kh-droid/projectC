#include<stdio.h>
int main () {

    int num ,reverse = 0 ,R ;
    printf("enter a num =") ;
    scanf("%d",&num);

    while(num != 0){
        R = num % 10 ;
        reverse = reverse * 10 + R ;
        num = num /10 ;
    }
    printf("reverse number =%d",reverse);
    return 0 ;
}
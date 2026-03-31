#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 5; i++) {  
        int j = 5;

        while (j >= 1) {   
            printf("%d ", j);
            j--;
        }

        printf("\n");
    }

    return 0;
}
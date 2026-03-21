#include <stdio.h>

int main() {
    int choice;
    float num, result = 0;

    while(1) {
        printf("\n--- Calculator Menu ---\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 5) {
            printf("Calculator Closed");
            break;
        }

        printf("Enter number: ");
        scanf("%f", &num);

        switch(choice) {
            case 1:
                result += num;
                break;

            case 2:
                result -= num;
                break;

            case 3:
                if(result == 0)
                    result = 1;
                result *= num;
                break;

            case 4:
                if(num != 0)
                    result /= num;
                else
                    printf("Cannot divide by zero\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

        printf("Current Result = %.2f\n", result);
    }

    return 0;
}
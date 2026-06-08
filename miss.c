#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int value;
    bool care;
    char loyalty[20];
} heart;

heart* trust() {
    static heart h;
    return &h;
}

void commit(heart *you) {
    printf("Committed successfully ❤️\n");
}

heart* returnfromyou() {
    return NULL;   // she returned NULL 😢
}

int main() {

    heart *you = trust();

    you->value = 100;
    you->care = true;

    commit(you);

    heart *result = returnfromyou();

    if (result == NULL) {
        printf("She returned NULL.\n");
        printf("Heart Break 💔\n");
        return 0;
    }

    printf("Love accepted ❤️\n");
    return 0;
}
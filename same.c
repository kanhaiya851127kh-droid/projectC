#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int value;
    bool care;
    int loyalty;
} heart;

heart* trust() {
    static heart h;
    return &h;
}

void commit(heart* h) {
    printf("Committed with value: %d\n", h->value);
}

heart* returnFromYou() {
    return NULL; // simulate rejection 💔
}

int main() {

    heart* you = trust();
    you->value = 100;
    you->care = true;
    you->loyalty = 9999;

    commit(you);

    heart* result = returnFromYou();

    if(result == NULL) {
        printf("She returned NULL.\n");
        printf("Heart broken 💔\n");
        return 0;
    }

    return 0;
}
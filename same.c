#include<heart.h>
int main () {

    heart*you = trust();
    you->value = 100;
    you->care = true;
    you->loyalty = infinte;//trest ishu in life for you.

    commit(you);

    heart* result = returnformyou();//you will return to me or not..
    if(result == NULL) {
        printf("she returned NULL .\n");
        heart.break();
        return  0;
    }
    return 0;
}
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char *my_env[] = {"FOOD=кофе", NULL};
    if (execle("./3.1zad", "./3.1zad", "пончики", NULL, my_env) == -1) {
        fprintf(stderr, "Не могу создать заказ: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}

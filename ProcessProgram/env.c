#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char **ptr;
    extern char **environ;

    // 모든 환경 변수를 출력
    for (ptr = environ; *ptr != 0; ptr++)
        printf("%s \n", *ptr);

    exit(0);
}
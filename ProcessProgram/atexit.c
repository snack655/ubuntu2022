#include <stdio.h>
#include <stdlib.h>

static void doA(void), doB(void);

int main(void) {
    if (atexit(doA) != 0)
        perror("doA 등록할 수 없습니다.");

    if (atexit(doB) != 0) 
        perror("doB 등록할 수 없습니다.");

    printf("main 끝 \n");
    exit(0);
}

static void doA(void) {
    printf("doA가 호출되었습니다.\n");
}

static void doB(void) {
    printf("doB가 호출되었습니다.\n");
}

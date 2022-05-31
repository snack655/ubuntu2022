#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        printf("1번째 자식 프로세스 시작\n");
        sleep(1);
        execl("/bin/echo", "echo", "hihi", NULL);
        printf("1번째 자식 프로세스 끝");
        exit(1);
    }

    if (fork() == 0) {
        printf("2번째 자식 프로세스 시작\n");
        sleep(2);
        execl("/bin/date", "date", NULL);
        printf("2번째 자식 프로세스 끝");
        exit(1);
    }

    if (fork() == 0) {
        printf("2번째 자식 프로세스 시작\n");
        sleep(3);
        execl("/bin/ls", "ls", "-al", NULL);
        printf("3번째 자식 프로세스 끝");
        exit(1);
    }
}
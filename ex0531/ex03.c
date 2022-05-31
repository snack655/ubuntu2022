#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid, status, child;

    pid = fork();
    printf("처음 프로세스 pid = %d\n", getpid());
    if (pid == 0) {
        // 자식 프로세스
        printf("자식 프로세스 pid = %d\n", getpid());
        exit(1);
    }

    child = wait(&status);
    printf("부모프로세스 pid = %d child = %d \n", getpid(), child);
}
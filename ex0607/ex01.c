#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid, status;

    pid = fork();

    // fork retvalue = 0
    // chlid process
    if (pid == 0) {
        printf(" child process pid = %d\n", getpid());
        exel("/bin/ls", "ls", "-al", NULL);
        sleep(1);
        exit(0);
    } else {
        int child = waitpid(pid, &status, 0);
        printf(" child = %d\n", child);
        printf(" parent process pid = %d\n", getpid());
        exit(0);
    }
}
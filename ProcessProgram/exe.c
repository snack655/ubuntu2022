#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int command;
    while (1) {
        printf("ls(1) / echo(2) / ps(3) / date(4)\n");
        printf("[-1] 입력 시 프로그램 종료\n");
        printf("무슨 명령어를 실행하시겠습니까?\n");
        scanf("%d", &command);

        int pid, status;
        if (command == -1) {
            break;
        } else if (command == 1) {

            pid = fork();
            if (pid == 0) {
                execl("/bin/ls", "ls", "-al", NULL);
            } else {
                waitpid(pid, &status, 0);
                printf("\n\n");
            }
        } else if (command == 2) {

            pid = fork();
            if (pid == 0) {
                char message[1024];
                printf("출력하실 메시지를 입력해주세요. : ");
                scanf("%s", message);
                execl("/bin/echo", "echo", message, NULL);
            } else {
                waitpid(pid, &status, 0);
                printf("\n\n");
            }
        
        
        } else if (command == 3) {

            pid = fork();
            if (pid == 0) {
                execl("/bin/ps", "ps", NULL);
            } else {
                waitpid(pid, &status, 0);
                printf("\n\n");
            }

        } else if (command == 4) {

            pid = fork();
            if (pid == 0) {
                execl("/bin/date", "date", NULL);
            } else {
                waitpid(pid, &status, 0);
                printf("\n\n");
            }
        } else {
            printf("해당하는 명령어가 없습니다.\n\n");
        }
    }
}
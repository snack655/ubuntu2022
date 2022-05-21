#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFF_SIZE 1024

int main() {
    int fd;

    char fileName[100];
    char filePerm[20];
    char buff[BUFF_SIZE];
    char buff2[BUFF_SIZE];

    printf("파일명을 입력하세요 : ");
    scanf("%s", fileName);

    printf("파일권한을 입력하세요 : ");
    scanf("%s", filePerm);

    int perm = strtol(filePerm, (char **)NULL, 8);

    fd = open(fileName, O_CREAT | O_RDWR, perm);
    if (fd == -1) {
        fprintf(stderr, "file create error: %s\n", strerror(errno));
        exit(2);
    }

    printf("성공적으로 만들어졌습니다.\n");

    printf("파일 내용을 입력해주세요! : ");
    getchar();
    scanf("%[^\n]", buff);

    lseek(fd, BUFF_SIZE, SEEK_SET);
    write(fd, buff, BUFF_SIZE);

    printf("내용이 입력되었습니다. : \n -> ");
    lseek(fd, BUFF_SIZE, SEEK_SET);
    read(fd, buff2, BUFF_SIZE);
    printf("%s", buff2);

    close(fd);
    exit(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char fileName[100];
    int filePerm;

    printf("파일명을 입력하세요 : ");
    scanf("%s", fileName);

    printf("파일권한을 입력하세요 : ");
    scanf("%d", &filePerm);
    
    if ((fd = open(fileName, O_WRONLY | O_CREAT | O_EXCL, filePerm)) == -1) {
        perror(fileName);
        printf("같은 파일명이 있어 만들기 실패헀습니다.");
        exit(2);
    }

    printf("성공적으로 만들어졌습니다.");
    close(fd);
    exit(0);
}
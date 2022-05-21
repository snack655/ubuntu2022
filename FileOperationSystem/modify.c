#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    int fd;
    char fileName[512];
    char buff[BUFF_SIZE];
    char modifyContents[BUFF_SIZE];
    char ans;

    // 실행법이 틀렸다는 것을 알려주는 기능
    if (argc < 2) {
        fprintf(stderr, "사용법 : %s FileName\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        fprintf(stderr, "file open error: %s\n", strerror(errno));
        exit(1);
    }

    printf("현재 파일 내용 : \n-> ");
    lseek(fd, BUFF_SIZE, SEEK_SET);
    read(fd, buff, BUFF_SIZE);
    printf("%s\n", buff);

    printf("기존의 내용을 수정하겠습니까? (y/n) : ");
    scanf("%c", &ans);
    if(ans == 'y' || ans == 'Y') {
        lseek(fd, BUFF_SIZE, SEEK_SET);
    } else {
        fd = open(argv[1], O_RDWR | O_APPEND);
        lseek(fd, BUFF_SIZE, SEEK_SET);
        printf("이어쓰기를 시작합니다.\n");
    }

    printf("수정하실 내용을 입력해주세요 : ");
    getchar();
    scanf("%[^\n]", modifyContents);
    
    write(fd, modifyContents, strlen(modifyContents));

    lseek(fd, BUFF_SIZE, SEEK_SET);
    read(fd, buff, BUFF_SIZE);
    printf("내용을 수정하였습니다\n-> %s", buff);
}


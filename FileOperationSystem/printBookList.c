#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "book.h"

int main(int argc, char **argv) {

    FILE *fd;
    int c;
    char buf[1024];
    struct book book;

    // 실행법이 틀렸다는 것을 알려주는 기능
    if (argc < 2) {
        fprintf(stderr, "사용법 : %s FileName\n", argv[0]);
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == NULL) {
        printf("파일 열기에 실패했습니다..\n");
        exit(1);
    }

    printf("** 책 리스트 **\n\n");
    fprintf(fd);
    fclose(fd);
    return 0;
}


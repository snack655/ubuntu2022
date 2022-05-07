#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#pragma warning(disable :4996)
#include "book.h"

#define MAX_LEN 1024


int main(int argc, char **argv) {

    int fd;
    int c;
    struct book book;

    // 실행법이 틀렸다는 것을 알려주는 기능
    if (argc < 2) {
        fprintf(stderr, "사용법 : %s FileName\n", argv[0]);
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("파일 열기에 실패했습니다..\n");
        exit(1);
    }

    printf("\n********************* 책 리스트 *********************\n\n");

    lseek(fd, sizeof(book), SEEK_SET);
    while(read(fd, &book, sizeof(book)) > 0) {
        if (book.cost == 0) 
            continue;
        printf("번호 : %d, 가격 : %d, 이름 : %s, 조회수 : %d\n", book.idx, book.cost, book.name, book.viewCount);
    }

    printf("\n********************************************************\n\n");
    return 0;
}


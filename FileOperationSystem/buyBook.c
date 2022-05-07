#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "book.h"

int main(int argc, char **argv) {

    int fd;
    char c;
    struct book book;

    if (argc < 2) {
        fprintf(stderr, "사용법 : %s FileName\n", argv[0]);
        exit(1);
    }
    fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        printf("파일 열기에 실패했습니다..\n");
        exit(1);
    }

    do {
        printf("구매하실 책의 번호를 입력해주세요 : ");
        scanf("%d", &book.idx);
        if(book.idx != 0) {
            lseek(fd, book.idx * sizeof(book), SEEK_SET);
            read(fd, &book, sizeof(book));

            printf("번호 : %d, 가격 : %d, 이름 : %s, 조회수 : %d\n", book.idx, book.cost, book.name, book.viewCount);
            printf("책을 구매합니다!!\n\n");

            book.cost = 0;
            book.viewCount = 0;
            book.idx = 0;
            lseek(fd, -(sizeof(book)), SEEK_CUR);
            write(fd, &book, sizeof(book));

        }
        printf("더 구매하시겠습니까? (Y, N) : ");
        scanf("%c\n", &c);
        printf("c = %c", c);
    } while (c == 'Y' || c == 'y');
}


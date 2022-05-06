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

    do {
        printf("\n 찾으실 책의 번호를 입력해주세요 : ");
        scanf("%d", &book.idx);
        lseek(fd, book.idx * sizeof(book), SEEK_SET);
        if (read(fd, &book, sizeof(book)) > 0 && book.idx != 0) {
            printf("번호 %d 가격 %d 이름 %s 조회수 %d\n", book.idx, book.cost, book.name, book.viewCount);
        } else {
            printf("그런 책이 존재하지 않습니다..ㅠㅠ\n");
        }
        printf("계속 하시겠습니까?(Y/N) : ");
        getchar();
        scanf("%c", &c);
    } while (c == 'Y' || c == 'y');
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "book.h"

// 책을 사서 저장한다.
int main(int argc, char **argv) {
    int fd;
    char go;
    struct book book;

    // 실행법이 틀렸다는 것을 알려주는 기능
    if (argc < 2) {
        fprintf(stderr, "사용법 : %s file\n", argv[0]);
        exit(1);
    }
    
    // 파일을 열고 / 실패했다면 오류를 핸들링
    if ((fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640)) == -1) {
        perror(argv[1]);
        printf("파일을 삭제하시고 다시 생성하시겠습니까? (y/n)");
        scanf("%c", &go);
        if (go == 'y') {
            if (remove(argv[1]) == 0) {
                fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0640);
                printf("성공\n");
            } else {
                printf("실패\n");
                exit(2);
            }
        } else {
            exit(2);
        }
    }

    // 입력 받은 후 파일에 값 입력
    printf("\n 번호, 가격 0 입력 시 종료\n");
    while (1) {
        printf("%-7s %-7s %-7s %-5s\n", "번호", "가격", "책", "조회수");
        scanf("%d %d %s %d", &book.idx, &book.cost, book.name, &book.viewCount);
        if(book.idx == 0 && book.cost == 0) {
            break;
        } else if (book.idx == 0 || book.cost == 0) {
            printf("다시 입력해주세요!\n");
            continue;
        }
        lseek(fd, book.idx * sizeof(book), SEEK_SET);
        write(fd, &book, sizeof(book));
    }
    close(fd);
    exit(0);
}
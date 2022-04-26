#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct {
    char name[24];
    int id;
    int score;
} STUDENT;

// 버퍼 비우기 예제
// void stdempty() {
//     while(getchar() == '\r')
// }

int main() {
    int fd;
    fd = open("studentdb", O_RDWR);

    if (fd == -1) {
        printf("file open fail");
    }

    char c;
    STUDENT student;
    // STUDENT *student1 = &student;

    do {
        printf("검색하실 학번을 입력하세요 : ");
        scanf("%d", &student.id);
        if(student.id != 0) {
            lseek(fd, sizeof(student), SEEK_SET);
            read(fd, &student, sizeof(student));

            printf("학번 = %d, 이름 = %s, 점수 = %d\n", student.id, student.name, student.score);

            printf("수정하실 점수 입력 : ");
            scanf("%d", &student.score);
            if (student.score != 0) {
                lseek(fd, -(sizeof(student)), SEEK_CUR);
                write(fd, &student, sizeof(student));
            }
        }
        getchar();
        printf("계속하시겠습니까? (Y, N) : ");
        scanf("%c\n", &c);
        printf("c = %c", c);
    } while (c == 'Y' || c == 'n');
    close(fd);
    return 0;
}
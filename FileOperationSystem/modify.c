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
    char buf[BUFF_SIZE] = {0, };

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

    int nread = read(fd, buf, BUFF_SIZE);
    printf("%s\n", buf);

}


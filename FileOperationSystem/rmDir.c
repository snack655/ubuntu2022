#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main() {
    DIR *dp;
    struct dirent *d;
    int i = 1;
    char rmDirName[512];

    printf("삭제할 디렉토리 경로를 입력해주세요 : ");
    scanf("%s", rmDirName);

    if (remove(rmDirName) == 0) {
        printf("디렉토리를 삭제하였습니다.");
    } else {
        fprintf(stderr, "directory remove error: %s\n", strerror(errno));
    }
    return 0;
}
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    DIR *dp;
    struct dirent *d;

    char directoryname[512];
    printf("확인할 디렉토리 경로를 입력해주세요 : ");
    scanf("%s", directoryname);

    dp = opendir(directoryname);
    if (dp == NULL) {
        perror("디렉토리가 없습니다.");
        exit(0);
    }
    while ( (d = readdir(dp)) != NULL) {
        printf("%s\n", d -> d_name);
    } 
}
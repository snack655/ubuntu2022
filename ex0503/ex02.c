#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    /*
        읽고 싶은 폴더명 입력하세요
        ls linuxClass
    */

    // 디렉토리 엔트리
    DIR *dp;
    // 디렉토리, 파일 담는 곳
    struct dirent *d;

    char directoryname[512];
    if (argc == 1) {
        strcpy(directoryname, ".");
    } else {
        strcpy(directoryname, argv[1]);
    }
    printf("directoryname = %s\n", directoryname);

    dp = opendir(directoryname);
    if (dp == NULL) {
        perror("dp is null");
        exit(0);
    }
    while ( (d = readdir(dp)) != NULL) {
        printf("d -> d_name %s\n", d -> d_name);
    } 

    return 0;
}
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc) {
    DIR *dp;
    struct dirent *d;
    int i = 1;

    char directoryname[512];
    strcpy(directoryname, "/Users/choiminjae/공부/linuxClass/FileOperationSystem");
    printf("이곳의 명령어를 사용합니다 : %s\n", directoryname);

    dp = opendir(directoryname);
    if (dp == NULL) {
        perror("명령어가 없습니다.");
        exit(0);
    }
    while ( (d = readdir(dp)) != NULL) {
        if((d->d_name)[0] != '.') 
            printf("%d 명령어 : %s\n", i++, d -> d_name);
    } 
    return 0;
}
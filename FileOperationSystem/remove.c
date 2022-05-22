#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    DIR *dp;
    struct dirent *d;
    int i = 1;
    char rmFileName[100];
    char currentCwd[512];
    char directoryname[512];
    printf("%s\n에서 삭제할 파일을 선택해주세요!\n", getcwd(currentCwd, 512));
    strcpy(directoryname, currentCwd);

    dp = opendir(directoryname);
    if (dp == NULL) {
        perror("디텍토리가 없습니다.");
        exit(0);
    }
    while ( (d = readdir(dp)) != NULL) {
        if((d->d_name)[0] != '.') 
            printf("%d : %s\n", i++, d -> d_name);
    } 
    i = 1;

    printf("삭제할 파일은 : ");
    scanf("%s", rmFileName);

    if (remove(rmFileName) == 0) {
        printf("파일을 삭제하였습니다.\n");
        dp = opendir(directoryname);
        while ( (d = readdir(dp)) != NULL) {
        if((d->d_name)[0] != '.') 
            printf("%d : %s\n", i++, d -> d_name);
    }
    } else {
        printf("파일을 삭제하지 못했습니다.");
    }

    closedir(dp);
    return 0;
}
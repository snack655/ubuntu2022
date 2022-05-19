#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    DIR *dp;
    struct dirent *d;
    int i = 1;
    char rmFileName[100];

    char directoryname[512];
    strcpy(directoryname, "/Users/choiminjae/공부/linuxClass/FileOperationSystem");
    printf("이 폴더에서 삭제할 파일을 선택해주세요 : %s\n", directoryname);

    dp = opendir(directoryname);
    if (dp == NULL) {
        perror("디텍토리가 없습니다.");
        exit(0);
    }
    while ( (d = readdir(dp)) != NULL) {
        if((d->d_name)[0] != '.') 
            printf("%d : %s\n", i++, d -> d_name);
    } 

    printf("삭제할 파일은 : ");
    scanf("%s", rmFileName);

    if (remove(rmFileName) == 0) {
        printf("파일을 삭제하였습니다.");
    } else {
        printf("파일을 삭제하지 못했습니다.");
    }
    return 0;
    
    
}
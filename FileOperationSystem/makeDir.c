#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    DIR *dir_info;
    struct dirent *dir_entry;
    char ans;
    char dirName[512];
    char currentCwd[512];

    printf("현재의 폴더에 폴더를 생성하시겠습니까? (y/n) : ");
    scanf("%c", &ans);

    
    if (ans == 'y' || ans == 'Y') {
        printf("생성할 폴더의 명을 입력해주세요 : ");
        scanf("%s", dirName);

        if (mkdir(dirName, 0755) == 0) {
            printf("%s\n에 폴더를 생성하였습니다.", getcwd(currentCwd, 512));
        } else {
           fprintf(stderr, "directory create error: %s\n", strerror(errno));
        }
        return 0;
    } else {
        printf("생성할 폴더의 경로를 입력해주세요 : ");
        scanf("%s", dirName);

        if (mkdir(dirName, 0755) == 0) {
             printf("폴더 생성에 성공하였습니다.");
        } else {
            fprintf(stderr, "directory create error : %s\n", strerror(errno));
        }
        return 0;
    }
}
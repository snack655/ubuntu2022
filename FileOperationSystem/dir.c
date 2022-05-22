#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define PERM_SIZE 10

void printTime(struct stat *buf) { 
        struct tm *mtime; 
        mtime=localtime(&buf->st_mtime); 
        printf("%04d-%02d-%02d %02d:%02d      ", 
                mtime->tm_year+1900, mtime->tm_mon+1, 
                mtime->tm_mday, mtime->tm_hour, 
                mtime->tm_min); 
} 

char * getperm (char *perm_c, struct stat * buf) {
    char *ref = "xwr";
    int i;

    memset (perm_c, '-', PERM_SIZE);
        
    if((buf -> st_mode & S_IFMT) == S_IFDIR)
        perm_c[0] = 'd';

    for (i = 0; i < 9; i++) {
        if (buf -> st_mode & (1 << i))
            perm_c[PERM_SIZE - i - 1] = ref[i % 3];
    }

    return perm_c;
}

int main() {

        char cwd[1024];
        char perm_c[PERM_SIZE + 1] = {0};        

        DIR *dp;
        struct dirent *d;
        struct stat buf;

        printf("확인하실 파일의 경로를 입력해주세요 : ");
        scanf("%s", cwd);

        if((dp = opendir(cwd)) == NULL) {
            fprintf(stderr, "directory open error: %s\n", strerror(errno));
            exit(1);
        }

        printf("권한    파일크기    시간    파일명\n");
        while( (d = readdir(dp)) != NULL) {
            lstat(d -> d_name, &buf);

            printf("%s    ", getperm(perm_c, &buf));
            printf("%lld      ", buf.st_size);
            printTime(&buf);
            printf("%s      \n", d -> d_name);
        }

        closedir(dp);
        return 0;
}
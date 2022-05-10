#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

struct aa {
    char[512] name;
};

char type(mode_t mode) {
    if (S_ISREG(mode))
        return '-';
    if (S_ISDIR(mode))
        return 'd';
}

char *perm(mode_t mode) {
    static char mystring[10] = "---------";
    printf("mode")

    strcpy(mystring, "---------");
    
    if (mode & 4) {
        mystring[6] = 'r';
    }
    if (mode & 2) {
        mystring[7] = 'w';
    }
    if (mode & 1) {
        mystring[8] = 'x';
    }

    return mystring;
}

void printstat(char *pathname, char *file, struct stat *st) {
    // printf("pathname = %s ", pathname);
    printf("%c%s", type(st->st_mode), perm(st->st_mode));
    printf(" %ld\t", st->st_blocks);
    printf(" %3d", st->st_nlink);
    printf(" %s %s", (getpwuid(st->st_uid))->pw_name, (getgrgid(st->st_gid))->gr_name);
    printf(" %9ld", st->st_size);
    printf(" %12s", ctime(st->st_ctime));
    printf(" %s\n", file);
}

void setaa(struct aa *pa) {
    printf("pa = %d", pa);
    strcpy(pa -> name, "안녕하세요 이름입니다.");
}
void printaa(struct aa *pa) {
    printf("pa -> name = %s", pa->name);
}

int main(int argc, char **argv) {

    struct aa maina;
    printf("&maina %d\n", &maina);
    setaa(&maina);
    printaa(&maina);

    DIR *dp;

     // 디렉토리, 파ㄹ 담는 곳
    struct dirent *d;
    char path[BUFSIZE];
    struct stat st;

    printf("BUFSIZE = %d\n", BUFSIZE);

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

    while((d = readdir(dp)) != NULL) {
        sprintf(path, "%s/%s\n", directoryname, d->d_name);
        if(lstat(path, &st) < 0)
            perror(path);
        printstat(path, d->d_name, &st);

        // printf("%5d", st.st_blocks);

        // printf("%s\n", d->d_name);
        // printf("path = %s", path);
    }
}
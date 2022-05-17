#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    if(argc != 2) {
        perror("삭제하실 디렉토리명 입력하세요");
        return -1;
    } 
    if(rmdir(argv[1]) == -1) {
        perror("삭제 실패");
        return 0;
    }
}
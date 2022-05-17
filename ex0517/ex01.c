/*
    디렉토리 만들기
    mkdir()
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/*
    ./ex01 argc -> 1
    ./ex02 aa argc -> 2
*/
int main(int argc, char **argv) {
    char di_name[20];
    //char *di_name2 = "aaa"; // 고정된 값이기 때문에 변경하려고 할 시 오류가 남
    if ( argc != 2 ) 
        strcpy(di_name, "temp");
    else
        strcpy(di_name, argv[1]);

    printf("di_name = %s", di_name);

    if ( mkdir(di_name, 0777) == -1) {
        perror("만들기 실패");
        return 1;
    }

 
    return 0;
}
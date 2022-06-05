#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char answer;
    char *ptr;
    char **ptrs;
    char keyward[100];
    extern char **environ;

    printf("모든 환경 변수를 출력하시겠습니까? : ");
    scanf("%c", &answer);
    if(answer == 'y' || answer == 'Y') {
        // 모든 환경 변수를 출력
        for (ptrs = environ; *ptrs != 0; ptrs++)
            printf("%s \n", *ptrs);

        exit(0);
    }

    printf("특정 환경 변수를 출력합니다.\n출력하실 환경변수를 입력해주세요 : ");
    scanf("%s", keyward);
    ptr = getenv(keyward);
    if(ptr == NULL) {
        printf("%s라는 환경변수가 없습니다.", keyward);
        exit(0);
    }
    printf("%s = %s", keyward, ptr);
    exit(0);
}
#include <stdio.h>
#include <string.h>
#define MAXLINE 100

// 문자열을 입력 받아 긴 문자열 일 때 출력하는 프로그래밍
void copy(char from[], char to[]);
char line[MAXLINE];
char regstr[MAXLINE];

int main() {
	int	max = 0;

	while (1) {
		gets(line);
		if(line == "kt") {
			break;
		}

		printf("line = %s\n", line);
		int size = strlen(line);
		printf("size = %d\n", size);

		if(max < size) {
			max = size;
			copy(regstr, line);
		}
		printf("size=%d\n", regstr);
	}
	// 정상 종료 일 때는 0을 리턴한다.
	return 0;
}

// u 뒤로 가기 ctrl+r 앞으로 가기
// ctrl + z ps 프로세스
// fg 앞으로 다시
// bg

/* copy: from을 to에 복사; to가 충분히 크지 않다고 가정 */
void copy(char from[], char to[]) {
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}

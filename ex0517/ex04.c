#include <unistd.h>
#include <stdio.h>

int main() {
    if (symlink("al", "alink") < 0) {
        perror("에러");
    }
}
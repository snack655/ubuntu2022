#include <stdio.h>
#include <stdlib.h>

int main() {
    int ret = system("ps a");
    printf("%d", ret);
    return 0;
}
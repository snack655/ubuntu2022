#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int perm = strtol(argv[1], (char**)NULL, 8);
    chmod(argv[2], perm);
}
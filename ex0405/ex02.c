#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// shirft + v drag = auto indent
int main() {
	int fd = open("myfile", O_RDWR|O_CREAT|O_EXCL, 0600);
	if(fd == -1)
		perror("error open file");
	pclose(fd);
	return 0;
}

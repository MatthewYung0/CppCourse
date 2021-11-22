#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

const char *FifoName  = "test_fifo";

int main(void)
{
    char s[200],u[200];
    int ret, fd;

    mknod(FifoName, S_IFIFO | 0644, 0);

    printf("waiting for consumer...\n");
    fd = open(FifoName, O_WRONLY);
    printf("got one\n");

    do {	
        printf("Tell the other one something:\n");
	fgets(u,  200, stdin);
        u[strlen(u)] = '\0';
        if ((ret = write(fd, u, strlen(u) + 1)) == -1)
            perror("write!");
    } while (ret > 0);

    return 0;
}

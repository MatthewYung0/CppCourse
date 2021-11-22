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
    char s[200];
    int ret, fd;

    mknod(FifoName, S_IFIFO | 0644, 0);

    printf("waiting for producer...\n");
    fd = open(FifoName, O_RDONLY);
    printf("got one\n");

    do {
        if ((ret = read(fd, s, 200)) == -1)
            perror("read");
        else {
            s[ret] = '\0';
            printf("tick: read %d bytes: \"%s\"\n", ret, s);
        }
    } while (ret > 0);

    return 0;
}
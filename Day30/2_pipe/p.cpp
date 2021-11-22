#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>

int main() {
    int pipeFileDescriptos[2];
    char buffer[30];

    pipe(pipeFileDescriptos);

    if (!fork()) {
        printf(" CHILD: writing to the pipe\n");
        for (size_t i = 0; i < 5; i++) {
      //      read(pipeFileDescriptos[0], buffer, 5);            
            write(pipeFileDescriptos[1], "child", 5);            
//            read(pipeFileDescriptos[0], buffer, 5);
       //     printf("CHILD: read \"%s\"\n", buffer);
        }
        
        printf(" CHILD: exiting\n");
        exit(0);
    } else {
        printf("PARENT: reading from pipe\n");
           for (size_t i = 0; i < 5; i++) {
		sleep(1);
//            write(pipeFileDescriptos[1], "test", 5);
            read(pipeFileDescriptos[0], buffer, 5);
            printf("PARENT: read \"%s\"\n", buffer);
        }
        printf("PARENT: read \"%s\"\n", buffer);
        wait(NULL);
    }

    return 0;
}

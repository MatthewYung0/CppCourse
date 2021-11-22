#include <iostream>
#include <sstream>
#include <unistd.h>
#include <thread>
#include <sys/wait.h>
std::stringstream DATA;


void iWantToExecuteThisInTheChild() {
    uint8_t i = 0;
    while(++i<3) {
        std::cout << "-------------------------------" << std::endl;
        std::cout << ">>> pid = " << getpid() << std::endl;
        DATA << (getpid()) << std::endl;
        std::cout << DATA.str() << std::endl;
        std::cout << "-------------------------------" << std::endl << std::endl;
        sleep(1); 
    }
}

int main () {

    std::cout << "My process id = " << getpid() << std::endl;
    signal(SIGCHLD, SIG_IGN); 

    pid_t pid;
    pid = fork();   
    if (pid);
    else {
      // for (size_t i=0 ; i < 2 ; i++) {                                     
       //    pid = fork();   

        /* if ( pid ) {
                break;      
            }*/
            std::cout << "Child #" << getpid() << std::endl;
	    exit(0);
       // }
//        iWantToExecuteThisInTheChild();
    }


 //   wait(NULLi);        
 	if (pid)  sleep (800);
    return 0;

}

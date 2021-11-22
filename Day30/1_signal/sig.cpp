// https://www.geeksforgeeks.org/signals-c-set-2/
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <iostream>  
// function declaration 
void sighup(int); 
void sigint(int); 
void sigquit(int); 
  
// driver code 
int main() 
{ 
    int pid; 
  
    /* get child process */
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { /* child */
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; /* loop for ever */
    } 
  
    else /* parent */
    { /* pid hold id of child */
	    sleep(3);
        printf("\nPARENT: sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 
  
// sighup() function definition 
void sighup(int) 
  
{ 
    std::cout << "CHILD: I have received a SIGHUP\n"; 
    signal(SIGHUP, sighup); /* reset signal */
} 
  
// sigint() function definition 
void sigint(int) 
  
{ 
    signal(SIGINT, sigint); /* reset signal */
    printf("CHILD: I have received a SIGINT\n"); 
} 
  
// sigquit() function definition 
void sigquit(int) 
{ 
    printf("My DADDY has Killed me!!!\n"); 
    exit(0); 
} 

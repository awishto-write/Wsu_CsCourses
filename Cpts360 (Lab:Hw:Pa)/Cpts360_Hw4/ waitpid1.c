// waitpid1.c

#include "csapp.h"
#define N 2

int main() 
{
    int status, i;
    pid_t pid;
    int* pointer = NULL;

    /* Parent creates N children */
    for (i = 0; i < N; i++) {                     
		if((pid = Fork()) == 0)  {/* Child */     
            *pointer = 1;
	      //  exit(100+i);  
            exit(0);        
       }                     
    }
    /* Parent reaps N children in no particular order */
    while ((pid = waitpid(-1, &status, 0)) > 0) { 
     // if (WIFEXITED(status))   
        if(WIFSIGNALED(status)) {
            int signal = WTERMSIG(status);  
            if(signal == SIGSEGV) {
                // printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status));    
                printf("child %d terminated by signal %d : Segmentation fault\n", pid, signal);    
            }  

            else
                printf("child %d terminated abnormally by signal %d\n", pid, signal);           
        }
    }

    /* The only normal termination is if there are no more children */
    if (errno != ECHILD)                          
	unix_error("waitpid error");

    exit(0);
}
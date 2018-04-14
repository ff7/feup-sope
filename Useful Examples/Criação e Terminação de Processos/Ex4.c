//======================================================================
// f04.c / JAS
// Basic synchronization. Father waits for the son to end.
//----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
    pid_t pid, pidSon;
    int status;
    pid=fork();
    if (pid > 0) {
    pidSon = wait(&status);
    printf("I'm the parent (PID=%d)\n\n",getpid());
    printf("My son %d exited with exit code %d\n",pidSon, WEXITSTATUS(status));}
    else
    {
    printf("I'm the son (PID=%d)\n\n",getpid());
    exit( getpid() % 10 );
    }
    printf ("PID=%d exiting ...\n",getpid());
    return 0;
}  

// O wait faz com que o pai espere que o filho termine e so deposi faca o 
// que tinha a fazer
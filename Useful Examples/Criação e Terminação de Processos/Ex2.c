//======================================================================
// f02.c / JAS
// Father & son. Which one runs first, after fork() ?
// Run several times and interpret results
//----------------------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
    int pid;
    printf("before fork...\n"); // remove '\n' and see what happens
    pid=fork();
    if (pid > 0)
    printf("I'm the parent (PID=%d)\n\n",getpid());
    else
    printf("I'm the son (PID=%d)\n\n",getpid());
    printf ("PID=%d exiting ...\n",getpid());
    return 0;
} 

// O pai (pid > 0) é quem corre primeiro depois do fork
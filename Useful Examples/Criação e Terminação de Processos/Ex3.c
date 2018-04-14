//======================================================================
// f03.c / JAS
// Fork & output buffering
// Equal to f02.c print("before fork ...") replaced by write(...)
//----------------------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
    int pid;
    write(STDOUT_FILENO,"before fork...",14); // printf() replaced by write()
    pid=fork();
    if (pid > 0)
    printf("I'm the parent (PID=%d)\n\n",getpid());
    else
    printf("I'm the son (PID=%d)\n\n",getpid());
    printf ("PID=%d exiting ...\n",getpid());
    return 0;
} 

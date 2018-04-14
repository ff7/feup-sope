#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid, pidSon;
    int status;
    
    if (argc != 2) {
        printf("usage: %s dirname\n",argv[0]);
         exit(1);
    }
    pid=fork();
    if (pid > 0)
    {
        pidSon = wait(&status);
        printf("I'm the parent (PID=%d)\n\n", getpid());
        printf("My son %d exited with exit code %d\n", pidSon,WEXITSTATUS(status));
    }
    else if (pid == 0){
        execlp("ls", "ls", "-laR", argv[1], NULL);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
} 
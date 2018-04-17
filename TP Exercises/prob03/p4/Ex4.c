#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
int main(void)
{
    int status;
    pid_t pid, pidSon;
    printf("before fork...\n"); 
    pid = fork();
    if (pid > 0){
        pidSon = wait(&status);
        printf(" World \n");
    }
    else
        printf("Hello ");
    return 0;
} 
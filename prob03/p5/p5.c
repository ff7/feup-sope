#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
 pid_t pid;
int status;
 pid=fork();
 if (pid > 0) { //pai
 printf("Hello ");
 }
 else
 { // filho
 pid = fork();
 if (pid == 0) // filho do filho
 {
     printf("my");
 }
 else 
 {
    wait(&status);
    printf(" friends! \n");
 }
 return 0;
 }
}
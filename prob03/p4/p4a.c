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
 if (pid > 0) {
 wait(&status);
 printf(" world!\n");
 }
 else
 {
 printf("Hello");
 }
 return 0;
 }
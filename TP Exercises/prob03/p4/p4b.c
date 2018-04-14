#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
 pid_t pid;
 pid=fork();
 if (pid > 0) {
 printf("Hello ");
 }
 else
 {
 printf("world!\n");
 }
 return 0;
 }
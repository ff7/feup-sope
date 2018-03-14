#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1 

int main(void)
{
    int fd[2]; // 2 por causa do read e do write
    pid_t pid;
    pipe(fd);

    pid = fork();

    if (pid > 0) // Pai
    {
        char a[2][10]; // 2 porque sao 2 numeros
        printf("Please insert two values: \n A: ");
        scanf("%s", &a[0]);
        printf("\n B: ");
        scanf("%s", &a[1]);
        close(fd[READ]);
        write(fd[WRITE],a,2*sizeof(char[10]));
        close(fd[WRITE]); 
        printf("\n\n");

    }

    else if (pid == 0) // Filho
    {
        char b[2][10];
        close(fd[WRITE]); // Nao e usado
        read(fd[READ],b,20*sizeof(char)); 
        int a[2];
        a[0] = atoi(b[0]);
        a[1] = atoi(b[1]);
        close (fd[READ]);
        printf("The sum of your values is: %i\n", a[0]+a[1]);
        printf("The difference of your values is: %i\n", a[0]-a[1]);
        printf("The multipication of your values is: %i\n", a[0]*a[1]);
        printf("The division of your values is: %f\n", (float)a[0]/(float)a[1]);
    }

    return 0;
}
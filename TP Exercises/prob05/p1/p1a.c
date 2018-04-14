#include <stdio.h>
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
        int a[2]; // 2 porque sao 2 numeros
        printf("Please insert two values: \n A: ");
        scanf("%d", &a[0]);
        printf("\n B: ");
        scanf("%d", &a[1]);
        close(fd[READ]);
        write(fd[WRITE],a,2*sizeof(int));
        close(fd[WRITE]); 
        printf("\n\n");

    }

    else if (pid == 0) // Filho
    {
        int a[2];
        close(fd[WRITE]); // Nao e usado
        read(fd[READ],a,2*sizeof(int)); 
        close (fd[READ]);
        printf("The sum of your values is: %i\n", a[0]+a[1]);
        printf("The difference of your values is: %i\n", a[0]-a[1]);
        printf("The multipication of your values is: %i\n", a[0]*a[1]);
        printf("The division of your values is: %f\n", (float)a[0]/(float)a[1]);
    }

    return 0;
}
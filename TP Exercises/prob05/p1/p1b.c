#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1 

struct Data{
    int n1;
    int n2;
}; 

int main(void)
{
    int fd[2]; // 2 por causa do read e do write
    pid_t pid;
    pipe(fd);
    
    pid = fork();

    if (pid > 0) // Pai
    {
        struct Data data;

        printf("Please insert two values: \n A: ");
        scanf("%d", &data.n1);
        printf("\n B: ");
        scanf("%d", &data.n2);
        close(fd[READ]);
        write(fd[WRITE],&data,sizeof(data));
        close(fd[WRITE]); 
        printf("\n\n");

    }

    else if (pid == 0) // Filho
    {
        struct Data data;

        close(fd[WRITE]); // Nao e usado
        read(fd[READ],&data,sizeof(data)); 
        close (fd[READ]);
        printf("The sum of your values is: %i\n", data.n1+data.n2);
        printf("The difference of your values is: %i\n", data.n1-data.n2);
        printf("The multipication of your values is: %i\n", data.n1*data.n2);
        printf("The division of your values is: %f\n", (float)data.n1/(float)data.n2);
    }

    return 0;
}
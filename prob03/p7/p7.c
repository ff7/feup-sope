#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]) 
{
    char prog[20];
    sprintf(prog,"%s.c",argv[1]);
    execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL);
     printf("Command not successful! ");
     exit(1);
} 

// Se os servicos tiverem sucesso o codigo que os chamou nao retorna
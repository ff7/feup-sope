//======================================================================
// e01.c / JAS
// execl() & execlp()
//----------------------------------------------------------------------

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
    int pid;
    pid=fork();
    if (pid > 0) {
    wait(NULL); //father does not care w/exit status of the son ...
    printf("I'm the parent (PID=%d)\n\n",getpid()); }
    else {
    printf("I'm the son (PID=%d)\n\n",getpid());
    execl("ls","ls","-la",NULL); //try with execlp()
    printf(".... \n"); //which message makes sense, here ?
    }
    printf ("PID=%d exiting ...\n",getpid());
    return 0;
} 

// Os servicos exec() nao criam um novo processo mas substituem a imagem em
// memoria do processo que os invocz por uma imagem proveniente de um ficheiro
// executavel
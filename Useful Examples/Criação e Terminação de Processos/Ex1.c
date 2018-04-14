//======================================================================
// f01.c / JAS
// Fork return value is different for 'parent' and 'child'
// Who is the 'parent' of the 'parent' ? Execute 'ps' command to see ...
//----------------------------------------------------------------------


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
    int fork_return_value;
    printf("before fork...\n");
    fork_return_value=fork();
    printf("I'm process %d: 'fork_return_value'=%d. My parent is %d.\n\n",getpid(),fork_return_value,getppid());
    return 0;
} 


// Notas:
//     pid_t: Retorna 0 para o filho
//            Retorna > 0 para o pai

//     getpid: Obtém o próprio PID 
//     getppid: Obtém o pid do pai

// O pai do pai é o processo que o criou, caso o processo que o tenha originado 
// já não exista então é atribuido um novo pai, que é o mesmo para estes casos

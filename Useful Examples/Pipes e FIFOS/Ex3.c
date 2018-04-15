#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
int main(void)
{
    int fd, messagelen, i;
    char message[100];
    do
    {
    fd=open("myfifo",O_WRONLY);
    if (fd==-1) sleep(1);
    }
    while (fd==-1);
    for (i=1; i<=3; i++)
    {
    sprintf(message,"Hello no. %d from process no. %d\n", i, getpid());
    messagelen=strlen(message)+1;
    write(fd,message,messagelen);
    sleep(3);
    }
    close(fd);
    return 0;
} 

// O Fifo faz o mesmo que o pipe mas atua em canais de comunicacao entre
// processo nao relacionados
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main(int argc, char * argv[])
{
    char erro[] = "Wrong number of arguments! \n";
    char erro2[] = "Couldnt open the file\n";

    if (argc != 2 && argc != 3)
    {
        write(STDOUT_FILENO,erro, sizeof(erro));
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(STDOUT_FILENO, erro2, sizeof(erro2));
    }

    int fd2;
    if (argc == 3)
    {
        fd2 = open(argv[2], O_WRONLY | O_TRUNC);
        dup2(fd2, STDOUT_FILENO);
    }

    char buffer[BUFFER_SIZE];
    int nCharsRead;

   
    
    while ((nCharsRead = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
     write(STDOUT_FILENO, buffer, nCharsRead);
    }
    close(fd);

    if (argc == 3)
    {
        close(fd2);
    }
    return 0;
}

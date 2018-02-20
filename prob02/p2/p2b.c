// Copia o conteudo de um ficheiro para outro recorrendo a chamadas diretas ao SO

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 512

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Wrong number of arguments \n");
        return 1;
    }

    int f1_fd = open(argv[1], O_RDONLY);
    if (f1_fd == -1)
    {
        printf("Couldnt open this file: %s\n", argv[1]); 
        return 2;
    }


    int f2_fd = open(argv[2], O_WRONLY | O_EXCL, 0644);
    if (f2_fd == -1)
    {
        printf("Couldnt open this file: %s\n", argv[2]); 
        close(f2_fd);
        return 2;
    }

    // Copying from f1 to f2

    char buffer[BUFFER_SIZE];
    int nCharsRead;

   while ( (nCharsRead = read(f1_fd, buffer , BUFFER_SIZE)) > 0)
    {
		write(f2_fd,buffer , nCharsRead);
	}

    close(f1_fd);
    close(f2_fd);

    return 0;
}
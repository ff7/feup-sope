#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define NAMES_LENGTH 100
#define GRADES_LENGTH 10

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    char buffer[512];

    char qtsNomes[] = "How many names do you want to write? \n";
    char nome[] = "\n Name? ";
    char grade[] = "\n Grade? ";

    write(STDOUT_FILENO, qtsNomes, sizeof(qtsNomes));
    read(STDIN_FILENO, buffer, 512);
    int buffer_size = atoi(buffer);

    char buffer_names[buffer_size][NAMES_LENGTH];
    char buffer_grades[buffer_size][GRADES_LENGTH];

    int nCharsRead;
    
    for (unsigned int i = 0; i < buffer_size; i++)
    {
        write(STDOUT_FILENO, nome, sizeof(nome));
        nCharsRead = read(STDIN_FILENO, buffer_names[i], NAMES_LENGTH);
        write(STDOUT_FILENO, grade, sizeof(grade));
        nCharsRead = read(STDIN_FILENO, buffer_grades[i], GRADES_LENGTH);
    }

    int fd = open(argv[1], O_WRONLY | O_EXCL, 0644);
    for (unsigned int i = 0; i < buffer_size; i++)
    {
        write(fd , buffer_names[i] , strlen(buffer_names[i])-1);
		write(fd , "  -  " , strlen("  -  "));
		write(fd , buffer_grades[i] , strlen(buffer_grades[i])-1);
		write(fd , "\n" , strlen("\n"));
    }

    close(fd);
    return 0;

}
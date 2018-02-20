// Copia o conteudo de um ficheiro para outro recorrendo a funcoes de C

#include <stdio.h>

#define BUFFER_SIZE 512

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Wrong number of arguments \n");
        return 1;
    }

    FILE * f1 = fopen(argv[1], "r");
    if (f1 == NULL)
    {
        printf("Couldnt open this file: %s\n", argv[1]);
        return 2;
    }

    FILE * f2 = fopen(argv[2], "w");
    if (f2 == NULL)
    {
        printf("Couldnt open this file: %s\n", argv[2]); 
        fclose(f1);
        return 2;
    }

    // Copying from f1 to f2

    char buffer[BUFFER_SIZE];
    int nCharsRead;

   while ( (nCharsRead = fread(buffer , sizeof(char) , BUFFER_SIZE , f1)) > 0)
   {
		fwrite(buffer , sizeof(char) , nCharsRead , f2);
	}

    fclose(f1);
    fclose(f2);

    return 0;
}
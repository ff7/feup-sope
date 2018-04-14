#include <stdio.h>

#define MAX_LENGTH_NAME 50

int main(int argc, char * argv[])

{
	// Dar print a uma string que obteve atraves do scanf

	char name[MAX_LENGTH_NAME];
	printf("Name?\n");
	scanf("%s", name);
	printf("Hello ");
	printf("%s", name);
	printf("\n");


	// Dar print a uma string que tinha como argumento

	if (argc == 1)
		printf("Only one argument!");
	else
	{
		printf("Hello ");

		/*Comeca em i = 1, pq no indice 0 esta o nome do programa, sendo que o primeiro argumento
		 * que vai receber esta em i = 1
		*/

		for(unsigned int i = 1; i < argc; i++)
		{
			printf("%s",argv[i]);
			printf(" ");
		}
		printf("\n");
	}

	return 0;
}


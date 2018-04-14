#include <stdio.h>

// Programa que escreva no ecra o valor das variaveis de ambiente

int main(int argc, char * argv[], char * envp[])
{
	while (*envp != NULL)
	{
		printf("%s \n", *envp);
		envp++;
	}
	return 0;
}



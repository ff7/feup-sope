#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int n = (int) atoi(argv[argc - 1]);

	if (argc != 3)
		printf("Wrong number of arguments");
	else
	{
		for(int i = 0; i < n; i++)
		{
			printf("Hello ");
			printf("%s", argv[argc - 2]); //Tb dava para fazer argv[1] pois e o indice da string
			printf("\n");
		}
	}
	return 0;
}

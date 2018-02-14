#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[], char * envp[])
{
	while(*envp != NULL) {
			if(strncmp(*envp, "USER=", strlen("USER=")) == 0) {
				printf("Hello %s!\n", *envp + 5);
			}
			envp++;
	}
	return 0;
}





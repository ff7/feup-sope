#include <stdio.h>
#include <stdlib.h>

void exitHandler1()
{
    printf("Executing exit handler 1\n");
}

void exitHandler2()
{
    printf("Executing exit handler 2\n");
}

int main()
{
    if (atexit(exitHandler1) != 0)
    {
        printf("Error registering handler 1 \n");
    }
    else if (atexit(exitHandler2) != 0)
    {
        printf("Error registering handler 2 \n"); 
    }  
    printf("Main done \n");
    exit(0);
}
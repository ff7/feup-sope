// SISTEMAS OPERATIVOS
// PIPES - Exemplos das aulas teóricas
// JAS (adaptado de Stevens)
// Coprocesso para fazer contas de somar (!)
// pipe03b.c (a executar em conjunto com pipe03a.c)
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 100

int main(void)
{
    int n, int1, int2;
    char line[MAXLINE];
    while ( (n = read(STDIN_FILENO, line, MAXLINE)) > 0)
    {
    line[n] = 0; // null terminate
    if (sscanf(line, "%d%d", &int1, &int2) == 2)
    {
    sprintf(line, "%d\n", int1 + int2);
    n = strlen(line);
    if (write(STDOUT_FILENO, line, n) != n)
    {
    fprintf(stderr,"write error"); exit(1);
    }
    }
    else
    {
    if (write(STDOUT_FILENO, "invalid args\n", 13) != 13)
    {
    fprintf(stderr,"write error"); exit(1);
    }
    }
    }
    exit(0);
} 
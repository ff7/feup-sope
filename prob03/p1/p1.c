#include <stdio.h>
#include <unistd.h>

int global=1;
int main(void) {
 int local = 2;
 if(fork() > 0) { //Pai
 printf("PID = %d; PPID = %d\n", getpid(), getppid());
 global++;
 local--;
 } else { //Filho
 printf("PID = %d; PPID = %d\n", getpid(), getppid());
 global--;
 local++;
 }
 printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);
 return 0;
} 

// Nos testes que efetuei o pai correu sempre antes do filho
// As alteracoes ao correr varias vezes encontraram-se no valor do PID
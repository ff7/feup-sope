#include <stdio.h>
#include <unistd.h>


int main(void) {
 //write(STDOUT_FILENO,"1",1);
 printf("1");
 if(fork() > 0) { //Pai
 //write(STDOUT_FILENO,"2",1);
 //write(STDOUT_FILENO,"3",1);
 printf("2");
 printf("3");
 } else { //Filho
 //write(STDOUT_FILENO,"4",1);
 //write(STDOUT_FILENO,"5",1);
 printf("4");
 printf("5");
 }
 //write(STDOUT_FILENO,"\n",1);
 printf("\n");
 return 0;
} 

// Se fizermos o write aparece esta sequencia: 123 45
// Se fizermos printf sem o \n aparece: 12345
// Se fizermos printf com o \n aparece: 123 145
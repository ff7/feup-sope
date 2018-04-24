#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 10000

void * thrfunc(void * arg)
{
    int i;
    fprintf(stderr, "Starting thread %s\n", (char *) arg);
    for (i = 1; i <= NUMITER; i++) write(STDERR,arg,1);
    return NULL;
}
int main()
{
    pthread_t ta, tb;
    char foo = 'a';
    pthread_create(&ta, NULL, thrfunc, &foo);
    foo = 'b';
    pthread_create(&tb, NULL, thrfunc, &foo);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
 return 0;
} 

// The problem of using the same variable for both threads is that
// the two of them use the value of the argument after its uodate which means
// that in this case they both print 'b'
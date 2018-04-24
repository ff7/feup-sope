#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 50000

int n = 50000;
int t1Count = 0;
int t2Count = 0;

void * thrfunc(void * arg)
{
    fprintf(stderr, "Starting thread %s\n", (char *) arg);
    while (n > 0){
        write(STDERR,arg,1);
        n--;
        printf("Teste: %d\n", *(int *) arg);

        if ( arg == "1")
            t1Count++;
        else if ( arg == "2")
            t2Count++;
    }
    return NULL;
}
int main()
{
    pthread_t ta, tb;
    pthread_create(&ta, NULL, thrfunc, "1");
    pthread_create(&tb, NULL, thrfunc, "2");
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    printf("Thread no 1 count: %d\n", t1Count);
    printf("Thread no 2 count: %d\n", t2Count);
    printf("Estimated Count: %d\n", t1Count + t2Count);

 return 0;
}

// The amount of character written is never the specified in n
// but an aproximation
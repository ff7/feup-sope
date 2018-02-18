#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    clock_t start, end;
    struct tms t;
    long ticks;

	start = times(&t);
  	ticks = sysconf(_SC_CLK_TCK);

	if (argc != 3)
	{
		printf("Wrong number of arguments \n");
	}

	int max = atoi(argv[1]);
	int term = atoi(argv[2]);

	srand(time(NULL));
	int r = 0;

	while(r != term)
	{
		r = rand() % max + 1;
		printf("Random number: %i\n", r);
	}

	end = times(&t);

	printf("Clock: %4.2f s\n", (double)(end-start)/ticks);
	printf("User time: %4.2f s\n", (double)t.tms_utime/ticks);
	printf("System time: %4.2f s\n", (double)t.tms_stime/ticks);
	printf("Children user time: %4.2f s\n", (double)t.tms_cutime/ticks);
	printf("Children system time: %4.2f s\n", (double)t.tms_cstime/ticks);

	return 0;
}
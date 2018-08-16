// finds the primes between 2 and 2^n -- the basic program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS 4


int Max_num, Bound;
int *primes;
int total = 0;

pthread_t t[10];
pthread_mutex_t mutex;

int compr( const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int is_prime( int p ){

	int i, to = sqrt(p);

	if ((p & 1)==0)
		return 0;
	for(i = 3; i <= to; i+=2)  {
		if ((p % i)==0)
			return 0;
	}
	return 1;
}

void * work (void *arg)
{
	usleep(100000); // You can't remove this line !! (part of HW)
	int my_start;
	int i;
    int input = *((int*) arg);

	my_start = (Max_num / THREADS) * input;

	int my_end = my_start + (Max_num / THREADS) - 1;

	if (my_start < 3)
		my_start = 3;
	if ((my_start % 2) == 0)
		my_start++;
	for (i = my_start; i < my_end; i += 2){
        if (is_prime (i)) {
            pthread_mutex_lock(&mutex);
			primes[total] = i;
            total++;
			pthread_mutex_unlock(&mutex);
		}
	}
    printf("\n");
	return NULL;
}

int main (int argn, char **argv)
{
	int digit, i, j, id = 0;

	if (argv[1]==0)
		digit = 10;
	else
		digit = atoi (argv[1]);
	Max_num = 1<<digit;

	primes = (int *) malloc((Max_num/2)*sizeof(int));

	primes[0] = 2;
    total++;

	pthread_mutex_init(&mutex, NULL);

	for (i = 0; i < THREADS; i++)  {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
		pthread_create(&t[i], NULL , work , (void*) arg );
    }
	
	for (i = 0; i < THREADS; i++)  {
		pthread_join(t[i], NULL );
	}

	printf ("Number of prime numbers between 2 and %d: %d\n", Max_num, total);

    qsort( primes, total, sizeof(int), compr);
	for (i = 0; i < total; i++)  {
		printf ("%d ", primes[i]);
	}

	printf("\n");

	return 0;
}

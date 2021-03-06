#include <stdio.h>
#include <stdlib.h>
unsigned int fibonacci(int n);

unsigned int* Fib;

int main(int argc, char *argv[] )
{
	int i,N;
    if ( argc < 2 )
        exit(0);
    
	N = atoi(argv[1]);

	Fib = (unsigned int *)malloc(N * sizeof(int));
	fibonacci(N);

	printf("The sequence of Fibonacci up to %d:\n", (N+1));
	for (i=0; i<=N; i++) 
		printf("%d, ", fibonacci(i));
	printf("\n");
	free(Fib);
	return 0;
}

unsigned int fibonacci( int n )
{
	if (Fib[n] != 0)
		return Fib[n];
	if ( n <= 1)
		return (Fib[n]=1);
	else
		return (Fib[n]=fibonacci(n-1) + fibonacci(n-2));
}

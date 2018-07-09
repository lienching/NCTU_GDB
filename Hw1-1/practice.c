#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define OFFSET 48

void func1(){
    printf("This is function 1.\n");
}
void func2(){
    printf("This is function 2.\n");
}
void func3(){
    printf("This is function 3.\n");    
}
void func4(){
    printf("This is function 4.\n");    
}
void func5(){
    printf("This is function 5.\n");    
}
void func6(){
    printf("This is function 6.\n");    
}
void func7(){
    printf("This is function 7.\n");    
}
void func8(){
    printf("This is function 8.\n");    
}

int number()
{
    int n;
	int q, q_t;
	int s, s_t;
	int r = rand()%1000;

	q_t = (r/5)%8;
	q = q_t + OFFSET + 1;
	s_t = r%10;
	s = s_t + OFFSET;
	return  ((s_t==0) && (q_t==0))?atoi((char*)&s): atoi((char*)&q);
    
}


void main()
{
    void (*func[8])(void) = {func1, func2, func3, func4, func5, func6, func7, func8};
    void *ptr;
    unsigned int i;
	int iter = 100;

    srand(time(NULL));
    
    while(iter > 0){
	    i = number();
        func[i - 1]();
		iter--;
	}
}

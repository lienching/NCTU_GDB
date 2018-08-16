CC=gcc
CFLAG=-g
SRC=fibonacci.c
TARGET=exe
DEBUGFLAG=-DDEBUG


ELF: out
	$(CC) -o $(TARGET) *.o 

out: fibonacci.c
	$(CC) -c $^ -o fibonacci.o

clean:
	rm exe

CC=gcc
CFLAG=-g
SRC=prime.c
TARGET=exe
DEBUGFLAG=-DDEBUG
LIB=-lpthread -lm

ELF: out
	$(CC) -o $(TARGET) *.o $(LIB)

out: prime.c
	$(CC) -c $^ -o prime.o

clean:
	rm exe

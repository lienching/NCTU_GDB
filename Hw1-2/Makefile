CC=gcc
CFLAGS=-g
DEBUGFLAG= -DDEBUG
SRC=insert_sort.c
TARGET=exe

ELF: out
	$(CC) -o $(TARGET) *.o

out: insert_sort.c
	$(CC) -c $^ -o practice.o

clean:
	rm exe

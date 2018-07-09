.PHONY: clean
CC = gcc
CFLAG = -g
DEBUGFLAG = -DDEBUG
SRC = practice.c
TARGET = exe
LIB = -lpthread


ELF: out
	$(CC) -o exe *.o

out: practice.c
	@$(CC) -c $^ -o practice.o

clean:
	rm exe

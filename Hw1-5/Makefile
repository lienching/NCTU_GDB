CC=gcc
CFLAG=-g
SRC=main.c
TARGET=exe
DEBUGFLAG=-DDEBUG
LIB=-Imylib/
STATIC_LIB=-Lmylib -lmylib

ELF: out
	$(CC) -o $(TARGET) *.o $(STATIC_LIB) 

out: main.c
	cd mylib && make && cd ..
	$(CC) -c $^ -o main.o $(LIB) 



CC=gcc
CFLAG=-g
LDFLAG= -shared
TARGET_LIB= libmylib.a
TARGET=lab1.c lab2.c

ELF: build_lib 
	ar rcs libmylib.a lab1.o lab2.o

build_lib:
	$(CC) -c -o lab1.o lab1.c
	$(CC) -c -o lab2.o lab2.c

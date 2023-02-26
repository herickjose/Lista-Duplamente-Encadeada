CC=gcc

CFLAGS=-c -g -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow 

all : main 

main : listaOrdenada.o listaDuplamente.o no.o main.o
	$(CC) listaOrdenada.o listaDuplamente.o no.o main.o -o main

main.o : main.c
	$(CC) $(CFLAGS) main.c

no.o : no.c no.h
	$(CC) $(CFLAGS) no.c

listaDuplamente.o : no.o listaDuplamente.c listaDuplamente.h
	$(CC) $(CFLAGS) listaDuplamente.c

listaOrdenada.o : no.o listaDuplamente.o listaOrdenada.c listaOrdenada.h
	$(CC) $(CFLAGS) listaOrdenada.c

clean : 
	rm *.o main	

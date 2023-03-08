.PHONY: all #Nathan Nguyen

all: client1.out

INCLUDE = .


client1.out: client1.c stack.h set.h set.o stack.o
				gcc -o client1.out client1.c stack.o set.o -std=c11


set.o: set.c set.h
				gcc -I$(INCLUDE) -c set.c -std=c11


stack.o: stack.c stack.h set.h
				gcc -I$(INCLUDE) -c stack.c -std=c11

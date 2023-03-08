.PHONY: all #Nathan Nguyen

all: testlib

MYLIB = libmathCU.a

# Where are include files kept
INCLUDE = .



testlib: test1.c $(MYLIB) mth3.h
        gcc -fPIC -o test.out test1.c $(MYLIB) -std=c11


$(MYLIB): cfact.o primes.o
				ar crv $@ $^   
                      # $(MYLIB) here is a target:, $@ refers to target
                      # $^ refers to ALL dependencies after the colon

cfact.o: cfact.c
        gcc -I$(INCLUDE) -c cfact.c

primes.o: primes.c
        gcc -I$(INCLUDE) -c primes.c

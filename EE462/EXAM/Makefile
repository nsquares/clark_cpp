.PHONY: clean veryclean uninstall dist all #FH

all: myapp

# Which compiler
CC = gcc

# Where to install
# note: admin/superuser permission might be needed; change path to local dir if needed
INSTDIR = /usr/local/bin
MANDIR = /usr/share/man/man1
#MANDIR = /usr/local/man/man1

# Where are include files kept
INCLUDE = .

# Options for development
CFLAGS = -g -Wall -ansi

# Options for release
# CFLAGS = -O -Wall -ansi

# Local Libraries
MYLIB = mylib.a

myapp: main.o $(MYLIB)
	$(CC) -o myapp main.o $(MYLIB)
	@echo done

$(MYLIB): 2.o 3.o
	ar rv $@ $^

#FH: the style below causes repeated (unnecessary) building of $(MYLIB)
#$(MYLIB): $(MYLIB)(2.o) $(MYLIB)(3.o)
# $(MYLIB): $(MYLIB)(2.o 3.o)



## succinct style
# main.o: main.c a.h
# 2.o: 2.c a.h b.h
# 3.o: 3.c b.h c.h

main.o: main.c a.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.c

2.o: 2.c a.h b.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 2.c

3.o: 3.c b.h c.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 3.c


clean:
	-rm -f main.o 2.o 3.o $(MYLIB) *~

veryclean: clean #FH
	-rm -fr myapp myapp-1* myapp*gz

uninstall: #FH
	-rm -fr $(INSTDIR)/myapp $(MANDIR)/myapp.1.gz
	@echo "deleted myapp (if it was there)"

install: myapp myapp.1
	@if [ -d $(INSTDIR) ]; \
	then \
		cp myapp $(INSTDIR) &&\
		chmod a+x $(INSTDIR)/myapp &&\
		chmod og-w $(INSTDIR)/myapp &&\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi
	@if [ -d $(MANDIR) ]; \
	then \
		echo "preparing to install manpage for myapp .." &&\
		cp myapp.1 $(MANDIR) &&\
		gzip -f "$(MANDIR)/myapp.1" &&\
		echo "Installed in $(MANDIR)";\
	else \
		echo "Sorry, $(MANDIR) does not exist";\
	fi


#FH
dist: myapp-1.0.tar.gz
	tstamp.sh $<

myapp-1.0.tar.gz: myapp myapp.1 myapp.spec
	-rm -rf myapp-1.0
	mkdir myapp-1.0
	cp *.c *.h *.1 Makefile myapp-1.0
	tar zcvf $@ myapp-1.0

myapp.rpm: myapp-1.0.tar.gz
	cp $< /usr/src/packages/SOURCES
	rpm -ba myapp.spec


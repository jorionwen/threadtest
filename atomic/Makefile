all:example14

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

example14:example14.o
	$(CC) $(LDFLAGS) -o $@ $^

example14.o:example14.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm example14.o example14

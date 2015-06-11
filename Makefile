CC=gcc
LD=gcc
CFLAGS=-Iincludes/ -g -Wall
LDFLAGS=

OBJS=teste1.o

.PHONY: dirs clean

all: $(OBJS)

# Source Files

build/slist.o: dirs lib/slist/slist.c includes/slist.h
	$(CC) $(CFLAGS) -c lib/slist/slist.c -o build/slist.o

#Tests

build/test1.o: dirs tests/slist/test1.c includes/slist.h
	$(CC) $(CFLAGS) -c tests/slist/test1.c -o build/test1.o

test1: dirs build/test1.o build/slist.o
	$(LD) $(LDFLAGS) build/test1.o build/slist.o -o build/test1

runtest1: dirs test1
	valgrind build/test1
	strace build/test1

#Helpers

dirs: build

build:
	mkdir -pv build/

clean:
	rm -rfv build/

OBJS = btree.o btree_test.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: solution

solution : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

btree.o : btree.h btree.cpp
	$(CC) $(CFLAGS) btree.cpp

btree_test.o : btree.h btree_test.cpp
	$(CC) $(CFLAGS) btree_test.cpp

.PHONY: clean
clean:
	rm -f *.o

.PHONY: clean_all
clean_all:
	rm -f *.o solution

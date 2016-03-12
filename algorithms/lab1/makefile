OBJS = sort.o sort_test.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: solution

solution : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

sort.o : sort.h sort.cpp
	$(CC) $(CFLAGS) sort.cpp

sort_test.o : sort.h sort_test.cpp
	$(CC) $(CFLAGS) sort_test.cpp

.PHONY: clean
clean:
	rm -f *.o

.PHONY: clean_all
clean_all:
	rm -f *.o solution

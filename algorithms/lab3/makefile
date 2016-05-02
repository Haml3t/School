OBJS = huffman.o huffman_test.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: solution

solution : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

huffman.o : huffman.h huffman.cpp
	$(CC) $(CFLAGS) huffman.cpp

huffman_test.o : huffman_test.cpp
	$(CC) $(CFLAGS) huffman_test.cpp

.PHONY: clean
clean:
	rm -f *.o

.PHONY: clean_all
clean_all:
	rm -f *.o solution

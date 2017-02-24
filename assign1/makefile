# makefile for assignment 0
TARGET = sqsort
OBJS = *.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -g
CC = gcc

$(TARGET) : $(TARGET).o sll.o dll.o queue.o stack.o integer.o real.o string.o scanner.o comparator.o
	$(CC)  $(LOPTS)  $(OBJS) -o $(TARGET)

$(TARGET).o : $(TARGET).c 
	$(CC) $(OPTS) -c $(TARGET).c

sll.o : sll.c sll.h
	$(CC) $(OPTS) -c sll.c

real.o : real.c real.h
	$(CC) $(OPTS) -c real.c

string.o : string.c string.h
	$(CC) $(OPTS) -c string.c

integer.o : integer.c integer.h
	$(CC) $(OPTS) -c integer.c

dll.o : dll.c dll.h
	$(CC) $(OPTS) -c dll.c

stack.o : stack.c stack.h
	$(CC) $(OPTS) -c stack.c

queue.o : queue.c queue.h
	$(CC) $(OPTS) -c queue.c

scanner.o : scanner.c scanner.h
	$(CC) $(OPTS) -c scanner.c

comparator.o : comparator.c comparator.h
	$(CC) $(OPTS) -c comparator.c

clean :
	rm -f $(OBJS) $(TARGET)

test :
	echo running sqsort on integer ex 1 from assigment instructions
	./sqsort -d t-int1.txt
	echo running sqsort on integer ex 2 from ass instructions
	./sqsort -d t-int2.txt
	echo running sqsort on random integers some reapeats
	./sqsort -d t-int3.txt
	echo running sqsort on all but one integer the same
	./sqsort -d t-int4.txt
	echo running sqsort on mostly the same integers
	./sqsort -d t-int5.txt
	echo running sqsort on real ex
	./sqsort -r t-real1.txt
	echo running sqsort on real all similar
	./sqsort -r t-real2.txt
	echo running sqsort on real all but 1 similar
	./sqsort -r t-real3.txt
	echo running sqsort on string ex
	./sqsort -s t-str1.txt
	echo running sqsort on string similar
	./sqsort -s t-str2.txt
	echo running sqsort on string all but 1 similar
	./sqsort -s t-str3.txt

# makefile for assignment 0
TARGET = bstrees
OBJS = *.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -g
CC = gcc

$(TARGET) : $(TARGET).o sll.o queue.o integer.o real.o scanner.o comparator.o
	$(CC)  $(LOPTS)  $(OBJS) -o $(TARGET)

$(TARGET).o : $(TARGET).c 
	$(CC) $(OPTS) -c $(TARGET).c

sll.o : sll.c sll.h
	$(CC) $(OPTS) -c sll.c

real.o : real.c real.h
	$(CC) $(OPTS) -c real.c

integer.o : integer.c integer.h
	$(CC) $(OPTS) -c integer.c

queue.o : queue.c queue.h
	$(CC) $(OPTS) -c queue.c

scanner.o : scanner.c scanner.h
	$(CC) $(OPTS) -c scanner.c

comparator.o : comparator.c comparator.h
	$(CC) $(OPTS) -c comparator.c

clean :
	rm -f $(OBJS) $(TARGET)

test :
	./bstrees -v corpus commands
	./bstrees -r corpus commands

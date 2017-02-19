# makefile for assignment 0
TARGET = assign1_test
OBJS = *.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -g
CC = gcc

$(TARGET) : $(TARGET).o sll.o dll.o queue.o stack.o integer.o real.o string.o
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

clean :
	rm -f $(OBJS) $(TARGET)

test :
	./$(TARGET)

# makefile for assignment 0
#TARGET = sqsort_test
OBJS = *.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -g
CC = gcc

# $(TARGET) : $(TARGET).o sll.o dll.o queue.o stack.o integer.o
	$(CC)  $(LOPTS)  $(OBJS) -o $(TARGET)

$(TARGET).o : $(TARGET).c 
	$(CC) $(OPTS) -c $(TARGET).c

sll.o : sll.c sll.h
	$(CC) $(OPTS) -c sll.c

#integer.o : integer.c integer.h
#	$(CC) $(OPTS) -c integer.c

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

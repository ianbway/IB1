# makefile for assignment 0
TARGET = bstrees
OBJS = *.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -g
CC = gcc

$(TARGET) : $(TARGET).o sll.o queue.o integer.o real.o string.o scanner.o comparator.o
	$(CC)  $(LOPTS)  $(OBJS) -o $(TARGET)

$(TARGET).o : $(TARGET).c 
	$(CC) $(OPTS) -c $(TARGET).c

sll.o : sll.c sll.h
	$(CC) $(OPTS) -c sll.c

real.o : real.c real.h
	$(CC) $(OPTS) -c real.c

integer.o : integer.c integer.h
	$(CC) $(OPTS) -c integer.c

string.o : string.c string.h
	$(CC) $(OPTS) -c string.c

queue.o : queue.c queue.h
	$(CC) $(OPTS) -c queue.c

scanner.o : scanner.c scanner.h
	$(CC) $(OPTS) -c scanner.c

comparator.o : comparator.c comparator.h
	$(CC) $(OPTS) -c comparator.c

clean :
	rm -f $(OBJS) $(TARGET)

test :
	./bstrees -v sampleCorpus1.txt sampleCommands1.txt myOutput1.txt
	./bstrees -v sampleCorpus2.txt sampleCommands2.txt myOutput2.txt
	./bstrees -v sampleCorpus3.txt sampleCommands3.txt myOutput3.txt
	./bstrees -v sampleCorpus4.txt sampleCommands4.txt myOutput4.txt
	./bstrees -v sampleCorpus4.txt sampleCommands5.txt myOutput9.txt
	./bstrees -r sampleCorpus1.txt sampleCommands1.txt myOutput5.txt
	./bstrees -r sampleCorpus2.txt sampleCommands2.txt myOutput6.txt
	./bstrees -r sampleCorpus4.txt sampleCommands4.txt myOutput8.txt
	./bstrees -v corpus0.txt commands0.txt myExtraOutput1.txt
	./bstrees -r corpus0.txt commands0.txt myExtraOutput2.txt
	./bstrees -v corpus1.txt commands1.txt myExtraOutput3.txt
	./bstrees -r corpus1.txt commands2.txt myExtraOutput4.txt
	./bstrees -v corpus2.txt commands3.txt myExtraOutput5.txt
	./bstrees -r corpus2.txt commands4.txt myExtraOutput6.txt
	./bstrees -v corpus3.txt commands5.txt myExtraOutput7.txt
	./bstrees -r corpus3.txt commands5.txt myExtraOutput8.txt
	diff myOutput1.txt out1.txt
	diff myOutput3.txt out3.txt
	diff myOutput4.txt out4.txt
	diff myOutput5.txt out5.txt
	diff myOutput6.txt out6.txt
	diff myOutput8.txt out8.txt
	diff myExtraOutput1.txt output1.txt
	diff myExtraOutput2.txt output2.txt
	diff myExtraOutput3.txt output3.txt
	diff myExtraOutput4.txt output4.txt
	diff myExtraOutput5.txt output5.txt
	diff myExtraOutput6.txt output6.txt
	diff myExtraOutput7.txt output7.txt
	diff myExtraOutput8.txt output8.txt


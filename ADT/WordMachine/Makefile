CC = gcc
CFLAGS = 
SRC = mwordmachine.c

driver: mwordmachine.o wordmachine.o
	$(CC) mwordmachine.o wordmachine.o -o driver

wordmachine.o: wordmachine.c
	$(CC) -c wordmachine.c

mwordmachine.o: mwordmachine.c 
	$(CC) -c $(SRC) 

clean:
	rm mwordmachine.o wordmachine.o driver
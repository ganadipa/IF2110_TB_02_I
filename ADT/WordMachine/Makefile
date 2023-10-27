CC = gcc
CFLAGS = -Wall -Werror -std=c11
SRC = tests/
driver: mwordmachine.o wordmachine.o
	$(CC) -o $@ $(CFLAGS)  $^

wordmachine.o: wordmachine.c
	$(CC) $(CFLAGS) -c $< -o $@

mwordmachine.o: $(SRC)mwordmachine.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY = clean
clean:
	rm -f *.o driver
CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MAIN = simpan.c
SRC_adt = ../lib/ADT/String/string.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJ_adr = $(SRC_adt:.c=.o)

SRC_char = ../lib/ADT/WordMachine/charmachine.c
OBJ_char = $(SRC_char:.c=.o)

SRC_word = ../lib/ADT/WordMachine/wordmachine.c
OBJ_word = $(SRC_word:.c=.o)
.PHONY: all clean test

all: main_program

main_program: $(OBJ_MAIN) $(OBJ_adr) $(OBJ_char) $(OBJ_word) 
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program $(OBJ_MAIN) $(OBJ_adr) $(OBJ_char) $(OBJ_word)



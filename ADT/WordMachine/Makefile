CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MAIN = wordmachine.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: main_program mword

main_program: $(OBJ_MAIN) $(OBJ_WORD)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mword $(OBJ_MAIN) $(OBJ_WORD) $(OBJ_TEST) $(TEST_RESULTS)


# UNIT TESTS

SRC_WORD = wordmachine.c
SRC_TEST = tests/mwordmachine.c
OBJ_WORD = $(SRC_WORD:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mword: $(OBJ_WORD) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_word: mword $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mword
	@if ./mword < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@


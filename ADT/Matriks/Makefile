CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MAIN = matriks.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: main_program mmatriks

main_program: $(OBJ_MAIN) $(OBJ_MATRIKS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mmatriks $(OBJ_MAIN) $(OBJ_MATRIKS) $(OBJ_TEST) $(TEST_RESULTS)







# UNIT TESTS

SRC_MATRIKS = matriks.c
SRC_TEST = tests/mmatriks.c
OBJ_MATRIKS = $(SRC_MATRIKS:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mmatriks: $(OBJ_MATRIKS) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_STATIK: mmatriks $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mmatriks
	@if ./mmatriks < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@


CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MAIN = liststatik.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: main_program mliststatik

main_program: $(OBJ_MAIN) $(OBJ_STATIK)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mliststatik $(OBJ_MAIN) $(OBJ_STATIK) $(OBJ_TEST) $(TEST_RESULTS)







# UNIT TESTS

SRC_STATIK = liststatik.c
SRC_TEST = tests/mliststatik.c
OBJ_STATIK = $(SRC_STATIK:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mliststatik: $(OBJ_STATIK) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_STATIK: mliststatik $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mliststatik
	@if ./mliststatik < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@


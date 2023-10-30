include makefile.que #unit test for queue
include makefile.sta #unit test for stack

include Makefile.din
CC = gcc
CFLAGS = -Wall -Werror -std=c11

#SRC ADT 
src_queue = ADT/Queue/queue.c
src_stack = ADT/Stack/stack.c

SRC_MAIN = main.c

OBJ_MAIN = $(SRC_MAIN:.c=.o)
queue = $(src_queue:.c=.o)
stack = $(src_stack:.c=.o)

.PHONY: all clean test

all: main_program

main_program: $(OBJ_MAIN) $(OBJ_FOO) $(queue) $(stack) 
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mfoo $(OBJ_MAIN) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)

din :
	$(MAKE) -f Makefile.din test_listdinque: #command for testing queue unit test` 
	$(MAKE) -f  makefile.que test_queue 

sta: #command for testing stack unit test
	$(MAKE) -f makefile.sta test_stack
# UNIT TESTS

SRC_FOO = ADT/Foo/foo.c
SRC_TEST = ADT/Foo/tests/mfoo.c
OBJ_FOO = $(SRC_FOO:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Foo/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mfoo: $(OBJ_FOO) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_foo: mfoo $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mfoo
	@if ./mfoo < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

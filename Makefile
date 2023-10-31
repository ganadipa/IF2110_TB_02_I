include Makefile.que #unit test for queue
include Makefile.sta #unit test for stack
include Makefile.word #unit test for wordmachine
include Makefile.din #unit test for list dinamik


BINARY = .bin
BINDIR = .bin
CODEDIRS = app lib/ADT/* lib/Types Function
INCDIRS = app lib/ADT lib/ADT/* lib/Types Function

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 $(DEPFLAGS) $(foreach D, $(INCDIRS), -I$(D)) -Wno-unused-variable -Wno-unused-parameter -Wno-unused-value -Wno-unused-but-set-variable
DEPFLAGS = -MP -MD

CFILES = $(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))
OBJECTS = $(patsubst %.c,$(BINARY)/%.o,$(CFILES))
DEPFILES = $(patsubst %.c,$(BINARY)/%.d,$(CFILES))
PROGRAM = $(BINDIR)/program

all: $(BINARY)

$(BINARY): $(OBJECTS)

$(BINDIR)/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(PROGRAM): $(OBJECTS)
	$(CC) -o $@ $^

clean: 
	rm -rf $(BINDIR)

# Target to run the application
run: $(PROGRAM)
	./$(PROGRAM)

word: 
	$(MAKE) -f Makefile.word test_word

que: 
	$(MAKE) -f Makefile.que test_queue

sta:
	$(MAKE) -f Makefile.sta test_stack

din:
	$(MAKE) -f Makefile.sta test_din




-include $(DEPFILES)
.PHONY: all clean distribute

#************************************************************************************************
#************************************************************************************************
#************************************************************************************************




# UNIT TESTS 

# ************************LinkedList UNIT TEST*************************************
# ************************LinkedList UNIT TEST*************************************
# ************************LinkedList UNIT TEST*************************************
LINKEDLIST_SRC = lib/ADT/LinkedList/listlinier.c
LINKEDLIST_SRC_TEST = lib/ADT/LinkedList/tests/mlistlinier.c
LINKEDLIST_OBJ = $(BINARY)/$(LINKEDLIST_SRC:.c=.o)
LINKEDLIST_OBJ_TEST = $(BINARY)/$(LINKEDLIST_SRC_TEST:.c=.o)

LINKEDLIST_TESTS_DIR = lib/ADT/LinkedList/tests
LINKEDLIST_TEST_CASES = $(wildcard $(LINKEDLIST_TESTS_DIR)/*.in)
LINKEDLIST_TEST_OUTPUTS = $(LINKEDLIST_TEST_CASES:.in=.out)
LINKEDLIST_TEST_RESULTS = $(LINKEDLIST_TEST_CASES:.in=.result)

mlistlinier: $(LINKEDLIST_OBJ) $(LINKEDLIST_OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_listlinier: mlistlinier $(LINKEDLIST_TEST_RESULTS)
	@cat $(LINKEDLIST_TEST_RESULTS)

$(LINKEDLIST_TEST_RESULTS): $(LINKEDLIST_TESTS_DIR)/%.result: $(LINKEDLIST_TESTS_DIR)/%.in $(LINKEDLIST_TESTS_DIR)/%.out mlistlinier
	@if ./mlistlinier < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): PASSED!"; \
	else \
		echo "$< $(word 2,$^): FAILED!"; \
	fi > $@
#************************************************************************************
#************************************************************************************
#************************************************************************************
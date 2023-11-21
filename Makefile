include Makefile.que #unit test for queue
include Makefile.sta #unit test for stack
include Makefile.word #unit test for wordmachine
include Makefile.din #unit test for list dinamik


BINARY = .bin
BINDIR = .bin
CODEDIRS = app lib/ADT/* lib/Types Function lib/Types/Application/* lib/Types/Application
INCDIRS = app lib/ADT lib/ADT/* lib/Types Function lib/Types/Application/* lib/Types/Application

CC = gcc
CFLAGS = -Wall -std=c11 $(DEPFLAGS) $(foreach D, $(INCDIRS), -I$(D))
DEPFLAGS = -MP -MD

CFILES = $(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))
OBJECTS = $(patsubst %.c,$(BINARY)/%.o,$(CFILES))
DEPFILES = $(patsubst %.c,$(BINARY)/%.d,$(CFILES))
PROGRAM = $(BINDIR)/program

all: $(BINARY)

$(BINARY): $(OBJECTS)

$(BINDIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(PROGRAM): $(OBJECTS)
	@echo "Running the code..."
	@$(CC) -o $@ $^

clean: 
	@rm -rf $(BINDIR)
	@echo "Cleaning up files..."

# Target to run the application
run: $(PROGRAM)
	@./$(PROGRAM)

word: 
	$(MAKE) -f Makefile.word test_wordmachine

que: 
	$(MAKE) -f Makefile.que test_queue

sta:
	$(MAKE) -f Makefile.sta test_stack

din:
	$(MAKE) -f Makefile.din test_listdin




-include $(DEPFILES)
.PHONY: all clean distribute

#************************************************************************************************
#************************************************************************************************
#************************************************************************************************




# UNIT TESTS 

# ************************LinkedList UNIT TEST*************************************
# ************************LinkedList UNIT TEST*************************************
# ************************LinkedList UNIT TEST*************************************
LINKEDLIST_DRIVER = lib/ADT/LinkedList/tests/driver.c
LINKEDLIST_SRC = lib/ADT/LinkedList/listlinier.c
LINKEDLIST_SRC_TEST = lib/ADT/LinkedList/tests/mlistlinier.c
LINKEDLIST_OBJ = $(BINARY)/$(LINKEDLIST_SRC:.c=.o)
LINKEDLIST_OBJ_TEST = $(BINARY)/$(LINKEDLIST_SRC_TEST:.c=.o)
LINKEDLIST_DRIVER_OBJ = $(BINARY)/$(LINKEDLIST_DRIVER:.c=.o)

LINKEDLIST_TESTS_DIR = lib/ADT/LinkedList/tests
LINKEDLIST_TEST_CASES = $(wildcard $(LINKEDLIST_TESTS_DIR)/*.in)
LINKEDLIST_TEST_OUTPUTS = $(LINKEDLIST_TEST_CASES:.in=.out)
LINKEDLIST_TEST_RESULTS = $(LINKEDLIST_TEST_CASES:.in=.result)

mlistlinier: $(LINKEDLIST_OBJ) $(LINKEDLIST_OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_listlinier: mlistlinier $(LINKEDLIST_TEST_RESULTS)
	@cat $(LINKEDLIST_TEST_RESULTS)

driver_listlinier: $(LINKEDLIST_DRIVER_OBJ)
	$(CC) $(CFLAGS) -o llist $(LINKEDLIST_DRIVER) $(LINKEDLIST_SRC)


$(LINKEDLIST_TEST_RESULTS): $(LINKEDLIST_TESTS_DIR)/%.result: $(LINKEDLIST_TESTS_DIR)/%.in $(LINKEDLIST_TESTS_DIR)/%.out mlistlinier
	@if ./mlistlinier < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): PASSED!"; \
	else \
		echo "$< $(word 2,$^): FAILED!"; \
	fi > $@
#************************************************************************************
#************************************************************************************
#************************************************************************************

# ************************LinkedList UNIT TEST*************************************
# ************************LinkedList UNIT TEST*************************************
# ************************LinkedList UNIT TEST*************************************
Graf_DRIVER = lib/ADT/Graf/tests/driver.c
Graf_SRC = lib/ADT/Graf/graf.c
Graf_SRC_TEST = lib/ADT/Graf/tests/mgraf.c
Graf_OBJ = $(BINARY)/$(Graf_SRC:.c=.o)
Graf_OBJ_TEST = $(BINARY)/$(Graf_SRC_TEST:.c=.o)
Graf_DRIVER_OBJ = $(BINARY)/$(Graf_DRIVER:.c=.o)

Graf_TESTS_DIR = lib/ADT/Graf/tests
Graf_TEST_CASES = $(wildcard $(Graf_TESTS_DIR)/*.in)
Graf_TEST_OUTPUTS = $(Graf_TEST_CASES:.in=.out)
Graf_TEST_RESULTS = $(Graf_TEST_CASES:.in=.result)

mgraf: $(Graf_OBJ) $(Graf_OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_graf: mgraf $(Graf_TEST_RESULTS)
	@cat $(Graf_TEST_RESULTS)

driver_graf: $(LINKEDLIST_DRIVER_OBJ)
	$(CC) $(CFLAGS) -o graf $(Graf_DRIVER) $(Graf_SRC)
	./graf

$(Graf_TEST_RESULTS): $(Graf_TESTS_DIR)/%.result: $(Graf_TESTS_DIR)/%.in $(Graf_TESTS_DIR)/%.out mgraf
	@if ./mgraf < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): PASSED!"; \
	else \
		echo "$< $(word 2,$^): FAILED!"; \
	fi > $@
#************************************************************************************
#************************************************************************************
#************************************************************************************


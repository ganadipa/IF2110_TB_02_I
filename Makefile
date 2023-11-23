include Makefile.que #unit test for queue
include Makefile.sta #unit test for stack
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

# word: 
# 	$(MAKE) -f Makefile.word test_wordmachine

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

# ************************Graf UNIT TEST*************************************
# ************************Graf UNIT TEST*************************************
# ************************Graf UNIT TEST*************************************
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

# ************************Tree UNIT TEST*************************************
# ************************Tree UNIT TEST*************************************
# ************************Tree UNIT TEST*************************************
Tree_DRIVER = lib/ADT/Tree/tests/driver.c
Tree_SRC = lib/ADT/Tree/tree.c
Tree_SRC2 = lib/ADT/ListDinamik/listdinamik.c
Tree_SRC_TEST = lib/ADT/Tree/tests/mtree.c
Tree_OBJ = $(BINARY)/$(Tree_SRC:.c=.o)
Tree_OBJ_TEST = $(BINARY)/$(Tree_SRC_TEST:.c=.o)
Tree_DRIVER_OBJ = $(BINARY)/$(Tree_DRIVER:.c=.o)

Tree_TESTS_DIR = lib/ADT/Tree/tests
Tree_TEST_CASES = $(wildcard $(Tree_TESTS_DIR)/*.in)
Tree_TEST_OUTPUTS = $(Tree_TEST_CASES:.in=.out)
Tree_TEST_RESULTS = $(Tree_TEST_CASES:.in=.result)

mtree: $(Tree_OBJ) $(Tree_OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^ $(Tree_SRC2)

test_tree: mtree $(Tree_TEST_RESULTS)
	@cat $(Tree_TEST_RESULTS)

driver_tree: $(LINKEDLIST_DRIVER_OBJ)
	$(CC) $(CFLAGS) -o tree $(Tree_DRIVER) $(Tree_SRC) $(Tree_SRC2)
	./tree

$(Tree_TEST_RESULTS): $(Tree_TESTS_DIR)/%.result: $(Tree_TESTS_DIR)/%.in $(Tree_TESTS_DIR)/%.out mtree
	@if ./mtree < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): PASSED!"; \
	else \
		echo "$< $(word 2,$^): FAILED!"; \
	fi > $@
#************************************************************************************
#************************************************************************************
#************************************************************************************

# ************************String UNIT TEST*************************************
# ************************String UNIT TEST*************************************
# ************************String UNIT TEST*************************************
String_DRIVER = lib/ADT/String/tests/driver.c
String_SRC = lib/ADT/String/string.c
String_SRC2 = lib/ADT/WordMachine/wordmachine.c
String_SRC3 = lib/ADT/WordMachine/charmachine.c
String_SRC_TEST = lib/ADT/String/tests/mstring.c
String_OBJ = $(BINARY)/$(String_SRC:.c=.o)
String_OBJ_TEST = $(BINARY)/$(String_SRC_TEST:.c=.o)
String_DRIVER_OBJ = $(BINARY)/$(String_DRIVER:.c=.o)

String_TESTS_DIR = lib/ADT/String/tests
String_TEST_CASES = $(wildcard $(String_TESTS_DIR)/*.in)
String_TEST_OUTPUTS = $(String_TEST_CASES:.in=.out)
String_TEST_RESULTS = $(String_TEST_CASES:.in=.result)

mstring: $(String_OBJ) $(String_OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^ $(String_SRC2) $(String_SRC3)

test_String: mstring $(String_TEST_RESULTS)
	@cat $(String_TEST_RESULTS)

driver_String: $(LINKEDLIST_DRIVER_OBJ)
	$(CC) $(CFLAGS) -o string $(String_DRIVER) $(String_SRC) $(String_SRC2) $(String_SRC3)
	./string

$(String_TEST_RESULTS): $(String_TESTS_DIR)/%.result: $(String_TESTS_DIR)/%.in $(String_TESTS_DIR)/%.out mstring
	@if ./mstring < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): PASSED!"; \
	else \
		echo "$< $(word 2,$^): FAILED!"; \
	fi > $@
#************************************************************************************
#************************************************************************************
#************************************************************************************

# ************************liststatik UNIT TEST*************************************
# ************************liststatik UNIT TEST*************************************
# ************************liststatik UNIT TEST*************************************
liststatik_DRIVER = lib/ADT/ListStatik/tests/driver.c
liststatik_SRC = lib/ADT/ListStatik/liststatik.c
liststatik_SRC_TEST = lib/ADT/ListStatik/tests/mliststatik.c
liststatik_OBJ = $(BINARY)/$(liststatik_SRC:.c=.o)
liststatik_OBJ_TEST = $(BINARY)/$(liststatik_SRC_TEST:.c=.o)
liststatik_DRIVER_OBJ = $(BINARY)/$(liststatik_DRIVER:.c=.o)

liststatik_TESTS_DIR = lib/ADT/ListStatik/tests
liststatik_TEST_CASES = $(wildcard $(liststatik_TESTS_DIR)/*.in)
liststatik_TEST_OUTPUTS = $(liststatik_TEST_CASES:.in=.out)
liststatik_TEST_RESULTS = $(liststatik_TEST_CASES:.in=.result)

mliststatik: $(liststatik_OBJ) $(liststatik_OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^ $(liststatik_SRC2) $(liststatik_SRC3)

test_liststatik: mliststatik $(liststatik_TEST_RESULTS)
	@cat $(liststatik_TEST_RESULTS)

driver_liststatik: $(LINKEDLIST_DRIVER_OBJ)
	$(CC) $(CFLAGS) -o liststatik $(liststatik_DRIVER) $(liststatik_SRC) $(liststatik_SRC2) $(liststatik_SRC3)
	./liststatik

$(liststatik_TEST_RESULTS): $(liststatik_TESTS_DIR)/%.result: $(liststatik_TESTS_DIR)/%.in $(liststatik_TESTS_DIR)/%.out mliststatik
	@if ./mliststatik < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): PASSED!"; \
	else \
		echo "$< $(word 2,$^): FAILED!"; \
	fi > $@
#************************************************************************************
#************************************************************************************
#************************************************************************************

# ************************WordMachine UNIT TEST*************************************
# ************************WordMachine UNIT TEST*************************************
# ************************WordMachine UNIT TEST*************************************
wordmachine_SRC = lib/ADT/WordMachine/wordmachine.c
charmachine_SRC = lib/ADT/WordMachine/charmachine.c
wordmachine_SRC_TEST = lib/ADT/WordMachine/tests/mwordmachine.c
wordmachine_OBJ = $(BINARY)/$(wordmachine_SRC:.c=.o)
charmachine_OBJ = $(BINARY)/$(charmachine_SRC:.c=.o)
wordmachine_OBJ_TEST = $(BINARY)/$(wordmachine_SRC_TEST:.c=.o)

wordmachine_TESTS_DIR = lib/ADT/WordMachine/tests
wordmachine_TEST_CASES = $(wildcard $(wordmachine_TESTS_DIR)/*.in)
wordmachine_TEST_OUTPUTS = $(wordmachine_TEST_CASES:.in=.out)
wordmachine_TEST_RESULTS = $(wordmachine_TEST_CASES:.in=.result)

mwordmachine: $(wordmachine_OBJ) $(charmachine_OBJ) $(wordmachine_OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_wordmachine: mwordmachine $(wordmachine_TEST_RESULTS)
	@cat $(wordmachine_TEST_RESULTS)

$(wordmachine_TEST_RESULTS): $(wordmachine_TESTS_DIR)/%.result: $(wordmachine_TESTS_DIR)/%.in $(wordmachine_TESTS_DIR)/%.out mwordmachine
	@if ./mwordmachine < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): PASSED!"; \
	else \
		echo "$< $(word 2,$^): FAILED!"; \
	fi > $@
#************************************************************************************
#************************************************************************************
#************************************************************************************
# To run this file: just type make

CFLAGS=-Wall -g -std=c99

EXES=ex1 ex2

.PHONY: all
all: ${EXES}

.PHONY: clean
clean:
	rm -f ${EXES}

# use option -B
# .PHONY: again
# again: clean ex1

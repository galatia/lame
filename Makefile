# To run this file: just type make

# this is a target; it's a thing to make
# by default, make makes the first target only
# file to make: files needed
hello: hello.c
# 	tab (not spaces) then command
# 	$@ == file to make
# 	$< == files needed
	gcc $< -std=c99 -o $@

# not actually file to make: command that will be phony
.PHONY: clean
clean:
	rm -f hello

.PHONY: again
# again needs clean (which it uses immediately as make clean) 
# and hello (which it then uses as "make hello" to make it again)
again: clean hello

.PHONY: run
# run depends on hello (causes it to be make-d)
run: hello
	./hello testarg1 testarg2 rubber duck
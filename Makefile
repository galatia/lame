# To run this file: just type make

# file to make: files needed
hello: hello.c
	# tab (not spaces) then command
	# $@ == file to make
	# $< == files needed
	gcc $< -std=c99 -o $@
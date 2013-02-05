FILES=node.c wordstat.c
CFLAGS=-ansi -pedantic -Wall -Werror

.PHONY: debug all

all:
	gcc $(FILES) $(CFLAGS) -o test

debug:
	gcc $(FILES) $(CFLAGS) -g -o test

clean:
	rm test

CC=gcc
CFLAGS=-std=c99 

main:
	$(CC) main.c $(CFLAGS) --output $@

clean:
	rm -rf *.o

.PHONY: clean

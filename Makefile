main:
	$(CC) main.c -std=c99 --output main

clean:
	rm -rf *.o

dist-clean:
	rm -rf main

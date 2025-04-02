CC = gcc
CFLAGS = -std=c99

6001par_match:6001par_match.c
	$(CC) $(CFLAGS) -o $@ $^

run:6001par_match
	./6001par_match

clean:
	rm -f 6001par_match
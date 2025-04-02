CC = gcc
CFLAGS = -std=c99

7003det_substring:7003det_substring.c
	$(CC) $(CFLAGS) -o $@ $^

run:7003det_substring
	./7003det_substring

clean:
	rm -f 7003det_substring
	rm -r *.dSYM
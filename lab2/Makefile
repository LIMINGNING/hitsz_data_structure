CC = gcc
CFLAGS = -std=c99

construct_btree:construct_btree.c
	$(CC) $(CFLAGS) -o $@ $^

run:construct_btree
	./construct_btree

clean:
	find . -type f ! -name "*.*" -exec rm -f {} \;
	find . -type d -name "*.dSYM" -exec rm -rf {} \;
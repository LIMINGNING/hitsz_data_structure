CC = gcc
CFLAGS = -std=c99

imp_que_by_stack:imp_que_by_stack.c
	$(CC) $(CFLAGS) -o $@ $^

run:imp_que_by_stack
	./imp_que_by_stack

clean:
	rm -f imp_que_by_stack
	rm -r *.dSYM

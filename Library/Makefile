CC = gcc
CFLAGS = -Wall -Werror -std=c99 -Wno-unused-result -fdiagnostics-show-option
LDFLAGS = -Wno-unused-result

SRCS = main.c livro.c
OBJS = $(SRCS:.c=.o)

all: main

main: $(OBJS)
	$(CC) $(LDFLAGS) -o main $(OBJS)

main.o: main.c livro.h
	$(CC) $(CFLAGS) -c main.c

livro.o: livro.c livro.h
	$(CC) $(CFLAGS) -c livro.c

clean:
	rm -f $(OBJS) main
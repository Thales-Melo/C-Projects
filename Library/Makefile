CC = gcc
CFLAGS = -Wall -Werror -std=c99 -Wno-unused-result -fdiagnostics-show-option
LDFLAGS = -Wno-unused-result

SRCS = main.c tLivro.c tInterface.c utils.c mainFunctions.c
OBJS = $(SRCS:.c=.o)

all: main

main: $(OBJS)
	$(CC) $(LDFLAGS) -o main $(OBJS)

main.o: main.c mainFunctions.h
	$(CC) $(CFLAGS) -c main.c

tLivro.o: tLivro.c tLivro.h
	$(CC) $(CFLAGS) -c tLivro.c

tInterface.o: tInterface.c tInterface.h
	$(CC) $(CFLAGS) -c tInterface.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c


clean:
	rm -f $(OBJS) main
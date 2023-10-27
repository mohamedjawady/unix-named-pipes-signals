CC = gcc
CFLAGS = -Iincludes/
DEBUGFLAGS = -DDEBUG

all: clientprod serverprod
debug: client server

client: client.c includes/errors.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o client client.c includes/errors.c includes/utils.c

server: server.c includes/errors.c includes/utils.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o server server.c includes/errors.c includes/utils.c

clientprod: client.c includes/errors.c
	$(CC) $(CFLAGS) -o clientprod client.c includes/errors.c includes/utils.c

serverprod: server.c includes/errors.c includes/utils.c
	$(CC) $(CFLAGS) -o serverprod server.c includes/errors.c includes/utils.c
clean:
	rm -f client clientprod server serverprod *.o

.PHONY: all clean

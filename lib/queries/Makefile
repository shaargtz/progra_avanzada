CC = gcc
CFLAGS = -g -Wall

libqueries : queries.o
	$(CC) $(CFLAGS) -shared -o libqueries.so queries.o

queries.o : queries.c queries.h
	$(CC) $(CFLAGS) -fPIC -c queries.c

clean :
	rm libqueries.so queries.o

CC = gcc
CFLAGS = -g -Wall

main : libqueriesEstudiante.so
	$(CC) $(CFLAGS) menu.c -L. -lqueriesEstudiante -o main.out

libqueriesEstudiante.so : estudiante.o queries.o
	$(CC) $(CFLAGS) -shared -o libqueriesEstudiante.so estudiante.o queries.o

estudiante.o : estudiante.c estudiante.h
	$(CC) $(CFLAGS) -c -fPIC estudiante.c

queries.o : queries.c queries.h
	$(CC) $(CFLAGS) -c -fPIC queries.c

clean :
	rm main estudiante.o queries.o libqueriesEstudiante.so

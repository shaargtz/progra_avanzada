CC = gcc
CFLAGS = -g -Wall

libestudiante : estudiante.o
	$(CC) $(CFLAGS) -shared -o libestudiante.so estudiante.o

estudiante.o : estudiante.c estudiante.h
	$(CC) $(CFLAGS) -fPIC -c estudiante.c

clean :
	rm libestudiante.so estudiante.o

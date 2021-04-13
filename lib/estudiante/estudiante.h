#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <stdbool.h>

typedef struct {
    int id;
    char *nombre;
    char *carrera;
    char *ciudad;
    char *fecha;
    int calificaciones[4];
    double promedio;
} Estudiante;

void help();
void muestra(Estudiante arr[], bool write, char *filename);

#endif
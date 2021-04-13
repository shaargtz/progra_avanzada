#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

typedef struct {
    int id;
    char *nombre;
    char *carrera;
    char *ciudad;
    char *fecha;
    int calificaciones[4];
} Estudiante;

void help();
void muestra();

#endif
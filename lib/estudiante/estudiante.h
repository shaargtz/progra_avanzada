#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int id;
    char nombre[16];
    char apellido[16];
    char carrera[3];
    char ciudad[16];
    char fecha[10];
    int calificaciones[4];
    double promedio;
} Estudiante;

void help();
void muestra(Estudiante arr[], bool write, FILE *out, bool verbose, int size);
Estudiante* leeArchivos(char* archivo1, char* archivo2, bool verbose, int size);
int cuentaEstudiantes(char* archivo, bool verbose);

#endif
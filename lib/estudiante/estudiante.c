#include "estudiante.h"
#include <stdlib.h>
#include <stdio.h>

#define MENSAJE_AYUDA   "%s file1 file2 [-h|-v|-o <filename>]\n"\
                        "Permite al usuario hacer consultas sobre los datos de los estudiantes"\
                        "que se encuentran en los archivos file1 y file2.\n\n"\
                        "-h :   muestra ayuda\n"\
                        "-v :   verbose, muestra paso a paso el funcionamiento\n"\
                        "-o :   escribe el output en el archivo que se pase como argumento\n"

void help(const char *progname) {
    fprintf(stderr, MENSAJE_AYUDA, progname);
    exit(EXIT_FAILURE);
}

void muestra(Estudiante arr[], bool write, char *filename) {
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("ID: %i\tNombre: %s\tCarrera: %s\tCiudad: %s\tFecha de graduacion: %s\t"\
            "Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\n", 
            arr[i].id, arr[i].nombre, arr[i].carrera, arr[i].ciudad, arr[i].fecha,
            arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3]);
        if (write) {
            fprintf(filename, "Todos los estudiantes\nID: %i\tNombre: %s\tCarrera: %s\tCiudad: %s\tFecha de graduacion: %s\t"\
                "Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\n",
                arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3]);
        }
    }
}
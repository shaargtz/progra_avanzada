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

void muestra(Estudiante arr[], bool write, FILE *out, bool verbose, int size) {
    if (write) fprintf(out, "Todos los estudiantes\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %i\tNombre: %s\tCarrera: %s\tCiudad: %s\tFecha de graduacion: %s\t"\
            "Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\tPromedio: %.2f\n", 
            arr[i].id, arr[i].nombre, arr[i].carrera, arr[i].ciudad, arr[i].fecha,
            arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3], arr[i].promedio);
        if (write) {
            if (verbose) printf("Escribiendo al archivo...\n");
            fprintf(out, "ID: %i\tNombre: %s\tCarrera: %s\tCiudad: %s\tFecha de graduacion: %s\t"\
                "Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\tPromedio: %.2f\n",
                arr[i].id, arr[i].nombre, arr[i].carrera, arr[i].ciudad, arr[i].fecha,
                arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3], arr[i].promedio);
        }
    }
}

Estudiante* leeArchivos(char* archivo1, char* archivo2, bool verbose, int size) {
    FILE *file1, *file2;

    file1 = fopen(archivo1, "r");
    if (file1 == NULL) {
        printf("No se encontro el archivo %s\n", archivo1);
        exit(1);
    }

    Estudiante *output;
    output = (Estudiante *)malloc(size * sizeof(Estudiante));

    if (verbose) printf("Leyendo datos de alumnos...\n");

    file1 = fopen(archivo1, "r");
    fscanf(file1, "%*[^\n]%*c");
    int counter = 0;
    while (fscanf(file1, "%d %s %s %s %s %s", &output[counter].id, output[counter].nombre, output[counter].apellido,
        output[counter].carrera, output[counter].ciudad, output[counter].fecha) != EOF) counter++;
    fclose(file1);

    if (verbose) printf("Leyendo calificaciones...\n");

    int id, calif1, calif2, calif3, calif4;
    file2 = fopen(archivo2, "r");
    fscanf(file2, "%*[^\n]%*c");
    while (fscanf(file2, "%d %d %d %d %d", &id, &calif1, &calif2, &calif3, &calif4) != EOF) {
        for (int i = 0; i < size; i++) {
            if (output[i].id == id) {
                output[i].calificaciones[0] = calif1;
                output[i].calificaciones[1] = calif2;
                output[i].calificaciones[2] = calif3;
                output[i].calificaciones[3] = calif4;
                output[i].promedio = 1.0 * (calif1 + calif2 + calif3 + calif4) / 4.0;
                break;
            }
        }
    }
    fclose(file2);

    return output;
}

int cuentaEstudiantes(char* archivo, bool verbose) {
    if (verbose) printf("Contando numero de alumnos...\n");
    FILE *file;
    file = fopen(archivo, "r");
    if (file == NULL) {
        printf("No se encontro el archivo %s\n", archivo);
        exit(1);
    }

    int counter = -1;
    while(fscanf(archivo, "%*[^\n]%*c") != EOF) counter++;

    return counter;
}
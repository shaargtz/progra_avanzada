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

Estudiante* leeArchivos(char* archivo1, char* archivo2) {
    FILE *file1, *file2;
    int numeroEstudiantes = 0, dummy;
    
    file1 = fopen(archivo1, "r");
    if (file1 == NULL) {
        printf("No se encontro el archivo %s\n", archivo1);
        exit(1);
    }

    fscanf(file1, "%*[^\n]");
    while (fscanf(file1, "%*[^\n]") != EOF) numeroEstudiantes++;
    fclose(file1);

    Estudiante *output;
    output = (Estudiante *)malloc(numeroEstudiantes * sizeof(Estudiante));

    file1 = fopen(archivo1, "r");
    fscanf(file1, "%*[^\n]");
    int counter = 0;
    while (fscanf(file1, "%d %s %s %s %s", &output[counter].id, output[counter].nombre, 
        output[counter].carrera, output[counter].ciudad, output[counter].fecha) != EOF) counter++;
    fclose(file1);

    file2 = fopen(archivo2, "r");
    fscanf(file2, "%*[^\n]");
    counter = 0;
    while (fscanf(file2, "%d %d %d %d %d", &dummy, 
        &output[counter].calificaciones[0], &output[counter].calificaciones[1],
        &output[counter].calificaciones[2], &output[counter].calificaciones[3]) != EOF) counter++;
    fclose(file2);

    return output;
}
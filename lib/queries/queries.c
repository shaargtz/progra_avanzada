#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../estudiante/estudiante.h"

leeQuery(Estudiante arr[], bool write, char *filename) {
    char *buffer;
    size_t bufsize = 32;
    buffer = (char *)malloc(bufsize * sizeof(char));
    printf("Escribe tu query:\n");
    getline(&buffer, &bufsize, stdin);
    ejecutaQuery(arr, buffer, write, filename);
}

ejecutaQuery(Estudiante arr[], char *query, bool write, char *filename) {
    char *arg1 = strtok(query, " ");
    if (arg1 == "Kardex") {
        char *arg2 = strtok(query, " ");
        if (!arg2) printf("Query invalida");
        else {
            for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                if (arr[i].id == arg2) {
                    printf("Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\n", 
                        arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3]);
                    if (write) {
                        fprintf(filename, "Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\n", 
                            arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3]);
                    }
                    return;
                }
                printf("Query invalida");
            }
        }
    } else if (arg1 == "Fecha_estimada_graduacion") {
        char *arg2 = strtok(query, " ");
        if (!arg2) printf("Query invalida");
        else {
            
        }
    } else if (arg1 == "Numero_alumnos") {
        char *arg2 = strtok(query, " ");
        if (!arg2) printf("Query invalida");
        else {
            char *arg3 = strtok(query, " ");
            if (!arg2) {

            } else {
                
            }
        }
    } else if (arg1 == "Nombre_alumnos") {
        char *arg2 = strtok(query, " ");
        if (!arg2) printf("Query invalida");
        else {
            char *arg3 = strtok(query, " ");
            if (!arg2) {

            } else {
                
            }
        }
    } else {
        printf("Query invalida");
    }
}
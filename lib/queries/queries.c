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
                if (arr[i].id == atoi(arg2)) {
                    printf("Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\n", 
                        arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3]);
                    if (write) {
                        fprintf(filename, "%s\nMateria A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\n", 
                            query, arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3]);
                    }
                    return;
                }
            }
            printf("No dio resultados la query");
        }
    } else if (arg1 == "Fecha_estimada_graduacion") {
        char *arg2 = strtok(query, " ");
        if (!arg2) printf("Query invalida");
        else {
            for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                if (arr[i].id == atoi(arg2)) {
                    printf("Fecha de graduacion: %s\n", 
                        arr[i].fecha);
                    if (write) {
                        fprintf(filename, "%s\nFecha de graduacion: %s\n", 
                            query, arr[i].fecha);
                    }
                    return;
                }
            }
            printf("No dio resultados la query");
        }
    } else if (arg1 == "Numero_alumnos") {
        char *arg2 = strtok(query, " ");
        if (!arg2) printf("Query invalida");
        else {
            char *arg3 = strtok(query, " ");
            if (!arg3) {
                if (arg2 == "*") muestra(arr, write, filename);
                else {
                    int count = 0;
                    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                        if (arr[i].carrera == arg2) {
                            printf("%s\n", arr[i].nombre);
                            count++;
                            if (write) fprintf(filename, "%s\n", query, arr[i].nombre);
                        }
                    }
                    if (!count) printf("No dio resultados la query");
                }
            } else {
                int count = 0;
                for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                    if (arr[i].carrera == arg2 && arr[i].ciudad == arg3) {
                        count++;
                    }
                }
                if (!count) printf("No dio resultados la query");
                else {
                    printf("%d alumnos\n", count);
                    if (write) fprintf(filename, "%d alumnos\n", count);
                }
            }
        }
    } else if (arg1 == "Nombre_alumnos") {
        char *arg2 = strtok(query, " ");
        if (!arg2) printf("Query invalida");
        else {
            char *arg3 = strtok(query, " ");
            if (!arg3) {
                if (arg2 == "*") muestra(arr, write, filename);
                else {
                    int count = 0;
                    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                        if (arr[i].carrera == arg2) {
                            printf("%s\n", arr[i].nombre);
                            count++;
                            if (write) fprintf(filename, "%s\n", query, arr[i].nombre);
                        }
                    }
                    if (!count) printf("No dio resultados la query");
                }
            } else {
                if (arg2 == "<") {
                    int count = 0;
                    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                        char *ptr;
                        double calificacion = strtod(arg3, ptr);
                        if (arr[i].promedio < calificacion) {
                            printf("%s\n", arr[i].nombre);
                            count++;
                            if (write) fprintf(filename, "%s\n", query, arr[i].nombre);
                        }
                    }
                    if (!count) printf("No dio resultados la query");
                } else if (arg2 == ">") {
                    int count = 0;
                    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                        char *ptr;
                        double calificacion = strtod(arg3, ptr);
                        if (arr[i].promedio > calificacion) {
                            printf("%s\n", arr[i].nombre);
                            count++;
                            if (write) fprintf(filename, "%s\n", query, arr[i].nombre);
                        }
                    }
                    if (!count) printf("No dio resultados la query");
                } else if (arg2 == "==") {
                    int count = 0;
                    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                        char *ptr;
                        double calificacion = strtod(arg3, ptr);
                        if (arr[i].promedio == calificacion) {
                            printf("%s\n", arr[i].nombre);
                            count++;
                            if (write) fprintf(filename, "%s\n", query, arr[i].nombre);
                        }
                    }
                    if (!count) printf("No dio resultados la query");
                } else if (arg2 == "!=") {
                    int count = 0;
                    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                        char *ptr;
                        double calificacion = strtod(arg3, ptr);
                        if (arr[i].promedio != calificacion) {
                            printf("%s\n", arr[i].nombre);
                            count++;
                            if (write) fprintf(filename, "%s\n", query, arr[i].nombre);
                        }
                    }
                    if (!count) printf("No dio resultados la query");
                } else {
                    int count = 0;
                    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                        if (arr[i].carrera == arg2 && arr[i].ciudad == arg3) {
                            printf("%s\n", arr[i].nombre);
                            count++;
                            if (write) fprintf(filename, "%s\n", query, arr[i].nombre);
                        }
                    }
                    if (!count) printf("No dio resultados la query");
                }
            }
        }
    } else {
        printf("Query invalida");
    }
}
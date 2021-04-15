#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queries.h"

void ejecutaQuery(Estudiante arr[], char *query, bool write, FILE *out, bool verbose, int size) {
    if (verbose) printf("Ejecutando query...\n");
    if (write) {
        if (verbose) printf("Escribiendo al archivo...\n");
        fprintf(out, "Query: %s\n", query);
    }
    char *arg1 = strtok(query, " ");
    if (!strcmp(arg1, "Kardex")) {
        char *arg2 = strtok(NULL, " ");
        if (!arg2) {
            printf("Query invalida\n");
            if (write) fprintf(out, "Query invalida\n");
        } else {
            for (int i = 0; i < size; i++) {
                if (arr[i].id == atoi(arg2)) {
                    printf("Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\n", 
                        arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3]);
                    if (write) {
                        fprintf(out, "Materia A: %i\tMateria B: %i\tMateria C: %i\tMateria D: %i\n", 
                            arr[i].calificaciones[0], arr[i].calificaciones[1], arr[i].calificaciones[2], arr[i].calificaciones[3]);
                    }
                    return;
                }
            }
            printf("No dio resultados la query\n");
            if (write) fprintf(out, "No dio resultados la query\n");
        }
    } else if (!strcmp(arg1, "Fecha_estimada_graduacion")) {
        char *arg2 = strtok(NULL, " ");
        if (!arg2) {
            printf("Query invalida\n");
            if (write) fprintf(out, "Query invalida\n");
        } else {
            for (int i = 0; i < size; i++) {
                if (arr[i].id == atoi(arg2)) {
                    printf("%s\n", arr[i].fecha);
                    if (write) fprintf(out, "%s\n", arr[i].fecha);
                    return;
                }
            }
            printf("No dio resultados la query\n");
            if (write) fprintf(out, "No dio resultados la query\n");
        }
    } else if (!strcmp(arg1, "Numero_alumnos")) {
        char *arg2 = strtok(NULL, " ");
        if (!arg2) {
            printf("Query invalida\n");
            if (write) fprintf(out, "Query invalida\n");
        } else {
            char *arg3 = strtok(NULL, " ");
            if (!arg3) {
                if (!strcmp(arg2, "*")) {
                    printf("%d alumnos\n", size);
                    if (write) fprintf(out, "%d alumnos\n", size);
                } else {
                    int count = 0;
                    for (int i = 0; i < size; i++) {
                        if (!strcmp(arr[i].carrera, arg2)) count++;
                    }
                    if (!count) printf("No dio resultados la query\n");
                    else {
                        printf("%d alumnos\n", count);
                        if (write) fprintf(out, "%d alumnos\n", count);
                    }
                }
            } else {
                int count = 0;
                for (int i = 0; i < size; i++) {
                    if (!strcmp(arr[i].carrera, arg2) && !strcmp(arr[i].ciudad, arg3)) count++;
                }
                if (!count) {
                    printf("No dio resultados la query\n");
                    if (write) fprintf(out, "No dio resultados la query\n");
                } else {
                    printf("%d alumnos\n", count);
                    if (write) fprintf(out, "%d alumnos\n", count);
                }
            }
        }
    } else if (!strcmp(arg1, "Nombre_alumnos")) {
        char *arg2 = strtok(NULL, " ");
        if (!arg2) {
            printf("Query invalida\n");
            if (write) fprintf(out, "Query invalida\n");
        } else {
            char *arg3 = strtok(NULL, " ");
            if (!arg3) {
                if (!strcmp(arg2, "*")) for (int i = 0; i < size; i++) {
                    printf("%s %s\n", arr[i].nombre, arr[i].apellido);
                    if (write) fprintf(out, "%s %s\n", arr[i].nombre, arr[i].apellido);
                }
                else {
                    int count = 0;
                    for (int i = 0; i < size; i++) {
                        if (!strcmp(arr[i].carrera, arg2)) {
                            printf("%s %s\n", arr[i].nombre, arr[i].apellido);
                            count++;
                            if (write) fprintf(out, "%s %s\n", arr[i].nombre, arr[i].apellido);
                        }
                    }
                    if (!count) {
                        printf("No dio resultados la query\n");
                        if (write) fprintf(out, "No dio resultados la query\n");
                    }
                }
            } else {
                if (!strcmp(arg2, "<")) {
                    int count = 0;
                    for (int i = 0; i < size; i++) {
                        char *ptr;
                        double calificacion = strtod(arg3, ptr);
                        if (arr[i].promedio < calificacion) {
                            printf("%s %s\n", arr[i].nombre, arr[i].apellido);
                            count++;
                            if (write) fprintf(out, "%s %s\n", arr[i].nombre, arr[i].apellido);
                        }
                    }
                    if (!count) {
                        printf("No dio resultados la query\n");
                        if (write) fprintf(out, "No dio resultados la query\n");
                    }
                } else if (!strcmp(arg2, ">")) {
                    int count = 0;
                    for (int i = 0; i < size; i++) {
                        char *ptr;
                        double calificacion = strtod(arg3, ptr);
                        if (arr[i].promedio > calificacion) {
                            printf("%s %s\n", arr[i].nombre, arr[i].apellido);
                            count++;
                            if (write) fprintf(out, "%s %s\n", arr[i].nombre, arr[i].apellido);
                        }
                    }
                    if (!count) {
                        printf("No dio resultados la query\n");
                        if (write) fprintf(out, "No dio resultados la query\n");
                    }
                } else if (!strcmp(arg2, "==")) {
                    int count = 0;
                    for (int i = 0; i < size; i++) {
                        char *ptr;
                        double calificacion = strtod(arg3, ptr);
                        if (arr[i].promedio == calificacion) {
                            printf("%s %s\n", arr[i].nombre, arr[i].apellido);
                            count++;
                            if (write) fprintf(out, "%s %s\n", arr[i].nombre, arr[i].apellido);
                        }
                    }
                    if (!count) {
                        printf("No dio resultados la query\n");
                        if (write) fprintf(out, "No dio resultados la query\n");
                    }
                } else if (!strcmp(arg2, "!=")) {
                    int count = 0;
                    for (int i = 0; i < size; i++) {
                        char *ptr;
                        double calificacion = strtod(arg3, ptr);
                        if (arr[i].promedio != calificacion) {
                            printf("%s %s\n", arr[i].nombre, arr[i].apellido);
                            count++;
                            if (write) fprintf(out, "%s %s\n", arr[i].nombre, arr[i].apellido);
                        }
                    }
                    if (!count) {
                        printf("No dio resultados la query\n");
                        if (write) fprintf(out, "No dio resultados la query\n");
                    }
                } else {
                    int count = 0;
                    for (int i = 0; i < size; i++) {
                        if (!strcmp(arr[i].carrera, arg2) && !strcmp(arr[i].ciudad, arg3)) {
                            printf("%s %s\n", arr[i].nombre, arr[i].apellido);
                            count++;
                            if (write) fprintf(out, "%s %s\n", arr[i].nombre, arr[i].apellido);
                        }
                    }
                    if (!count) {
                        printf("No dio resultados la query\n");
                        if (write) fprintf(out, "No dio resultados la query\n");
                    }
                }
            }
        }
    } else {
        printf("Query invalida\n");
        if (write) fprintf(out, "Query invalida\n");
    }
}

void leeQuery(Estudiante arr[], bool write, FILE *out, bool verbose, int size) {
    scanf("%*c");
    printf("Escribe tu query: ");
    char line[32];
    fgets(line, 32, stdin);
    line[strlen(line) - 1] = '\0';
    if (verbose) printf("Leyendo query...\n");
    ejecutaQuery(arr, line, write, out, verbose, size);
}
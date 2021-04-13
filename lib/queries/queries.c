#include <stdlib.h>
#include <stdio.h>
#include <string.h>

leeQuery() {
    char *buffer;
    size_t bufsize = 32;
    buffer = (char *)malloc(bufsize * sizeof(char));
    printf("Escribe tu query:\n");
    getline(&buffer, &bufsize, stdin);
    ejecutaQuery(buffer);
}

ejecutaQuery(char *query) {
    char *arg1 = strtok(query, " ");
    if (arg1 == "Kardex") {
        char *arg2 = strtok(query, " ");
        if (!arg2) printf("Query invalida");
        else {
            
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
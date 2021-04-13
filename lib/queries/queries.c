#include <stdlib.h>
#include <stdio.h>

leeQuery() {
    char *buffer;
    size_t bufsize = 32;
    buffer = (char *)malloc(bufsize * sizeof(char));
    printf("Escribe tu query:\n");
    getline(&buffer, &bufsize, stdin);
    ejecutaQuery(buffer);
}
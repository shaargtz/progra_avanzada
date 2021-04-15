#ifndef QUERIES_H
#define QUERIES_H
#include "estudiante.h"

void ejecutaQuery(Estudiante arr[], char *query, bool write, FILE *out, bool verbose, int size);
void leeQuery(Estudiante arr[], bool write, FILE *out, bool verbose, int size);

#endif
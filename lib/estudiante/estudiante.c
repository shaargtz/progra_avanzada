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
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <libgen.h>
#include "../lib/estudiante/estudiante.h"
#include "../lib/queries/queries.h"

int main(int argc, char *argv[]) {
    bool menu = true, verbose = false, write = false;
    int choice, opt, numEstudiantes;
    char *filename, *progname, *file1, *file2;
    Estudiante *arr;

    if (argc < 3) {
        printf("Faltan argumentos para ejecutar el programa\n");
        exit(1);
    }

    while ((opt = getopt(argc - 2, argv + 2, "ho:v")) != EOF) {
        switch (opt) {
            case 'h':
                help();
                break;
            case 'v':
                verbose = true;
                break;
            case 'o':
                write = true;
                filename = optarg;
                progname = basename(argv[0]);
                break;
        }
    }

    numEstudiantes = cuentaEstudiantes(argv[1], verbose);
    arr = leeArchivos(argv[1], argv[2], verbose, numEstudiantes);

    while (menu) {
        printf("Selecciona una opcion:\n1 Mostrar estudiantes\n2 Hacer una query\n3 Salir\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                muestra(arr, write, filename, verbose, numEstudiantes);
                break;
            case 2:
                leeQuery(arr, write, filename, verbose, numEstudiantes);
                break;
            case 3:
                menu = false;
                break;
        }
    }

    return 0;
}
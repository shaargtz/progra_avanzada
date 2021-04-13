#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <libgen.h>
#include "../lib/estudiante/estudiante.h"
#include "../lib/queries/queries.h"

int main(int argc, char *argv[]) {
    bool menu = true, verbose = false, write = false;
    int choice, opt;
    char *filename, *progname;

    while ((opt  = getopt(argc, argv, "hvo:")) != EOF) {
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


    while (menu) {
        printf("Selecciona una opcion:\n1 Mostrar estudiantes\n2 Hacer una query\n3 Salir\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                muestra(write, filename, progname);
                break;
            case 2:
                break;
            case 3:
                menu = false;
                break;
        }
    }
    return 0;
}
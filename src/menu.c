#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    bool menu = true;
    int choice;

    while (menu) {
        printf("Selecciona una opcion:\n1 Mostrar estudiantes\n2 Hacer una query\n3 Salir\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
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
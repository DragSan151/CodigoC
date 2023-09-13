#include <stdio.h>

// Declarar los tipos
const int LargoStr = 80;
const int LargoLib = 25;

typedef char String[LargoStr];
typedef String Libreria[LargoLib];
typedef enum { FALSE, TRUE } boolean;

int main() {
    Libreria lib;

    // Leer cada string de la biblioteca
    for (int i = 0; i < LargoLib; i++) {
        int j = 0;
        printf("Ingrese el nombre del libro #%d: ", i + 1);
        scanf("%c", &lib[i][j]);

        while (lib[i][j] != '\n' && j < (LargoStr - 1)) {
            j++;
            scanf("%c", &lib[i][j]);
        }

        lib[i][j] = '\0';
    }

    // Contar cuántos títulos de la biblioteca tienen la palabra AMISTAD.
    int cantidad = 0;
    for (int i = 0; i < LargoLib; i++) {
        int j = 0;
        int pos = 0;
        boolean contiene = FALSE;

        while (lib[i][j] != '\0' && !contiene) {
            if (pos == 0 && (lib[i][j] == 'A' || lib[i][j] == 'a') && (j == 0 || lib[i][j - 1] == ' ')) pos++;
            else if (pos == 1 && (lib[i][j] == 'M' || lib[i][j] == 'm')) pos++;
            else if (pos == 2 && (lib[i][j] == 'I' || lib[i][j] == 'i')) pos++;
            else if (pos == 3 && (lib[i][j] == 'S' || lib[i][j] == 's')) pos++;
            else if (pos == 4 && (lib[i][j] == 'T' || lib[i][j] == 't')) pos++;
            else if (pos == 5 && (lib[i][j] == 'A' || lib[i][j] == 'a')) pos++;
            else if (pos == 6 && (lib[i][j] == 'D' || lib[i][j] == 'd') && (lib[i][j + 1] == '\0' || lib[i][j + 1] == ' ')) {
                contiene = TRUE;
                cantidad++;
            }
            else pos = 0;

            j++;
        }
    }

    printf("\nLa palabra AMISTAD se contro en %d titulo(s)\n\n", cantidad);

    // Mostrar el contenido de la biblioteca
    for (int i = 0; i < LargoLib; i++) {
        int j = 0;
        printf("Libro N%d: ", i + 1);
        while (lib[i][j] != '\0') {
            printf("%c", lib[i][j]);
            j++;
        }
        printf("\n");
    }
}
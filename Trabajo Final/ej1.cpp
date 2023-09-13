#include <stdio.h>

const int BOLSOS = 550;
const int PORTA = 230;

int main() {

    float total = 0;
    char seguir;

    // Obtener info de cada grupo
    do {
        printf("Cuantas personas hay en el grupo? ");
        int cant = 0;
        scanf("%d", &cant);

        float totalSocios = 0;

        for (int i = 0; i < cant; i++) {
            char socio, uruguayo;

            fflush(stdin);
            printf("El integrante %d es Uruguayo? (s/n):  ", i + 1);
            scanf("%c", &uruguayo);

            fflush(stdin);
            printf("\nEl integrante %d es Socio? (s/n):  ", i + 1);
            scanf("%c", &socio);

            if (uruguayo == 's') total += (BOLSOS * 0.9) + PORTA;
            else total += BOLSOS + (PORTA * 0.95);

            if (socio == 's') totalSocios++;
        }

        total = total * ((100 - totalSocios) / 100);

        // Seguir
        fflush(stdin);
        printf("Quiere agregar otro grupo? (s/n):  ");
        scanf("%c", &seguir);
    } while (seguir == 's');

    printf("\nEl total a pagar de la asociacion es: $%.2f", total);
}
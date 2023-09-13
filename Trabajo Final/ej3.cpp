#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 5;

typedef int Matriz[N][N];

int main()
{
    Matriz matriz;
    int opcion;
    srand(time(NULL));

    // Cargar la matriz con valores aleatorios entre 1 y 10
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 10 + 1;
        }
    }

    printf("Bienvenido al ejercicio 3\n");

    // Mostrar la matriz en pantalla con formato de cuadricula
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] < 10) printf("0%d ", matriz[i][j]);
            else printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    while (opcion != 2) {

        printf("\nSelecciona una opcion:\n");
        printf("1. Obtener la diferencia entre la suma de los elementos de la diagonal principal y la secundaria.\n");
        printf("2. Devolver el promedio de los elementos del rectongulo inferior.\n");
        printf("3. Calcular la suma de los valores de la fila superior y la columna izquierda.\n");
        scanf("%d", &opcion);

        printf("------------------------------------------------------------------------------------------------------\n");

        switch (opcion) {
        case 1: // Obtener la diferencia entre la suma de los elementos de la diagonal principal y la secundaria.
        {
            int diagonalPrincipal = 0;
            int diagonalSecundaria = 0;

            for (int i = 0; i < N; i++) {
                diagonalPrincipal += matriz[i][i];
                diagonalSecundaria += matriz[i][N - i - 1];
            }

            int resta = diagonalPrincipal - diagonalSecundaria;

            printf("La diferencia entre la suma de los elementos de la diagonal principal y la secundaria es: %d\n", resta);
            break;
        }

        case 2: // Devolver el promedio de los elementos del rectangulo inferior.
        {
            float rectanguloInferior = 0;
            int tam = 0;
            // El indice de la mediana depende si es par o impar
            int medH = N / 2;
            if (N % 2 != 0) medH++;

            for (int i = medH; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    rectanguloInferior += matriz[i][j];
                    tam++;
                }
            }

            float promedio = rectanguloInferior / tam;

            printf("El promedio de los elementos del rectangulo inferior es: %.1f\n", promedio);
            break;
        }

        case 3: // Calcular la suma de los valores de la fila superior y la columna izquierda.
        {
            int filaSuperior = 0;
            int columnaIzquierda = 0;

            for (int i = 0; i < N; i++) {
                filaSuperior += matriz[0][i];
                if (i != 0) {
                    columnaIzquierda += matriz[i][0];
                }
            }

            int suma = filaSuperior + columnaIzquierda;
            printf("La suma de los valores de la fila superior y la columna izquierda es: %d\n", suma);
            break;
        }
        default:
            printf("Opcion invalida.\n");
            break;
        }

        printf("\nQuieres seguir con el programa?(1-Si o 2-No)\n");
        scanf("%d", &opcion);
    }
}
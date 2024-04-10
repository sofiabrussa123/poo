#include <stdio.h>

int main()
{
    int filas, columnas;
    printf("Este programa te pide una matriz de dimensiones especificadas.\n\n");

    printf("Ingresa el número de filas: ");
    scanf("%d", &filas);

    printf("Ingresa el número de columnas: ");
    scanf("%d", &columnas);

    int A[filas][columnas];
    int i, j;

    printf("\nIngresa los elementos de la matriz:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("Ingresa el valor A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nLa matriz ingresada es:\n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
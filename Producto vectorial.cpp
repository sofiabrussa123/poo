#include <stdio.h>

int main() {
    float vector1[3], vector2[3], productoVectorial[3];
    int i;

    printf("Ingrese las coordenadas del primer vector (x y z):\n");
    for(i = 0; i < 3; i++) {
        scanf("%f", &vector1[i]);
    }

    printf("Ingrese las coordenadas del segundo vector (x y z):\n");
    for(i = 0; i < 3; i++) {
        scanf("%f", &vector2[i]);
    }

    productoVectorial[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    productoVectorial[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    productoVectorial[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

    printf("El producto vectorial de los vectores es: (%.2f, %.2f, %.2f)\n", productoVectorial[0], productoVectorial[1], productoVectorial[2]);

    return 0;
}


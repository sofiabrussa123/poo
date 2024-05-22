#include <stdio.h>

int main() {
    float vector1[3], vector2[3], productoEscalar = 0.0;
    int i;

    printf("Ingrese las coordenadas del primer vector (x y z):\n");
    for(i = 0; i < 3; i++) {
        scanf("%f", &vector1[i]);
    }

    printf("Ingrese las coordenadas del segundo vector (x y z):\n");
    for(i = 0; i < 3; i++) {
        scanf("%f", &vector2[i]);
    }

    for(i = 0; i < 3; i++) {
        productoEscalar += vector1[i] * vector2[i];
    }

    printf("El producto escalar de los vectores es: %.2f\n", productoEscalar);

    return 0;
}


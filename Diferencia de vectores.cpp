#include <stdio.h>

int main() {
    float vector1[2], vector2[2], diferencia[2];
    int i;

    printf("Ingrese las coordenadas del primer vector (x y):\n");
    for(i = 0; i < 2; i++) {
        scanf("%f", &vector1[i]);
    }

    printf("Ingrese las coordenadas del segundo vector (x y):\n");
    for(i = 0; i < 2; i++) {
        scanf("%f", &vector2[i]);
    }

    for(i = 0; i < 2; i++) {
        diferencia[i] = vector1[i] - vector2[i];
    }

    printf("La diferencia de los vectores es: (%.2f, %.2f)\n", diferencia[0], diferencia[1]);

    return 0;
}



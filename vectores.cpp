#include <stdio.h>

int main() {
    float vector1[2], vector2[2];
    int i;

    printf("Ingrese las coordenadas del primer vector (x y):\n");
    for(i = 0; i < 2; i++) {
        scanf("%f", &vector1[i]);
    }

    printf("Ingrese las coordenadas del segundo vector (x y):\n");
    for(i = 0; i < 2; i++) {
        scanf("%f", &vector2[i]);
    }

    if(vector1[0] * vector2[1] == vector1[1] * vector2[0]) {
        printf("Los vectores son linealmente dependientes.\n");
    } else {
        printf("Los vectores no son linealmente dependientes.\n");
    }

    return 0;
}


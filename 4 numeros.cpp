#include <stdio.h>

int main() {
    float numeros[4];
    float suma = 0.0, media;
    int i;

    printf("Ingrese 4 numeros:\n");
    for(i = 0; i < 4; i++) {
        scanf("%f", &numeros[i]);
        suma += numeros[i];
    }

    media = suma / 4;
    printf("Los numeros ingresados son: ");
    for(i = 0; i < 4; i++) {
        printf("%.2f ", numeros[i]);
    }
    printf("\nLa media aritmetica es: %.2f\n", media);

    return 0;
}


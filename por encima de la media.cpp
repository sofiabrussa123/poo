#include <stdio.h>

int main() {
    float numeros[10];
    float suma = 0.0, media;
    int i;

    printf("Ingrese 10 numeros:\n");
    for(i = 0; i < 10; i++) {
        scanf("%f", &numeros[i]);
        suma += numeros[i];
    }

    media = suma / 10;
    printf("La media es: %.2f\n", media);
    printf("Los numeros por encima de la media son: ");
    for(i = 0; i < 10; i++) {
        if(numeros[i] > media) {
            printf("%.2f ", numeros[i]);
        }
    }
    printf("\n");

    return 0;
}




#include <stdio.h>

int main() {
    int numeros[10];
    int i, mayor;

    printf("Ingrese 10 numeros:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    mayor = numeros[0];
    for(i = 1; i < 10; i++) {
        if(numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }

    printf("El numero mayor es: %d\n", mayor);

    return 0;
}




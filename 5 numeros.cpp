#include <stdio.h>

int main() {
    int numeros[5];
    int i;

    printf("Ingrese 5 numeros:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Los numeros en orden inverso son: ");
    for(i = 4; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}



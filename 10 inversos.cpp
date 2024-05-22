#include <stdio.h>

int main() {
    int numeros[10];
    int i;

    printf("Ingrese 10 numeros:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Los numeros en orden inverso son: ");
    for(i = 9; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}



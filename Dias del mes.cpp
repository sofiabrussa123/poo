#include <stdio.h>

int main() {
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes;

    printf("Ingrese el mes (1-12): ");
    scanf("%d", &mes);

    if(mes >= 1 && mes <= 12) {
        printf("El mes %d tiene %d dias.\n", mes, diasPorMes[mes - 1]);
    } else {
        printf("Mes invalido.\n");
    }

    return 0;
}



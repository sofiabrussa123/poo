#include <stdio.h>

int main() {
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes, dia, diaDelAnio = 0;
    int i;

    printf("Ingrese el mes (1-12): ");
    scanf("%d", &mes);
    printf("Ingrese el dia (1-31): ");
    scanf("%d", &dia);

    if(mes >= 1 && mes <= 12 && dia >= 1 && dia <= diasPorMes[mes - 1]) {
        for(i = 0; i < mes - 1; i++) {
            diaDelAnio += diasPorMes[i];
        }
        diaDelAnio += dia;
        printf("El dia %d del mes %d es el dia %d del anio.\n", dia, mes, diaDelAnio);
    } else {
        printf("Fecha invalida.\n");
    }

    return 0;
}



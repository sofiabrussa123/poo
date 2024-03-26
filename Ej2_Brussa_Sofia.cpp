#include <stdio.h>

int main() {
    int opcion;
    int credito;
    int wifi;
    int nota_examen1, nota_examen2;
    int sueldo;
    float aumento, nuevo_sueldo;
    char mensaje[100];

    do {
        printf("Seleccione una opción:\n");
        printf("1. Enviar mensaje de texto o WhatsApp\n");
        printf("2. Verificar aptitud para el curso de capacitación\n");
        printf("3. Calcular aumento de sueldo\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
               printf("Ingrese el estado del crédito (1 si hay crédito, 0 si no hay crédito): ");
                scanf("%d", &credito);
                printf("Ingrese el estado del servicio de Wifi (1 si hay servicio, 0 si no hay servicio): ");
                scanf("%d", &wifi);
                printf("Ingrese el mensaje a enviar: ");
                scanf(" %[^\n]s", mensaje);  // Leer el mensaje incluyendo espacios

                if (credito == 1 || wifi == 1) {
                    printf("Mensaje enviado: %s\n", mensaje);
                } else {
                    printf("No se puede enviar el mensaje. No hay crédito ni servicio de Wifi.\n");
                }
                break;

            case 2:
                printf("Ingrese la nota del primer examen: ");
                scanf("%d", &nota_examen1);
                printf("Ingrese la nota del segundo examen: ");
                scanf("%d", &nota_examen2);

                if (nota_examen1 >= 7 && nota_examen2 >= 8) {
                    printf("Apto\n");
                } else {
                    printf("No apto\n");
                }

                break;

            case 3:
                printf("Ingrese el sueldo del trabajador: ");
                scanf("%d", &sueldo);

                if (sueldo < 8000) {
                    aumento = sueldo * 0.15;
                } else {
                    aumento = sueldo * 0.12;
                }

                nuevo_sueldo = sueldo + aumento;
                printf("El nuevo sueldo del trabajador es: %.2f\n", nuevo_sueldo);

                break;

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                break;
        }

        printf("\n");

    } while (opcion != 0);

    return 0;
}
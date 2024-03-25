#include <stdio.h>

int main() {
    int opcion;
    int continuar;
    
    do {
        printf("\n Seleccione una opcion: \n");
        printf("\n1. Verificar si un numero es positivo o negativo.\n");
        printf("2. Verificar si un numero es par o impar.\n");
        printf("3. Verificar si un número es multiplo de 2, de 3, ambos o ninguno.\n");
        printf("4. Encontrar el mayor y el menor entre tres valores.\n");
        printf("\nIngrese su opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                int numero;
                printf("Ingrese un numero: ");
                scanf("%d", &numero);
                
                if (numero > 0) {
                    printf("El numero es positivo.\n");
                } else if (numero < 0) {
                    printf("El numero es negativo.\n");
                } else {
                    printf("El numero es cero.\n");
                }
                break;
            }
                
            case 2: {
                int numero;
                printf("Ingrese un numero: ");
                scanf("%d", &numero);
                
                if (numero % 2 == 0) {
                    printf("El numero es par.\n");
                } else {
                    printf("El numero es impar.\n");
                }
                break;
            }
                
            case 3: {
                int numero;
                printf("Ingrese un numero: ");
                scanf("%d", &numero);
                
                if (numero % 2 == 0 && numero % 3 == 0) {
                    printf("El numero es multiplo de 2 y de 3.\n");
                } else if (numero % 2 == 0) {
                    printf("El numero es multiplo de 2 pero no de 3.\n");
                } else if (numero % 3 == 0) {
                    printf("El numero es multiplo de 3 pero no de 2.\n");
                } else {
                    printf("El numero no es multiplo de 2 ni de 3.\n");
                }
                break;
            }
                
            case 4: {
                int numero1, numero2, numero3;
                printf("\nIngrese tres numeros: \n");
                scanf("%d %d %d", &numero1, &numero2, &numero3);
                
                int mayor = numero1;
                int menor = numero1;
                
                if (numero2 > mayor) {
                    mayor = numero2;
                }
                if (numero3 > mayor) {
                    mayor = numero3;
                }
                
                if (numero2 < menor) {
                    menor = numero2;
                }
                if (numero3 < menor) {
                    menor = numero3;
                }
                
                printf("El mayor es: %d\n", mayor);
                printf("El menor es: %d\n", menor);
                break;
            }
                
            default:
                printf("Opcion invalida.\n");
                break;
        }
        
        printf("\n¿Desea realizar otra operacion? (1 para si, 0 para no): ");
        scanf("%d", &continuar);
        printf("\n");
    } while (continuar == 1);
    
    printf("¡Gracias por usar el programa!\n");
    
    return 0;
}

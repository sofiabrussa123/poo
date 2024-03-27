#include <stdio.h>

int main() {
    int opcion;
    
    do {
        printf("Menú:\n");
        printf("1. Hallar tres números consecutivos cuya suma sea 87.\n");
        printf("2. Calcular la media (promedio) de 3 números.\n");
        printf("3. Determinar si un valor numérico positivo es par o impar.\n");
        printf("4. Determinar si un alumno aprobó una materia.\n");
        printf("5. Determinar el resultado de una nota.\n");
        printf("6. Calcular el impuesto por concepto de alquiler.\n");
        printf("0. Salir.\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                int numero;
                int num1, num2, num3;
                int suma;
                
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                
                for (num1 = numero; num1 <= numero - 2; num1++) {
                    num2 = num1 + 1;
                    num3 = num2 + 1;
                    suma = num1 + num2 + num3;
                    
                    if (suma == 87) {
                        printf("Los números consecutivos son: %d, %d, %d\n", num1, num2, num3);
                        break;
                    }
                }
                
                if (suma != 87) {
                    printf("No se encontraron números consecutivos cuya suma sea 87.\n");
                }
                
                break;
            }
            
            case 2: {
                float num1, num2, num3;
                float promedio;
                
                printf("Ingrese los tres números: ");
                scanf("%f %f %f", &num1, &num2, &num3);
                
                promedio = (num1 + num2 + num3) / 3;
                
                printf("El promedio es: %.2f\n", promedio);
                
                break;
            }
            
            case 3: {
                int numero;
                
                printf("Ingrese un número positivo: ");
                scanf("%d", &numero);
                
                if (numero > 0) {
                    if (numero % 2 == 0) {
                        printf("El número es par.\n");
                    } else {
                        printf("El número es impar.\n");
                    }
                } else {
                    printf("El número no es positivo.\n");
                }
                
                break;
            }
            
            case 4: {
                float nota1, nota2, nota3, nota4, tarea;
                float promedio;
                
                printf("Ingrese las notas de las cuatro pruebas y la nota de la tarea: ");
                scanf("%f %f %f %f %f", &nota1, &nota2, &nota3, &nota4, &tarea);
                
                promedio = (nota1 + nota2 + nota3 + nota4 + tarea) / 5;
                
                if (promedio >= 6) {
                    printf("El alumno aprobó la materia.\n");
                } else {
                    printf("El alumno no aprobó la materia.\n");
                }
                
                break;
            }
            
            case 5: {
                float nota;
                
                printf("Ingrese una nota: ");
                scanf("%f", &nota);
                
                if (nota >= 6) {
                    printf("Aprobado.\n");
                    
                    if (nota >= 8) {
                        printf("¡Felicitaciones!\n");
                    }
                } else if (nota == 1) {
                    printf("Debes esforzarte más.\n");
                } else {
                    printf("Reprobado.\n");
                }
                
                break;
            }
            
            case 6: {
                float alquiler;
                float impuesto;
                
                printf("Ingrese el monto del alquiler: ");
                scanf("%f", &alquiler);
                
                if (alquiler <= 202) {
                    impuesto = 0;
                } else if (alquiler <= 607) {
                    impuesto = alquiler * 0.05;
                } else if (alquiler <= 1013) {
                    impuesto = alquiler * 0.10;
                } else if (alquiler <= 1418) {
                    impuesto = alquiler * 0.15;
                } else {
                    impuesto = alquiler * 0.25;
                }
                
                printf("El impuesto a pagar por el alquiler es: %.2f\n", impuesto);
                
                break;
            }
            
            case0:
                printf("Saliendo del programa...\n");
                break;
                
            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
        }
        
        printf("\n");
    } while (opcion != 0);
    
    return 0;
}
#include <stdio.h>

int main() {
    int opcion;
    int continuar;
    
    do {
        printf("Seleccione una opcion:\n");
        printf("1. Cobro de viaje de estudios.\n");
        printf("2. Calculo de comisiones de un vendedor.\n");
        printf("3. Calculo de calificacion final del alumno.\n");
        printf("4. Impresion de numeros pares.\n");
        printf("5. Encuentro en la carretera.\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
			    int cantidadAlumnos;
			    int costoAlumno;
			    int costoTotal;
			
			    printf("Ingrese la cantidad de alumnos: ");
			    scanf("%d", &cantidadAlumnos);
			
			    if (cantidadAlumnos >= 100) {
			        costoAlumno = 500;
			    } else if (cantidadAlumnos >= 50 && cantidadAlumnos < 100) {
			        costoAlumno = 400;
			    } else if (cantidadAlumnos >= 30 && cantidadAlumnos < 50) {
			        costoAlumno = 300;
			    } else {
			        costoAlumno = 6000 / cantidadAlumnos;
			    }
			
			    if (cantidadAlumnos < 30) {
			        costoTotal = 6000;
			    } else {
			        costoTotal = cantidadAlumnos * costoAlumno;
			    }
			
			    printf("El costo por alumno es de: $%d\n", costoAlumno);
			    printf("El costo total del viaje es de: $%d\n", costoTotal);
                break;
            }
                
            case 2: {
                float sueldoBase;
                float ventas[3];
                float comision;
                float totalMes;
                
                printf("Ingrese el sueldo base del vendedor: $");
                scanf("%f", &sueldoBase);
                
                for (int i = 0; i < 3; i++) {
                    printf("Ingrese el monto de la venta %d: $", i + 1);
                    scanf("%f", &ventas[i]);
                }
                
                comision = (ventas[0] + ventas[1] + ventas[2]) * 0.1;
                totalMes = sueldoBase + comision;
                
                printf("El monto de las comisiones es de: $%.2f\n", comision);
                printf("El total que recibira en el mes es de: $%.2f\n", totalMes);
                break;
            }
                
            case 3: {
                float calificaciones[3];
                float promedioParciales;
                float calificacionFinal;
                float trabajoFinal;
                float calificacionFinalMateria;
                
                for (int i = 0; i < 3; i++) {
                    printf("Ingrese la calificacion del parcial %d: ", i + 1);
                    scanf("%f", &calificaciones[i]);
                }
                
                printf("Ingrese la calificacion del examen final: ");
                scanf("%f", &calificacionFinal);
                
                printf("Ingrese la calificacion del trabajo final: ");
                scanf("%f", &trabajoFinal);
                
                promedioParciales = (calificaciones[0] + calificaciones[1] + calificaciones[2]) / 3;
                
                calificacionFinalMateria = (promedioParciales * 0.55) + (calificacionFinal * 0.30) + (trabajoFinal * 0.15);
                
                printf("La calificacion final en la materia es: %.2f\n", calificacionFinalMateria);
                break;
            }
                
            case 4: {
                int numero1, numero2;
                
                printf("Ingrese el primer numero: ");
                scanf("%d", &numero1);
                
                printf("Ingrese el segundo numero: ");
                scanf("%d", &numero2);
                
                printf("Numeros pares entre %d y %d:\n", numero1, numero2);
                
                for (int i = numero1; i <= numero2; i++) {
                    if (i % 2 == 0) {
                        printf("%d ", i);
                    }
                }
                
                printf("\n");
                break;
            }
                
            case 5: {

				int posicion_auto1 = 70;
				int posicion_auto2 = 150;
				int velocidad;
				int distancia_recorrida;
				float tiempo;
				int posicion_encuentro;
				
				printf("Un auto se encuentra en el kilómetro 70 y otro en el kilómetro 150.\n");
				printf("Van en sentidos opuestos y a la misma velocidad.\n");
				printf("Ingrese la velocidad (km/h): ");
				scanf("%d", &velocidad);
				
				distancia_recorrida = posicion_auto2 - posicion_auto1;
				tiempo = (float)distancia_recorrida / (2 * velocidad);
				posicion_encuentro = posicion_auto1 + velocidad * tiempo;
				
				printf("Los autos se encontrarán en el kilómetro %d de la carretera.\n", posicion_encuentro);
				printf("El encuentro ocurrirá después de %.2f horas.\n", tiempo);
				
				
				}
                break;
                
            default:
                printf("Opcion invalida.\n");
                break;
        }
        
        printf("¿Desea realizar otra operación? (1 para si, 0 para no): ");
        scanf("%d", &continuar);
        printf("\n");
    } while (continuar == 1);
    
    printf("¡Gracias por usar el programa!\n");
    
    return 0;
}

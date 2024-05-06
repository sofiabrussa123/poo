#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
    int opcion, jugada, maquina, acumJugador, acumMaquina, acumPuntosJ = 0, acumPuntosM = 0, acumEmpates = 0, i, j;
    char nombre[50];
	
    printf("Bienvenido al juego de piedra, papel y tijera!\n\n");

    printf("Por favor, ingresa tu nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea del nombre

    printf("\nHola, %s!\n", nombre);

    do {
        printf("\nMenu:\n");
        printf("1. Jugar\n");
        printf("2. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el búfer del teclado

        switch (opcion) {
            case 1:
                acumJugador = 0;
                acumMaquina = 0;
                acumPuntosJ = 0;
                acumPuntosM = 0;
                acumEmpates = 0;

                for (i = 0; i < 5; i++) {
                    printf("\nRonda %d\n\n", i + 1);
                    for (j = 0; j < 3; j++) {
                        printf("Ingrese piedra (1), papel (2) o tijera (3): ");
                        scanf("%d", &jugada);

                        srand(time(NULL));
                        maquina = 1 + rand() % 3;

                        // Comparar las jugadas del jugador y la máquina para determinar el resultado
                        if (jugada == 1 && maquina == 1) {
                            printf("Piedra - Piedra: Empate\n");
                            acumEmpates++;
                        } else if (jugada == 1 && maquina == 2) {
                            printf("Piedra - Papel: Perdiste\n");
                            acumMaquina++;
                        } else if (jugada == 1 && maquina == 3) {
                            printf("Piedra - Tijera: Ganaste\n");
                            acumJugador++;
                        } else if (jugada == 2 && maquina == 1) {
                            printf("Papel - Piedra: Ganaste\n");
                            acumJugador++;
                        } else if (jugada == 2 && maquina == 2) {
                            printf("Papel - Papel: Empate\n");
                            acumEmpates++;
                        } else if (jugada == 2 && maquina == 3) {
                            printf("Papel - Tijera: Perdiste\n");
                            acumMaquina++;
                        } else if (jugada == 3 && maquina == 1) {
                            printf("Tijera - Piedra: Perdiste\n");
                            acumMaquina++;
                        } else if (jugada == 3 && maquina == 2) {
                            printf("Tijera - Papel: Ganaste\n");
                            acumJugador++;
                        } else if (jugada == 3 && maquina == 3) {
                            printf("Tijera - Tijera: Empate\n");
                            acumEmpates++;
                        } else {
                            printf("Dato incorrecto\n");
                        }
                    }

                    // Comparar los acumuladores para determinar el ganador de la ronda
                    if (acumJugador > acumMaquina) {
                        acumPuntosJ++;
                    } else if (acumMaquina > acumJugador) {
                        acumPuntosM++;	
                    } 
                }

                printf("\nResultados:\n");
                printf("Partidas ganadas: %d\n", acumPuntosJ);
                printf("Partidas empatadas (no cuentan para ninguno): %d\n", acumEmpates);
                printf("Partidas perdidas: %d\n", acumPuntosM);

                // Comparar los acumuladores finales para determinar el ganador del juego
                if (acumPuntosJ > acumPuntosM) {
                    printf("\nGanaste!\n");
                } else if (acumPuntosJ < acumPuntosM) {
                    printf("\nPerdiste :(\n");
                } else if (acumPuntosJ == acumPuntosM) {
                    printf("\nEmpate!\n");
                }
                break;
            case 2:
                printf("\nGracias por jugar, %s! Hasta luego.\n", nombre);
                break;
            default:
			    printf("\nOpción inválida. Por favor, elige una opción válida.\n");
			    break;
		}
		} while (opcion != 2);
		
		return 0;
		}

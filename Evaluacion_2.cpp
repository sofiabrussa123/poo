/******************************************************************************
Sofia Brussa 5° 2da
compilador "https://www.onlinegdb.com/"
Tema N°5

El club del barrio inaugura un gimnasio en sus instalaciones. En los primeros meses deciden promocionar solamente 4 clases, 
estas son "Top Ride", "Zumba", "Entrenamiento" y "Abdominales". Cada clase tiene un cupo de participantes. 
Todas las clases se dan en simultáneo y tienen 5 horarios diferentes. 
Estos horarios se distinguen como Horario 1, Horario 2. Horario 3, Horario 4 y Horario 5.
Para llevar un control en el gimnasio los alumnos deben anotarse 
cada vez que ingresan a una clase dando como dato el "Nombre" de dicha clase; 
aquellos que superen el cupo se los debe informar a través de un mensaje
Puede ocurrir que quede algún horario sin el dictado de alguna de las actividades por no asistir ningún alumno,
Los informes se deben dar cuando el usuario no quiera ingresar más alumnos porque los horarios finalizaron 
o porque todas las clases en sus horarios carecen de cupo.

Se pide:
Utilizar un vector para el cupo de las actividades y una matriz para registrar la asistencia de los alumnos
Informar cual es la clase en la que no concurrió ningún alumno
Informar cual es el horario en el que no se dicto ninguna clase
Informar la cantidad de personas que concurrió a cada clase
informar la ganancia obtenida en el dia sabiendo que en el horario central la clase cuesta 5 700 
y en los horarios inferiores el costo disminuye en un 20% y en los horarios superiores el costo aumenta un 15%


comprension:
usar matrices,vectores,funciones,comentar e identar codigo, colores,que este bien ordenado. Usar buena interfaz.
clases (se dan el simultaneo)
top Ride
Zumba 
Entrenamiento
Abdominales

horarios 
1
2
3 (horario central)
4
5

inscripcion (cada clase)
nombre de alumno

llevar control de cupo con un vector
llevar control de asistencias con una matriz
calcular costo de cada clase

hacer un menu con el que se va a interactuar para las incripciones (usar colores):
1. top Ride
2. Zumba
3. Entrenamiento
4. Abdominales
5. salir 

luego de salir efectuar el informe de (hacer un menu aparte que deje elegir que informe ver):
ganacias del dia por clase
en que clase no fueron los alumnos
en que horario no hubo clases
asistencias por clase
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CLASSES 4
#define MAX_SLOTS 5
#define MAX_CUPOS 10

// Definición de los nombres de las clases y horarios
const char *classes[MAX_CLASSES] = {"Top Ride", "Zumba", "Entrenamiento", "Abdominales"};
const char *slots[MAX_SLOTS] = {"Horario 1", "Horario 2", "Horario 3", "Horario 4", "Horario 5"};

// Arrays para controlar los cupos y la asistencia
int cupos[MAX_CLASSES] = {10, 10, 10, 10};
int asistencia[MAX_CLASSES][MAX_SLOTS] = {0};
int total_asistencia[MAX_CLASSES] = {0};

// Función para limpiar la pantalla
void limpiarPantalla() {
    printf("\033[H\033[J"); // Secuencia ANSI para limpiar la pantalla
}

// Función para inscribir un alumno
void inscribir_alumno(int clase) {
    int horario;
    char nombre[50];

    limpiarPantalla(); // Limpiar la pantalla al iniciar la inscripción

    // Mostrar opciones de horarios
    printf("Seleccione el horario:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        printf("%d. %s\n", i + 1, slots[i]);
    }

    // Validar la entrada del horario
    while (scanf("%d", &horario) != 1 || horario < 1 || horario > MAX_SLOTS) {
        printf("Horario no válido. Intente de nuevo: ");
        while (getchar() != '\n'); // Limpiar el buffer de entrada
    }
    horario--; // Ajustar al índice del array

    // Verificar si hay cupo disponible en el horario seleccionado
    if (asistencia[clase][horario] < cupos[clase]) {
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nombre);
        asistencia[clase][horario]++;
        total_asistencia[clase]++;
        printf("Alumno %s inscrito en %s en %s\n", nombre, classes[clase], slots[horario]);
    } else {
        printf("Cupo lleno para %s en %s\n", classes[clase], slots[horario]);
    }
}

// Función para generar informe de clases sin alumnos
void informe_clase_sin_alumnos() {
    limpiarPantalla(); // Limpiar la pantalla antes del informe
    for (int i = 0; i < MAX_CLASSES; i++) {
        int asistencia_total = 0;
        for (int j = 0; j < MAX_SLOTS; j++) {
            asistencia_total += asistencia[i][j];
        }
        if (asistencia_total == 0) {
            printf("Ningún alumno asistió a la clase %s\n", classes[i]);
        }
    }
}

// Función para generar informe de horarios sin clases
void informe_horario_sin_clases() {
    limpiarPantalla(); // Limpiar la pantalla antes del informe
    for (int j = 0; j < MAX_SLOTS; j++) {
        int clases_total = 0;
        for (int i = 0; i < MAX_CLASSES; i++) {
            clases_total += asistencia[i][j];
        }
        if (clases_total == 0) {
            printf("No se dictó ninguna clase en %s\n", slots[j]);
        }
    }
}

// Función para generar informe de asistencia por clase
void informe_asistencia_por_clase() {
    limpiarPantalla(); // Limpiar la pantalla antes del informe
    for (int i = 0; i < MAX_CLASSES; i++) {
        printf("Asistencia total en %s: %d\n", classes[i], total_asistencia[i]);
    }
}

// Función para generar informe de ganancias por clase y horario
void informe_ganancias() {
    limpiarPantalla(); // Limpiar la pantalla antes del informe
    double precios[MAX_SLOTS] = {4560, 4560, 5700, 6555, 6555}; // Precios por horario
    double ganancias[MAX_CLASSES] = {0};

    // Calcular ganancias para cada clase
    for (int i = 0; i < MAX_CLASSES; i++) {
        for (int j = 0; j < MAX_SLOTS; j++) {
            ganancias[i] += asistencia[i][j] * precios[j];
        }
        printf("Ganancia total en %s: %.2f\n", classes[i], ganancias[i]);
    }
}

// Función para mostrar el menú de informes
void menu_informes() {
    int opcion;
    do {
        limpiarPantalla(); // Limpiar la pantalla antes de mostrar el menú de informes
        // Mostrar opciones de informes
        printf("\n\033[1;34mSeleccione el informe a visualizar:\033[0m\n");
        printf("1. Ganancias del dia por clase\n");
        printf("2. Clase sin alumnos\n");
        printf("3. Horario sin clases\n");
        printf("4. Asistencia por clase\n");
        printf("5. Salir\n");
        printf("\n\033[1;34mIngrese la opcion deseada:\033[0m ");
        
        // Validar la entrada del usuario
        while (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5) {
            printf("Opción no válida. Intente de nuevo: ");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
        }

        // Ejecutar la opción seleccionada
        switch (opcion) {
            case 1:
                informe_ganancias();
                break;
            case 2:
                informe_clase_sin_alumnos();
                break;
            case 3:
                informe_horario_sin_clases();
                break;
            case 4:
                informe_asistencia_por_clase();
                break;
            case 5:
                printf("Saliendo del menú de informes...\n");
                break;
            default:
                printf("Opción no válida, por favor intente de nuevo.\n");
                break;
        }
        if (opcion != 5) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n'); // Esperar a que el usuario presione Enter
            getchar(); // Capturar el Enter
        }
    } while (opcion != 5); // Repetir hasta que elija salir
}

int main() {
    int opcion;
    do {
        limpiarPantalla(); // Limpiar la pantalla antes de mostrar el menú principal
        // Mostrar el menú principal con opciones de inscripción y generación de informes
        printf("\033[1;32mMenú de inscripciones:\033[0m\n");
        printf("1. Top Ride\n");
        printf("2. Zumba\n");
        printf("3. Entrenamiento\n");
        printf("4. Abdominales\n");
        printf("5. Generar informes\n");
        printf("6. Salir\n");
        printf("\n\033[1;32mIngrese la opcion deseada:\033[0m ");
        
        // Validar la entrada del usuario
        while (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6) {
            printf("Opción no válida. Intente de nuevo: ");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
        }

        // Ejecutar la opción seleccionada
        if (opcion >= 1 && opcion <= 4) {
            inscribir_alumno(opcion - 1); // Inscribir alumno en la clase seleccionada
        } else if (opcion == 5) {
            printf("Generando informes...\n");
            menu_informes(); // Mostrar el menú de informes
        } else if (opcion == 6) {
            printf("Saliendo del programa...\n");
            break;
        } else {
            printf("Opción no válida, por favor intente de nuevo.\n");
        }
        if (opcion != 6) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n'); // Esperar a que el usuario presione Enter
            getchar(); // Capturar el Enter
        }
    } while (opcion != 6); // Repetir hasta que elija salir

    return 0;
}




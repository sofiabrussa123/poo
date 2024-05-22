#include <stdio.h>

void transpuesta2x2();
void determinante3x3();
void adjunta3x3();
void inversa3x3();
void producto2x2();
void resolverSistemaGauss();
void meses30Dias();

int main() {
    int opcion;

    do {
        printf("\nSeleccione una opcion:\n");
        printf("\n");
        printf("1. Mostrar la traspuesta de una matriz 2x2\n");
        printf("2. Mostrar el determinante de una matriz 3x3\n");
        printf("3. Mostrar la matriz adjunta de una matriz 3x3\n");
        printf("4. Mostrar la matriz inversa de una matriz 3x3\n");
        printf("5. Calcular el producto de dos matrices 2x2\n");
        printf("6. Resolver un sistema de 3 ecuaciones con 3 incognitas usando el metodo de Gauss\n");
        printf("7. Mostrar los meses que tienen 30 dias\n");
        printf("8. Salir\n");
        printf("\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                transpuesta2x2();
                break;
            case 2:
                determinante3x3();
                break;
            case 3:
                adjunta3x3();
                break;
            case 4:
                inversa3x3();
                break;
            case 5:
                producto2x2();
                break;
            case 6:
                resolverSistemaGauss();
                break;
            case 7:
                meses30Dias();
                break;
            case 8:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no válida. Intente de nuevo.\n");
        }
    } while (opcion != 8);

    return 0;
}

void transpuesta2x2() {
    int matriz[2][2], transpuesta[2][2];
    int i, j;

    printf("Ingrese los elementos de la matriz 2x2:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    printf("La matriz transpuesta es:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", transpuesta[i][j]);
        }
        printf("\n");
    }
}

void determinante3x3() {
    int matriz[3][3];
    int determinante;

    printf("Ingrese los elementos de la matriz 3x3:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
                 - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
                 + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    printf("El determinante de la matriz es: %d\n", determinante);
}

void obtenerCofactor(int matriz[3][3], int temp[3][3], int p, int q, int n) {
    int i = 0, j = 0;
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < n; columna++) {
            if (fila != p && columna != q) {
                temp[i][j++] = matriz[fila][columna];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinar(int matriz[3][3], int n) {
    int determinante = 0;
    if (n == 1) {
        return matriz[0][0];
    }

    int temp[3][3];
    int signo = 1;

    for (int f = 0; f < n; f++) {
        obtenerCofactor(matriz, temp, 0, f, n);
        determinante += signo * matriz[0][f] * determinar(temp, n - 1);
        signo = -signo;
    }

    return determinante;
}

void obtenerAdjunta(int matriz[3][3], int adj[3][3]) {
    if (3 == 1) {
        adj[0][0] = 1;
        return;
    }

    int signo = 1, temp[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            obtenerCofactor(matriz, temp, i, j, 3);
            signo = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (signo) * (determinar(temp, 3 - 1));
        }
    }
}

void adjunta3x3() {
    int matriz[3][3], adj[3][3];

    printf("Ingrese los elementos de la matriz 3x3:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    obtenerAdjunta(matriz, adj);

    printf("La matriz adjunta es:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void obtenerInversa(int matriz[3][3], float inversa[3][3]) {
    int determinante = determinar(matriz, 3);
    if (determinante == 0) {
        printf("La matriz no es invertible.\n");
        return;
    }

    int adj[3][3];
    obtenerAdjunta(matriz, adj);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inversa[i][j] = adj[i][j] / (float)determinante;
        }
    }
}

void inversa3x3() {
    int matriz[3][3];
    float inversa[3][3];

    printf("Ingrese los elementos de la matriz 3x3:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    obtenerInversa(matriz, inversa);

    printf("La matriz inversa es:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%.2f ", inversa[i][j]);
        }
        printf("\n");
    }
}

void producto2x2() {
    int matriz1[2][2], matriz2[2][2], producto[2][2];
    int i, j, k;

    printf("Ingrese los elementos de la primera matriz 2x2:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Ingrese los elementos de la segunda matriz 2x2:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            producto[i][j] = 0;
            for(k = 0; k < 2; k++) {
                producto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    printf("El producto de las dos matrices es:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", producto[i][j]);
        }
        printf("\n");
    }
}

void gaussJordan(float a[3][4]) {
    int i, j, k;
    float ratio;

    for(i = 0; i < 3; i++) {
        if(a[i][i] == 0.0) {
            printf("Mathematical Error!");
            return;
        }
        for(j = 0; j < 3; j++) {
            if(i != j) {
                ratio = a[j][i] / a[i][i];
                for(k = 0; k < 4; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    for(i = 0; i < 3; i++) {
        a[i][3] = a[i][3] / a[i][i];
        a[i][i] = 1;
    }
}

void resolverSistemaGauss() {
    float a[3][4];
    int i, j;

    printf("Ingrese los coeficientes del sistema de ecuaciones (3x4):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    gaussJordan(a);

    printf("Las soluciones son:\n");
    for(i = 0; i < 3; i++) {
        printf("x%d = %.2f\n", i + 1, a[i][3]);
    }
}

void meses30Dias() {
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;

    printf("Los meses con 30 dias son:\n");
    for(i = 0; i < 12; i++) {
        if(diasPorMes[i] == 30) {
            printf("Mes %d\n", i + 1);
        }
    }
}


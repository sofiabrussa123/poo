#include <stdio.h>

int main() {
    int a, b, c;

    for (int a = 1; a <= 500; a++) {
        for (int b = a; b <= 500; b++) {
            for (int c = b; c <= 500; c++) {
                if (a * a + b * b == c * c) {
                    printf("cateto opuesto: %d, cateto adyacente: %d, hipotenusa :%d\n", a, b, c);
                }
            }
        }
    }

    return 0;
}
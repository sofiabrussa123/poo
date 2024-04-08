#include <stdio.h>

void collatz_conjecture(int num) {
    while (num != 1) {
        printf("%d ", num);
        
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = num * 3 + 1;
        }
    }
    
    printf("1\n");
}

int main() {
    int start_num;
    
    printf("Ingrese un numero para probar la conjetura de Collatz: ");
    scanf("%d", &start_num);
    
    collatz_conjecture(start_num);
    
    return 0;
}
#include<stdio.h>

float porcentaje(float a, float b, float c){
    float per;

    per = (a * b) / c;
        
    return per;
}

int main(void){
    int menu_option;

    do{
        printf("1.Calificacion final\n
        2.descuento del 15% sobre el total de la compra\n
        3.valor absoluto de un número dado como entrada\n
        4.porcentaje de hombres y que porcentaje de mujeres\n
        5.equivalencia en dólares estadounidenses\n
        6.Calcular la FCM para cualquier persona\n
        7.Salir\n"
        );
        scanf("%d", &menu_option);

        switch(menu_option){
            case 1:{
                int i = 0;
                int calificacionp = 0;
                int calificacion = 0;
                float calificacionpf = 0;

                for (i = 0; i < 3; i++) {
                  printf("Ingrese la calificacion de la evaluacion %d\n", i);
                  scanf("%d", &calificacion);
                  calificacionp = calificacionp + calificacion;
                  calificacionpf = (calificacionp / 3) * 0.55;
                }
                printf("Ingrese la calificacion de la  evaluacion final\n");
                scanf("%d", &calificacion);

                float calificationef = calificacion * 0.3;

                printf("Ingrese la calificacion del trabajo final\n");
                scanf("%d", &calificacion);

                int calificaciontpf = calificacion * 0.15;

                float califfinal = calificacionpf + calificationef + calificaciontpf;

                printf("La calificacion final es de: %f", califfinal);

                break;
            }
            case 2:{
                float precio;
                float precioF;

                printf("Cuanto sale lo que compraste?: ");
                scanf("%f", &precio);

                precioF = precio * 0.85;

                printf("Con descuento, la compra sale %2.f", precioF);
                
                break;
            }
            case 3:{
                int num;
                printf("Ingrese un numero: ");
                scanf("%d", &num);

                if(num < 0){
                    num = num + ((num * (-1))* 2);
                }

                printf("El valor absoluto del numero es de: %d", num);

                break;
            }
            case 4:{
                int h;
                int m;
                int t;
                float ph;
                float pm;

                printf("Cuantos hombres son?: ");
                scanf("%d", &h);
                printf("Cuantas mujeres son?: ");
                scanf("%d", &m);

				t = h + m;
                ph = porcentaje(h, 100, t);
                pm = porcentaje(m, 100, t);
                
                printf("Hay un %% %f de hombres y un %% %f de mujeres", ph, pm);
                break;
            }
            case 5:{
                float pesos;
                int tdcambio;
                float dolares;

                printf("Cuantos pesos tenes? ");
                scanf("%f", &pesos);

                printf("Cuanto esta el dolar? ");
                scanf("%d", &tdcambio);

                dolares = pesos / tdcambio;

                printf("Equivalencia en dolares: %2.f", dolares);

                break;
            }
            case 6:{            
                float FCmax;
                float edad;
                float peso;
                int sexo;

                printf("Cuantos años tiene? ");
                scanf("%f", &edad);

                printf("Cuanto pesa en kg? ");
                scanf("%f", &peso);
                
                printf("Es hombre o mujer? (1 || 2)");
                scanf("%d", &sexo);
                
                if(sexo == 1){
                    FCmax = ((210- (0.5 * edad)) - (peso * 0.01)) + 4;
                }else if(sexo == 2){
                    FCmax = (210- (0.5 * edad)) - (peso * 0.01);
                }

                printf("Su FCM es de %2.f", FCmax);
                
                break;
            }
            case 7:{
                printf("Saliendo del Programa");
                printf("\n Adios");

                break;
            }
        }
    }while(menu_option != 7);
    return 0;
}
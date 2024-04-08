#include<stdio.h>

/*
1-Un alumno desea saber cuál será su calificación final, dicha calificación se compone de los siguientes porcentajes:
55% 		del promedio final de sus calificaciones (de sus  3 evaluaciones parciales)
30% 		de la calificación de promedio
15% 		de la calificación de un trabajo final

2-Una tienda ofrece un descuento del 15% sobre el total de la compra, 
y un cliente desea saber cuánto deberá pagar finalmente por su compra.

3-Generar el valor absoluto de un número dado como entrada.
Valor absoluto o módulo1 de un número real es su valor numérico sin tener en cuenta su signo, 
sea este positivo (+) o negativo (-). 
Así, por ejemplo, 3 es el valor absoluto de +3 y de -3.
El valor absoluto está relacionado con las nociones de magnitud, distancia y norma en diferentes contextos matemáticos y físicos.

4-Un maestro desea saber qué porcentaje de hombres y que porcentaje de mujeres hay en un grupo de estudiantes.

5-Dada una cantidad en pesos argentinos, obtener la equivalencia en dólares estadounidenses, 
asumiendo que la unidad cambiaría es un dato desconocido.

6-Calcular la FCM para cualquier persona, sabiendo que ésta es la fórmula de la Frecuencia cardíaca máxima por géneros: 
Para hombres FCmax = ((210 – (0,5 * edad en años)) – 1% del peso) + 4
Para mujeres FCmax = (210 – (0,5 * edad en años)) - 1% del peso
*/

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
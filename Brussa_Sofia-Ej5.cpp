#include<stdio.h>

int main(void){
    int menu_option;

    do{
        printf("1.impuesto por concepto de alquiler\n2.formato hh:mm [am/pm]\n3.invertir su capital\n4.diferencia de edad\n5.Convierta a horas minutos y segundos\n6.Salir\n");
        scanf("%d", &menu_option);

        switch(menu_option){
            case 1:{
                float sueldo;
                float impuesto;
                printf("Ingrese el valor del alquiler: ");
                scanf("%f", &sueldo);
                printf("\n");

                if(sueldo <= 202){
                    impuesto = 0;
                }else if(202 < sueldo <= 607){
                    impuesto = sueldo * 0.05;
                }else if(607 < sueldo <= 1.013){
                    impuesto = sueldo * 0.1;
                }else if(1.013 < sueldo <= 1.418){
                    impuesto = sueldo * 0.15;
                }else if(1.418 < sueldo){
                    impuesto = sueldo * 0.25;
                }
                printf("Se pagara %2.f de impuestos\n", impuesto);

                break;
            }
            case 2:{
                int hora;
                int minutos;
                char *pmam;

                printf("Ingrese la hora: ");
                scanf("%d", &hora);
                printf("\n");
                printf("Ingrese los minutos");
                scanf("%d", &minutos);

                if(hora > 12){
                    hora = hora - 12;
                    pmam = "PM";
                }else pmam = "AM";

                printf("La hora es: %d:%d %s", hora, minutos, pmam);

                break;
            }
            case 3:{
                float DeC; 
                printf("Ingrese el dinero a invertir: ");
                scanf("%f", &DeC);
                printf("\n");

                DeC = DeC + (DeC * 0.02);

                printf("Luego de un mes, tendras %f\n", DeC);

                break;
            }
            case 4:{
                int padre = 50;
                int hijo = 20;
                int cont;

                do{
                    padre = padre + 1;
                    hijo = hijo + 1;
                    cont = cont + 1;
                }while(padre != hijo * 2);

                printf("El padre tardara %d años en tener el doble de edad que su hijo", cont);

                break;
            }
            case 5:{
                int horas, minutos, segundos;
                printf("Ingrese un tiempo en segundos: ");
                scanf("%d", &segundos);

                minutos = segundos / 60; 
                segundos = segundos % 60;

                horas = minutos / 60;
                minutos = minutos % 60;

                printf("En hh:mm:ss es: %d:%d:%d\n", horas, minutos, segundos);

                break;
            }
            case 6:{
                printf("Saliendo...");
                printf("\n Adios");

                break;
            }
        }
    }while(menu_option != 6);
    return 0;
}
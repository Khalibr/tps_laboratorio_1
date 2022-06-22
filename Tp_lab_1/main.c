#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"


int main()
{
    system("color B0");
    int menu;
    int km=0;
    float precioAerolineas;
    float precioLatam;

    float resultadoTarjDebAero;
    float resultadoTarjDebLatam;

    float resultadoTarjCredAero;
    float resultadoTarjCredLatam;

    float resultadoBTCAero;
    float resultadoBTCLatam;

    float unitarioAer = 7200;
    float unitarioLatam = 7600;

do{
    system("cls");
    printf("1.Ingresar Kilometros: (km=%d)\n"
    "2.Ingresar Precio de Vuelo: (Aerolineas=$%.2f, Latam=$%.2f)\n"
    "3.Calcular todos los costos.\n"
    "4.Informar Resultados.\n"
    "5.Carga forzada de datos.\n"
    "6.Salir\n"
    "\nIngrese opcion: ",km,precioAerolineas,precioLatam);
    scanf("%d",&menu);


    switch(menu)
    {
        case 1:
            system("cls");
            printf("Ingresar Kilometros: \n");
            scanf("%d",&km);
        break;

        case 2:
            system("cls");
            printf("- Precio vuelo Aerolineas: \n");
            scanf("%f",&precioAerolineas);

            printf("- Precio vuelo Latam: \n");
            scanf("%f",&precioLatam);
        break;

        case 3:
            system("cls");
            if(precioAerolineas>0 && precioLatam>0){
                    printf("--- Calculando precios de vuelos ---\n");

            resultadoTarjDebAero=priceDebitCrd(precioAerolineas);
            resultadoTarjDebLatam=priceDebitCrd(precioLatam);

            resultadoTarjCredAero=priceCreditCrd(precioAerolineas);
            resultadoTarjCredLatam=priceCreditCrd(precioLatam);

            resultadoBTCAero=priceBTC(precioAerolineas);
            resultadoBTCLatam=priceBTC(precioLatam);
            }
            else{
                printf("*** No hay nada que calcular ***\nIngrese el precio en los vuelos\n");
            }
            system("pause");
        break;

        case 4:
            system("cls");

            printf("Kms ingresados: %d\n",km);

            printf("\nLatam: %.2f\n",precioLatam);
            printf("a. Precio con tarjeta de debito: %.2f\n",resultadoTarjDebLatam);
            printf("b. Precio con tarjeta de credito: %.2f\n",resultadoTarjCredLatam);
            printf("c. precio pagando con bitcoin: %.2f\n",resultadoBTCLatam);
            if(precioLatam>1){
                printf("d. precio unitario: $%.2f\n",unitarioLatam);
            }
            else{
                printf("d. precio unitario: $0\n");
            }

            printf("\nAerolineas: %.2f\n",precioAerolineas);
            printf("a. Precio con tarjeta de debito: %.2f\n",resultadoTarjDebAero);
            printf("b. Precio con tarjeta de credito: %.2f\n",resultadoTarjCredAero);
            printf("c. precio pagando con bitcoin: %.2f\n",resultadoBTCAero);
            if(precioAerolineas>0){
                printf("d. precio unitario: $%.2f\n",unitarioAer);
            }
            else{
                printf("d. precio unitario: $0\n");
            }


            printf("\nLa diferencia de precio es: $%.2f\n",difPrecio(precioAerolineas,precioLatam));
            system("pause");
        break;

        case 5: //hardcodeo
            system("cls");
            km=7090;
            precioAerolineas=162965;
            resultadoTarjDebAero=priceDebitCrd(162965);
            resultadoTarjCredAero=priceCreditCrd(162965);
            resultadoBTCAero=priceBTC(162965);
            precioLatam=159339;
            resultadoTarjDebLatam=priceDebitCrd(159339);
            resultadoTarjCredLatam=priceCreditCrd(159339);
            resultadoBTCLatam=priceBTC(159339);

            printf("Kilometros ingresados: %d km\n",km);
            printf("\nLatam: $%.2f\n",precioLatam);
            printf("a. Precio con tarjeta de debito: $%.2f\n",resultadoTarjDebLatam);
            printf("b. Precio con tarjeta de credito: $%.2f\n",resultadoTarjCredLatam);
            printf("c. precio pagando con bitcoin: %.2f BTC\n",resultadoBTCLatam);
            printf("d. precio unitario: $%.2f\n",unitarioLatam);


            printf("\nPrecio Aerolineas: $%.2f\n",precioAerolineas);
            printf("a. Precio con tarjeta de debito: $%.2f\n",resultadoTarjDebAero);
            printf("b. Precio con tarjeta de credito: $%.2f\n",resultadoTarjCredAero);
            printf("c. precio pagando con bitcoin: %.2f BTC\n",resultadoBTCAero);
            printf("d. precio unitario: $%.2f\n",unitarioAer);

            printf("\nLa diferencia de precio es: $%.2f\n",difPrecio(precioAerolineas,precioLatam));

            system("pause");

        break;
        case 6:
        break;



    }
}while(menu!=6);




    return 0;
}

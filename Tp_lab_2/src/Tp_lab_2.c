/*
 ============================================================================
 Name        : Tp_lab_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "passenger.h"
#include "tipoClase.h"

#define len 10
#define lenClass

int main(void) {
	setbuf(stdout,NULL);

	char salir = 'n';
	int proximoId=1000;

	ePassenger pasajeros[len];
    /*eClassType tipoclase[lenClass]={
    		{3000, "Primera Clase"},
    		{3001, "Ejecutivo"},
    		{3002, "Premium"},
    };*/


	initPassenger(pasajeros, len);

	hardcodeoAerolineas(pasajeros, len, 6,&proximoId);

	do{
	    switch(menuAerolineas()){
	    		case 1:
	    			if(addPassenger(pasajeros, len, &proximoId)){
	    				printf("Empleado cargado con exito!\n");
	    			}
	    			else{
	    				printf("No se pudo cargar el empleado :(\n");
	    			}
	    			break;
	    		case 2:
	    			removePassenger(pasajeros, len);
	    			break;
	    		case 3:
	    			findPassengerById(pasajeros, len);
	    			break;
	    		case 4:
	    			switchSubMenu(pasajeros,len);
	    			break;
	    		case 5:
	    			forPrintPassenger(pasajeros,len);
	    			break;
	    		case 20:
	    			printf("Desea salir s/n: ");
	    			fflush(stdin);
	    			scanf("%c",&salir);
	    			break;

	    	}
	    }while(salir != 's');




	return EXIT_SUCCESS;
}

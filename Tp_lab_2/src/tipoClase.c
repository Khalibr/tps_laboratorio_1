/*
 * tipoClase.c
 *
 *  Created on: 13 may. 2022
 *      Author: Santt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passenger.h"
#include "tipoClase.h"

int cargarDescripcion(eClassType tipoClase[], int tam, int id, char descr[]){
	int todoOk=0;
	if(tipoClase!=NULL && tam >0 && descr!=NULL){
		for(int i=0;i<tam;i++){
			if(tipoClase[i].id == id){ //encuentro id por ref
				strcpy(descr,tipoClase[i].descripcion);
				todoOk=1;
				break;
			}
		}

	}

	return todoOk;
}


int listarTipoClase(eClassType tipoClase[],int tam){
	int todoOk=0;

	if(tipoClase!=NULL && tam>0){
		printf("--------------------------------------------------\n");
		printf("************	  CLASE VUELOS	  ***************\n");
		printf("--------------------------------------------------\n\n");

		for(int i=0;i<tam;i++){
			printf("%d  %15s\n",tipoClase[i].id,tipoClase[i].descripcion);
		}

	}

	return todoOk;
}

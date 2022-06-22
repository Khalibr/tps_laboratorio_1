/*
 * passenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: Santt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passenger.h"

#define CADAUX 100
#define len 10


int initPassenger(ePassenger vec[],int tam){
	int todoOk=0;
		if(vec!=NULL && tam>0){
			for(int i=0;i<tam;i++){//recorro el array para inicializar
				vec[i].isEmpty=1;//si la struct no tiene datos
			}					//esta vacio-1-verdadero.
			todoOk=1;
		}

	return todoOk;
}

int hardcodeoAerolineas(ePassenger vec[],int tam,int cant, int* pNextId){
	int todoOk=0;
	ePassenger pasajeros[10]={
		{0,"Juan","Gomez",200.00,"FirstClass",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Alberto","Solari",200.00,"Ejecutive",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Maria","Paz",200.00,"Premium",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Lisandro","Fredo",200.00,"FirstClass",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Malena","Gil",200.00,"Premium",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Gonzalo","Nashi",200.00,"Ejecutive",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Ramiro","Fracatelli",200.00,"FirstClass",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Ivan","Palo",200.00,"Premium",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Cristian","Misa",200.00,"FirstClass",1,1,0}, //el 0 efectua que el campo isEmpty esta cargado
		{0,"Luna","Llena",200.00,"Ejecutive",1,0,0}, //el 0 efectua que el campo isEmpty esta cargado
		};
		if(vec!=NULL && pNextId!=NULL && tam>0 && tam<=10 && cant<=tam){
			for(int i=0;i<cant;i++){//el cant me indica cuantos datos debo mostrar
					vec[i]=pasajeros[i]; //igualo arrays paralelos
										//el que llega por parametro con el que esta aca dentro
					vec[i].id=*pNextId;
					(*pNextId)++;
			}
			todoOk=1;
		}


	return todoOk;
}



int menuAerolineas(){
	int opcion;
	printf("-----------------------------------------------------------------------------------------------------------\n");
	printf("Div I - Julian Medina - TP_02\n");
	printf("*****************************		AEROLINEAS	 	*************************************\n");
	printf("-----------------------------------------------------------------------------------------------------------\n\n");
	printf("1. Alta pasajeros\n");
	printf("2. Baja pasajeros\n");
	printf("3. Modificar pasajeros\n");
	printf("4. Informes pasajeros\n");
	printf("5. Mostrar pasajeros\n");
	printf("20. Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);

	scanf("%d", &opcion);
	printf("\n");

	return opcion;
}

int buscarLibre(ePassenger vec[],int tam, int* pIndex){
	int todoOk=0;

			if(vec!=NULL && pIndex!=NULL && tam>0){
				*pIndex=-1;//precargo el puntero con -1

				for(int i=0;i<tam;i++){
					if(vec[i].isEmpty){
						*pIndex=i; //cargo el puntero con el lugar libre
					}
				}
				todoOk=1;
			}

	return todoOk;
}

int buscarPasajero(ePassenger vec[],int tam,int id, int* pIndex){
	int todoOk=0;

				if(vec!=NULL && pIndex!=NULL && tam>0){
					*pIndex=-1;//precargo el puntero con -1

					for(int i=0;i<tam;i++){
						if(!vec[i].isEmpty && vec[i].id==id){
							*pIndex=i; //cargo el puntero con el lugar libre
							break;
						}
					}
					todoOk=1;
				}

	return todoOk;
}

int addPassenger(ePassenger vec[],int tam, int* pNextId){
	int todoOk=0;
	int indice;
	ePassenger nuevoPasajero;

		if(vec!=NULL && pNextId!=NULL && tam>0){
			printf("************************************************\n");
			printf("			ALTA PASAJERO			\n");
			printf("------------------------------------------------\n\n");
			buscarLibre(vec, tam, &indice);

			if(indice== -1){
				printf("No hay lugar disponible en el sistema\n");
			}
			else{
				nuevoPasajero.id = *pNextId;
				printf("Ingrese Nombre: ");
				fflush(stdin);
				gets(nuevoPasajero.name);

				printf("Ingrese Apellido: ");
				fflush(stdin);
				gets(nuevoPasajero.lastname);

				printf("Ingrese precio del vuelo: ");
				scanf("%f,",&nuevoPasajero.price);

				printf("Ingrese codigo de vuelo: ");
				fflush(stdin);
				gets(nuevoPasajero.flycode);

				printf("Ingrese tipo de pasajero: ");
				scanf("%d",&nuevoPasajero.typePassenger);

				printf("Ingrese estado de vuelo: "); //sacarlo luego
				scanf("%d",&nuevoPasajero.statusFlight);

				printf("\n\n------------------------------------------------\n\n");

				nuevoPasajero.isEmpty=0;

				vec[indice] = nuevoPasajero;

				(*pNextId)++;
				todoOk=1;
			}

		}

	return todoOk;
}

void printPassengerForm(ePassenger pas){
	printf("ID: %d\n",pas.id);
	printf("Nombre: %s\n",pas.name);
	printf("Apellido: %s\n",pas.lastname);
	printf("Precio de vuelo: %f\n",pas.price);
	printf("Codigo: %s\n",pas.flycode);
	printf("Tipo de pasaje: %d\n",pas.typePassenger);
	printf("Estado de vuelo: %d\n",pas.statusFlight);
}

void printPassengerLine(ePassenger vec){

	printf("%4d  %15s	%15s	 	%5.4f    %12s       %4d	  %4d\n",
			vec.id,
			vec.name,
			vec.lastname,
			vec.price,
			vec.flycode,
			vec.typePassenger,
			vec.statusFlight);
}

int forPrintPassenger(ePassenger vec[],int tam){
	int todoOk=0;
	int flag=1;

		if(vec!=NULL && tam>0 ){
			printf("----------------------------------------------------------------------------------------------------------------------\n\n");
			printf("		****************** 		LISTA DE PASAJEROS 		*********************\n\n");
			printf("ID	 	NOMBRE 		APELLIDO	PRECIO 		CODIGO    	TIPO 	  ESTADO\n");
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			for(int i=0;i<tam;i++){
				if(!vec[i].isEmpty){ //valido antes de mostrar si esta vacio
					printPassengerLine(vec[i]);
					flag=0;
				}

			}
			if(flag){
				printf("			No hay pasajeros cargados\n");
			}
			todoOk=1;
		}

	return todoOk;
}


int subMenuInforme(){
	int opcion;

		printf("--------------------------------------------------------------------------\n\n");
		printf("***************** 		INFORMES		 *****************\n");
		printf("--------------------------------------------------------------------------\n\n");
		printf("1. Por apellido y tipo de pasajero\n");
		printf("2. Por total y promedio de precio\n");
		printf("3. Por codigo y estado\n\n");
		printf("5. Regresar al menu principal\n\n");
		printf("Ingrese opcion: ");
		fflush(stdin);


		scanf("%d", &opcion);

	return opcion;
}

void switchSubMenu(ePassenger vec[],int tam){

	switch(subMenuInforme()){
		case 1:
			printf("ENTRE AL 1");
		break;
		case 2:
			printf("ENTRE AL 2");
		break;
		case 3:
			printf("ENTRE AL 3");
		break;
	}
}


int removePassenger(ePassenger vec[],int tam){
	int todoOk=0;
	int indice;
	int id;
	char confirma;

		if(vec!=NULL && tam>0){
			forPrintPassenger(vec, tam);

			printf("----------------------------------------------------------\n\n");
			printf("***************** BAJA PASAJERO *****************\n\n");
			printf("----------------------------------------------------------\n\n");

			printf("Ingrese ID: ");
			scanf("%d",&id);

			if(buscarPasajero(vec, tam, id, &indice)){
				if(indice==-1){
					printf("No existe empleado con id: %d en el sistema\n",id);
				}
				else{
					printPassengerForm(vec[indice]);
					printf("Confirma baja?: ");
					fflush(stdin);
					scanf("%c",&confirma);
					if(confirma=='s' || confirma=='S'){
						vec[indice].isEmpty=1;
						printf("Baja exitosa!!!\n");
					}
					else{
						printf("Baja cancela por el usuario\n");
					}
				}
				todoOk=1;
			}


		}

	return todoOk;


}

int submenuModificarPasajero(){
	int opcion;
	printf("\n-------------- CAMPO A MODIFICAR -----------------\n\n");
	printf("1. Modificar Nombre\n");
	printf("2. Modificar Apellido\n");
	printf("3. Modificar Precio\n");
	printf("4. Modificar Codigo\n");
	printf("5. Modificar Tipo de Pasaje\n");
	printf("6. Modificar Estado de vuelo\n");
	printf("7. Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);

	scanf("%d", &opcion);

	return opcion;
}

int findPassengerById(ePassenger vec[],int tam){
	int todoOk=0;
	int indice;
	int id;
	char auxName[CADAUX];
	char auxLastName[CADAUX];
	float price;
	char flyCode[CADAUX];
	//int typePassenger;
	int statusFlight;



		if(vec!=NULL && tam>0){
			forPrintPassenger(vec, tam);

			printf("---------------------------------------------\n");
			printf("*************** MODIFICAR EMPLEADO ***************\n");
			printf("---------------------------------------------\n\n");

			printf("Ingrese ID: ");
			scanf("%d",&id);

			if(buscarPasajero(vec, tam, id, &indice)){
				if(indice==-1){
					printf("No existe empleado con id: %d en el sistema\n",id);
				}
				else{
					printPassengerForm(vec[indice]);

					switch(submenuModificarPasajero()){
						case 1:
							printf("Ingrese nuevo nombre: ");
							fflush(stdin);
							gets(auxName);
							//hacer validacion
							strcpy(vec[indice].name,auxName);
							printf("Nombre modificado con exito!\n");
							break;
						case 2:
							printf("Ingrese nuevo Apellido: ");
							fflush(stdin);
							gets(auxLastName);
							strcpy(vec[indice].lastname,auxLastName);
							//hacer validacion
							printf("Apellido modificado con exito!\n");
							break;
						case 3:
							printf("Ingrese nueva precio: ");
							scanf("%f",&price);
							//hacer validacion
							vec[indice].price = price;
							printf("Precio modificado con exito!\n");
							break;
						case 4:
							printf("Ingrese nueva codigo: ");
							fflush(stdin);
							gets(flyCode);
							strcpy(vec[indice].flycode,flyCode);
							//hacer validacion
							printf("Codigo modificado con exito!\n");
							break;
						case 5:
							printf("Ingrese nueva tipo de pasaje: ");
							scanf("%d",&statusFlight);
							vec[indice].statusFlight = statusFlight;
							printf("Tipo de pasaje modificado con exito!\n");
							break;
						/*case 6:
							listarSectores(sectores, tamSec);
							printf("Ingrese nuevo id sector: ");
							scanf("%d",&sector);
							//hacer validacion
							while(!validarSector(sectores, tamSec, sector)){
								printf("Id invalido, Reingrese id sectores: ");
								scanf("%d",&sector);
							}
							vec[indice].idSector = sector;
							printf("Sector modificado con exito!\n");
							break;*/
					}

				}
				todoOk=1;
			}


		}

	return todoOk;

}



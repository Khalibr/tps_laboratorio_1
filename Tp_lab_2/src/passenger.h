/*
 * passenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: Santt
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[15];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}ePassenger;



#endif /* PASSENGER_H_ */


int menuAerolineas();


int buscarLibre(ePassenger vec[],int tam, int* pIndex);
int buscarPasajero(ePassenger vec[],int tam,int id, int* pIndex);


int hardcodeoAerolineas(ePassenger vec[],int tam,int cant, int* pNextId);

int initPassenger(ePassenger vec[],int tam);//2

int addPassenger(ePassenger vec[],int tam, int* pNextId);
int removePassenger(ePassenger vec[],int tam);

void printPassengerForm(ePassenger pas);
void printPassengerLine(ePassenger vec);
int printPassenger(ePassenger vec[], int tam);
int forPrintPassenger(ePassenger vec[],int tam);


int findPassengerById(ePassenger vec[],int tam);

//informes
int subMenuInforme();
void switchSubMenu(ePassenger vec[],int tam);

//ordenar e info







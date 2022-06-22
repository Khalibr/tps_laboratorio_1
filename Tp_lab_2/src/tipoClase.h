/*
 * tipoClase.h
 *
 *  Created on: 13 may. 2022
 *      Author: Santt
 */

#ifndef TIPOCLASE_H_
#define TIPOCLASE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passenger.h"


typedef struct{
	int id;
	char descripcion[15];

}eClassType;


#endif /* TIPOCLASE_H_ */

int cargarDescripcion(eClassType tipoClase[], int tam, int id, char descr[]);//1
int listarTipoClase(eClassType tipoClase[],int tam);//2
//int buscarTipoClase(eClassType vec[],int tam,int id, int* pIndex);//3
//int validarTipoClase(eClassType vec[],int tam,int id);//4

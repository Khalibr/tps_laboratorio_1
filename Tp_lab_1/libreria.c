#include "libreria.h"

float priceDebitCrd(float num1)
{
    float resultado;

    resultado = num1-num1*10/100;


    return resultado;
}

float priceCreditCrd(float num1)
{
    float resultado;
    resultado = num1+num1*25/100;
    return resultado;
}

float priceBTC(float num1)
{
    float resultado;
    resultado = num1 / 4606954.55;
    return resultado;
}

float difPrecio (float num1,float num2)
{
    float resultado;
    resultado = num1 - num2;
    return resultado;
}

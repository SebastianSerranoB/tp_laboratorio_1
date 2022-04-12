/*
 * arithmeticCalculus.c
 *
 * Cuerpo de funciones de calculo aritmetico utilzadas en TP1, laboratorio de programacion 1, UTN 2022.
 *  Created on: 10 abr 2022
 *  Autor: SEBASTIAN SERRANO BELLOSO
 *
 */

#include <stdlib.h>
#include <stdio.h>

float calculatePrice(float price, float percentaje)
{
	float finalPrice;

	finalPrice = price * percentaje;

	return finalPrice;
}


float divide(float operatorA, float operatorB)
{
	float result;

	result = operatorA / operatorB;

	return result;
}


float calculateDifference(float minuend, float subtrahend)
{
	float result;

	result = minuend - subtrahend;
	if(result < 0)
	{
		result = result * -1;
	}

	return result;
}

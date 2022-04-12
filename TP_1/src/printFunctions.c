/*
 * printFunctions.c
 *Cuerpo de funciones print utilzadas en TP1, laboratorio de programacion 1, UTN 2022.
 *  Created on: 10 abr 2022
 *  Autor: SEBASTIAN SERRANO BELLOSO
 *
 */

#include <stdlib.h>
#include <stdio.h>

void printAerolineas(float price, float debit, float credit, float bitcoin, float unitPrice)
{
	printf("Precio Aerolineas: $%.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con bitcoin: %.3f BTC\nd) Mostrar precio unitario: $ %.2f\n"
	, price, debit, credit, bitcoin, unitPrice);
}


void printLatam(float price, float debit, float credit, float bitcoin, float unitPrice)
{
	printf("\nPrecio Latam: $%.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con bitcoin: %.3f BTC\nd) Mostrar precio unitario: $ %.2f\n"
		, price, debit, credit, bitcoin, unitPrice);
}


/*
 * getterFunctions.c
 *
 *	Cuerpo de funciones getter utilzadas en TP1, laboratorio de programacion 1, UTN 2022.
 *  Created on: 10 abr 2022
 *  Autor: SEBASTIAN SERRANO BELLOSO
 *
 */


#include <stdlib.h>
#include <stdio.h>

int mainMenu(float km, float aerolineas, float latam)
{
	int opcionRetornada;
	printf("\n\n 1- Ingresar Kilómetros:( km = %.2f) \n 2- Ingresar precio de vuelos:(Aerolineas = %.2f, Latam = %.2f)"
			"\n 3- Calcular costos. \n 4- Informar resultados. \n 5- Carga forzada de datos. \n 6- Salir\n Opcion ingresada: ", km, aerolineas, latam);
	scanf("%d", &opcionRetornada);

	return opcionRetornada;
}


char subMenu(void)
{
	char returnOption;
	printf("\n A- Ingresar precio de vuelo para empresa Aerolineas: " "\n L- Ingresar precio de vuelo para empresa Latam: " "\n S- Volver al menu principal." "\n Opcion ingresada: ");
	fflush(stdin);
	scanf("%c", &returnOption);
	while(returnOption != 'A' && returnOption != 'L' && returnOption != 'S')
	{
		printf("\nError, reingrese una opcion valida: ");
		fflush(stdin);
		scanf("%c", &returnOption);
	}

	return returnOption;
}


float getFloat(int min, int max, char type)
{
	float enteredFloat;


	if(type == 'K')
	{
		printf("\nIngrese la distancia en kilometros: ");
	}
	else
	{
		if(type == 'A')
		{
			printf("\nIngrese el precio de vuelo para la empresa Aerolineas: ");
		}
		else
		{
			printf("\nIngrese el precio de vuelo para la empresa Latam: ");
		}
	}
	scanf("%f", &enteredFloat);
	while(enteredFloat  < min || enteredFloat > max)
	{
		printf("\nError, reingrese el numero: ");
		scanf("%f", &enteredFloat);
	}

	return enteredFloat;
}

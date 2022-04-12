/*
 ============================================================================
 Name        : TP_1.c
 Autor       : Serrano Belloso Sebastian
 Division    : k-1
 UTN FRA 2022 - Laboratorio de Programacion 1- Trabajo practico 1.
 Fecha de entrega: 16/04/2022.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arithmeticCalculus.h"
#include "getterFunctions.h"
#include "printFunctions.h"


int main(void)
{
	setbuf(stdout, NULL);
	int enteredOption, subMenuOption, calculationsFlag;
	float enteredKilometers, enteredAerolineasPrice, enteredLatamPrice;
	float aerolineasDebit, aerolineasCredit, aerolineasBitcoin, aerolineasUnitPrice;
	float latamDebit, latamCredit, latamBitcoin, latamUnitPrice, priceDifference;

	enteredKilometers = 0, enteredAerolineasPrice = 0, enteredLatamPrice = 0;
	calculationsFlag = 0;

	do{
		enteredOption = mainMenu(enteredKilometers, enteredAerolineasPrice, enteredLatamPrice);
		switch(enteredOption)
		{
		case 1:
			enteredKilometers = getFloat(300, 150000, 'K');
			break;
		case 2:
			do{
				subMenuOption = subMenu();
				switch(subMenuOption)
				{
				case 'A':
					enteredAerolineasPrice = getFloat(10000, 1000000, 'A');
					break;
				case 'L':
					enteredLatamPrice = getFloat(10000, 1000000, 'L');
					break;
				case 'S':
					printf("\nHas salido del submenu");
					break;
				}
			}while(subMenuOption != 'S');
			break;
		case 3:
			if(enteredKilometers != 0 && enteredAerolineasPrice != 0 && enteredLatamPrice != 0)
			{
				aerolineasDebit = calculatePrice(enteredAerolineasPrice, 0.9);
				aerolineasCredit = calculatePrice(enteredAerolineasPrice, 1.25);
				aerolineasBitcoin = divide(enteredAerolineasPrice, 4606954.55);
				aerolineasUnitPrice = divide(enteredAerolineasPrice, enteredKilometers);

				latamDebit = calculatePrice(enteredLatamPrice, 0.9);
				latamCredit = calculatePrice(enteredLatamPrice, 1.25);
				latamBitcoin = divide(enteredLatamPrice, 4606954.55);
				latamUnitPrice = divide(enteredLatamPrice, enteredKilometers);

				priceDifference = calculateDifference(enteredAerolineasPrice, enteredLatamPrice);

				calculationsFlag = 1;
				printf("\nCalculo de tarifas finalizado.");
			}
			else
			{
				printf("\nError, debe ingresar kilometros y ambos precios antes de calcular tarifas.(Boton 1 y 2)");
			}
			break;
		case 4:
			if(calculationsFlag == 1)
			{
				printf("\nKMs Ingresados: %.2f km\n\n", enteredKilometers);
				printAerolineas(enteredAerolineasPrice, aerolineasDebit, aerolineasCredit, aerolineasBitcoin, aerolineasUnitPrice);
				printLatam(enteredLatamPrice, latamDebit, latamCredit, latamBitcoin, latamUnitPrice);

				if(priceDifference != 0){
					printf("\nLa diferencia de precio es: $ %.2f\n", priceDifference);
				}
				else
				{
					printf("\nEl precio es el mismo para ambas empresas.");
				}
			}
			else
			{
				printf("\nError, debe calcular los gastos previamente(boton 3).");
			}
			break;
		case 5:
				enteredKilometers = 7090;
				enteredAerolineasPrice= 162965;
				enteredLatamPrice = 159339;
			break;
		case 6:
				printf("\nHas salido del menu.");
			break;}
	}while(enteredOption != 6);

	return EXIT_SUCCESS;
}


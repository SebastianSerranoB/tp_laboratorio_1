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
#include "utn.h" //library created for TP_1.

int main(void){
	setbuf(stdout, NULL);
	//declare local variables
	int enteredOption, subMenuOption;
	float enteredKilometers, enteredAerolineasPrice, enteredLatamPrice;
	enteredKilometers = 0, enteredAerolineasPrice = 0, enteredLatamPrice = 0;
	float aerolineasDebit, aerolineasCredit, aerolineasBitcoin, aerolineasUnitPrice;
	float latamDebit, latamCredit, bitcoinLatam, latamUnitPrice;
	float priceDifference;

	do{ //do-while cicle begins.
		enteredOption = mainMenu(enteredKilometers, enteredAerolineasPrice, enteredLatamPrice);// calls mainMenu function, it shows a menu, asks and gets chosen option used in do-while cicle.
		switch(enteredOption){//options switch begins. //switch cases begin, each option entered is a case.
		case 1: enteredKilometers = getFloat(1, 150000, 'K');
			break;
		case 2: do{	subMenuOption = subMenu();//subMenu() function shows submenu for choosing aeroline prices.
				switch(subMenuOption){
				case 'A': enteredAerolineasPrice = getFloat(1, 1000000, 'A');
					break;
				case 'L': enteredLatamPrice = getFloat(1, 1000000, 'L');
					break;
				case 'S': printf("\nHas salido del submenu");
					break;}
					}while(subMenuOption != 'S');
			break;
		case 3: if(enteredKilometers != 0 && enteredAerolineasPrice != 0 && enteredLatamPrice != 0){
				aerolineasDebit = calculatePrice(enteredAerolineasPrice, 0.9);
				aerolineasCredit = calculatePrice(enteredAerolineasPrice, 1.25);
				aerolineasBitcoin = divide(enteredAerolineasPrice, 4606954.55 );
				aerolineasUnitPrice = divide(enteredAerolineasPrice, enteredKilometers);

				}else{printf("\nError,ingrese kilometros y ambos precios para calcular tarifas.");}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default: printf("\nError, reingrese una opcion valida: ");
			break;}
	}while(enteredOption != 6); //while 6 is not the entered option, while cicle keeps going, "6" is for exit.
	return EXIT_SUCCESS;}


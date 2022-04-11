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

int main(void){setbuf(stdout, NULL);
	int enteredOption, subMenuOption, calculationsFlag; //declare local variables
	float enteredKilometers, enteredAerolineasPrice, enteredLatamPrice; //entry variables
	float aerolineasDebit, aerolineasCredit, aerolineasBitcoin, aerolineasUnitPrice, latamDebit, latamCredit, latamBitcoin, latamUnitPrice, priceDifference;  //calculation variables.
	enteredKilometers = 0, enteredAerolineasPrice = 0, enteredLatamPrice = 0; //initialize entry variables in 0 to show status in menu.
	calculationsFlag = 0; //initialize calculations flag.

	do{ enteredOption = mainMenu(enteredKilometers, enteredAerolineasPrice, enteredLatamPrice);//do-while cicle begins/calls mainMenu function, it shows an options menu, returning while condition option. The parameters are also printed in console
		switch(enteredOption){//options switch cases begin, each option entered is a case.
		case 1: enteredKilometers = getFloat(300, 150000, 'K'); //sends a minimun and maximum range and a char that indicates the type.
			break;
		case 2: do{	subMenuOption = subMenu();//subMenu() function shows submenu for choosing aeroline prices.
				switch(subMenuOption){
				case 'A': enteredAerolineasPrice = getFloat(10000, 1000000, 'A');
					break;
				case 'L': enteredLatamPrice = getFloat(10000, 1000000, 'L');
					break;
				case 'S': printf("\nHas salido del submenu");
					break;}
					}while(subMenuOption != 'S');  //while "S" is not the entered option, while cicle(subMenu) keeps going, "S" is for exit.
			break;
		case 3: if(enteredKilometers != 0 && enteredAerolineasPrice != 0 && enteredLatamPrice != 0){ //calculations with functions.
				aerolineasDebit = calculatePrice(enteredAerolineasPrice, 0.9); //sends flight price and debit discount.
				aerolineasCredit = calculatePrice(enteredAerolineasPrice, 1.25); //sends flight price and credit interest.
				aerolineasBitcoin = divide(enteredAerolineasPrice, 4606954.55); // sends flight price and bitcoin price in $ARS.
				aerolineasUnitPrice = divide(enteredAerolineasPrice, enteredKilometers); // divides flight price and kilometers to get unit price.
				latamDebit = calculatePrice(enteredLatamPrice, 0.9);
				latamCredit = calculatePrice(enteredLatamPrice, 1.25);
				latamBitcoin = divide(enteredLatamPrice, 4606954.55);
				latamUnitPrice = divide(enteredLatamPrice, enteredKilometers);
				priceDifference = calculateDifference(enteredAerolineasPrice, enteredLatamPrice); // substracts both flight prices returning the difference.
				calculationsFlag = 1; //if calculations are done, flag goes up.
				printf("\nCalculo de tarifas finalizado.");}
				else{printf("\nError, debe ingresar kilometros y ambos precios antes de calcular tarifas.(Boton 1 y 2)");}
			break;
		case 4: if(calculationsFlag == 1){  //flag check
				printf("\nKMs Ingresados: %.2f km\n\n", enteredKilometers);
				printAerolineas(enteredAerolineasPrice, aerolineasDebit, aerolineasCredit, aerolineasBitcoin, aerolineasUnitPrice);
				printLatam(enteredLatamPrice, latamDebit, latamCredit, latamBitcoin, latamUnitPrice);
				if(priceDifference != 0){ // checks for difference in prices, if they have the same value, it shows that in console.
					printf("\nLa diferencia de precio es: $ %.2f\n", priceDifference);}
				else{printf("\nEl precio es el mismo para ambas empresas.");}}
				else{printf("\nError, debe calcular los gastos previamente(boton 3).");}
			break;
		case 5: enteredKilometers = 7090; //forced entry variables
				enteredAerolineasPrice= 162965;
				enteredLatamPrice = 159339;
			break;
		case 6: printf("\nHas salido del menu.");
			break;}
	}while(enteredOption != 6); //while "6" is not the entered option, while cicle(Main menu) keeps going, "6" is for exit.
	return EXIT_SUCCESS;}


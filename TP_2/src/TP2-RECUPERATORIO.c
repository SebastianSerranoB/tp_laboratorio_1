/*
 ============================================================================
 Name        : TP2-RECUPERATORIO.c

 ALUMNO      : Serrano Belloso Sebastian
 DNI         : 42810404
 DIVISION	 : K-1

LABORATORIO DE PROGRAMACION 1
TRABAJO PRACTICO N-2
UTN-FRA -- 2022 --
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arrayPassenger.h"
#include "funcionesAlumno.h"

int main(void)
{
	setbuf(stdout,NULL);

	sPassenger passenger[MAX_PASSENGERS];
	sFlight flight[MAX_FLIGHTS];
	int idPassenger;
	int mainMenuOption;
	idPassenger = 0;

	initPassengers(passenger, MAX_PASSENGERS);
	initFlights(flight, MAX_FLIGHTS);

	do{
		mainMenuOption = menu(1, 6,"\n\n=====================  MAIN MENU  =====================\n"
									"\n1- ADD\n2- MODIFY\n3- REMOVE\n4- PRINT MENU\n5- FORCED ENTRY\n\n6- EXIT"
									"\n\n=======================================================");
		switch(mainMenuOption)
		{
			case 1:
				idPassenger++;
				if(add(passenger, MAX_PASSENGERS, idPassenger) == -1){
					idPassenger--;
				}
			break;
			case 2:
				modifyPassenger(passenger, MAX_PASSENGERS, flight, MAX_FLIGHTS);
				break;
			case 3:
				removeOption(passenger, MAX_PASSENGERS, flight, MAX_FLIGHTS);
				break;
			case 4:
				printMenu(passenger, MAX_PASSENGERS, flight, MAX_FLIGHTS);
				break;
			case 5:
				idPassenger++;
				if(forcedEntry(passenger, MAX_PASSENGERS, idPassenger) > -1){
					idPassenger += 5;
				}
				else{
					idPassenger--;
				}
				break;

			case 6:
				printf("\nEXITED MAIN MENU");
				break;
		}

	}while(mainMenuOption != 6);


	return EXIT_SUCCESS;
}


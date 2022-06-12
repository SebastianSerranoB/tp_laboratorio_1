#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* passengerAux;
	char nombreAux[51];
	char apellidoAux[51];
	char precioAux[51];
	char tipoPasajeroAux[51];
	char codigoVueloAux[51];
	char idAux[10];
	char estadoVueloAux[21];
	int rtn;
	int cant;
	rtn = -1;

	passengerAux = Passenger_new();


	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux, nombreAux, apellidoAux, precioAux, codigoVueloAux, tipoPasajeroAux, estadoVueloAux);

		do{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux, nombreAux, apellidoAux, precioAux, codigoVueloAux, tipoPasajeroAux, estadoVueloAux);

			if(cant == 7)
			{
				passengerAux = Passenger_newParametros(idAux, nombreAux, apellidoAux, precioAux, codigoVueloAux, tipoPasajeroAux, estadoVueloAux);

				if(passengerAux != NULL)
				{
					ll_add(pArrayListPassenger, passengerAux);
					rtn = 0;
				}

			}
			else
			{
				break;
			}

		}while(feof(pFile) == 0);

	}


    return rtn;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* auxPassenger;
	int cant;
	int rtn;
	rtn = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do{
			auxPassenger = Passenger_new();
			cant = fread(auxPassenger,sizeof(Passenger),1,pFile);
			if(auxPassenger != NULL && cant == 1)
			{
				ll_add(pArrayListPassenger, auxPassenger);
				rtn = 0;
			}

		}while(feof(pFile) == 0);

	}

	return rtn;
}

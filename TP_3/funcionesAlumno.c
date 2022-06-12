/*
 * funcionesAlumno.c
 *
 *  Created on: 8 jun 2022
 *      Author: admin
 */

#include "Passenger.h"
#include "funcionesAlumno.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
  TIPO PASAJERO
-FirstClass
-ExecutiveClass
-EconomyClass


estado vuelo
En Horario -  Aterrizado - En Vuelo -Demorado
 * */

void charTipoPasajero(int* tipoInt, char* tipoChar)
{
	switch(*tipoInt)
	{
		case 1:
			strcpy(tipoChar, "FirstClass");
			break;
		case 2:
			strcpy(tipoChar, "ExecutiveClass");
			break;
		case 3:
			strcpy(tipoChar, "EconomyClass");
			break;
	}

}

void charEstadoVuelo(int* estadoInt, char* estadoChar)
{
	switch(*estadoInt)
	{
	case 1:
		strcpy(estadoChar, "En Horario");
		break;
	case 2:
		strcpy(estadoChar, "Aterrizado");
			break;
	case 3:
		strcpy(estadoChar, "En Vuelo");
			break;
	case 4:
		strcpy(estadoChar, "Demorado");
			break;
	}

}

int conversorTipoPasajero(char* tipoPasajeroAux)
{
	int rtn;
	rtn = -1;

	if(strcmp(tipoPasajeroAux, "FirstClass") == 0)
	{

		rtn = 1;
	}
	else
	{
		if(strcmp(tipoPasajeroAux, "ExecutiveClass") == 0)
		{

			rtn = 2;
		}
		else
		{

			rtn =  3;
		}
	}

	return rtn;
}

int conversorEstadoVuelo(char* estadoVueloAux)
{
	int rtn;
	rtn = -1;

	if(strcmp(estadoVueloAux ,"En Horario") == 0)
	{
		rtn = 1;
	}
	else
	{
		if(strcmp(estadoVueloAux, "Aterrizado") == 0)
		{
			rtn = 2;
		}
		else
		{
			if(strcmp(estadoVueloAux, "En Vuelo") == 0)
			{
				rtn = 3;
			}
			else
			{
				rtn = 4;
			}
		}
	}


	return rtn;
}


int mainMenu()
{
	int opcion;

	printf("\n\n==================  MENU PRINCIPAL  ==================\n\n"
			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
			"3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n"
			"6. Listar pasajeros\n7. Ordenar pasajeros\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n\n10. Salir\n"
			"==========================================================\n");
	opcion = getInt(1, 10, "Ingrese una opcion: ");


	return opcion;
}



int listPassengers(LinkedList* pArrayPassengers)
{
	Passenger* passengerAux;
	int i;
	int limite;
	int rtn;
	rtn = -1;

	if(pArrayPassengers != NULL)
	{
		limite = ll_len(pArrayPassengers);
		printf("\n  ID\t       NOMBRE\t\t     APELLIDO\t\t   PRECIO\t     CODIGO\t\t    TIPO\t\t  ESTADO");
		for(i=0;i<limite;i++)
		{
			passengerAux = (Passenger*)ll_get(pArrayPassengers, i);

			if(passengerAux != NULL)
			{
				printOnePassenger(passengerAux);
				rtn = 0;
			}
		}
	}


	return rtn;
}



int printOnePassenger(Passenger* this)
{
	int idAux;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char tipoPasajeroChar[25];
	char codigoVueloAux[10];
	int estadoVueloAux;
	char estadoVueloChar[25];
	int rtn;
	rtn = -1;


	if(this != NULL)
	{

		if(Passenger_getId(this, &idAux) == 0 && Passenger_getNombre(this, nombreAux) == 0 && Passenger_getApellido(this, apellidoAux) == 0 && Passenger_getPrecio(this, &precioAux) == 0 && Passenger_getTipoPasajero(this, &tipoPasajeroAux) == 0 && Passenger_getCodigoVuelo(this, codigoVueloAux) == 0 && Passenger_getEstadoVuelo(this, &estadoVueloAux) == 0 )
		{

			charTipoPasajero(&tipoPasajeroAux, tipoPasajeroChar);
			charEstadoVuelo(&estadoVueloAux, estadoVueloChar);
			printf("\n %5d\t %15s\t%15s\t\t  %10.2f\t  %10s\t     %15s\t  %15s",idAux, nombreAux, apellidoAux, precioAux, codigoVueloAux, tipoPasajeroChar, estadoVueloChar);
			rtn = 0;
		}
	}


	return rtn;
}





//VALIDACIONES

int stringEmpty(char string[])
{
	int rtn;
	int i;
	rtn = 0;


		for(i=0;i<strlen(string);i++)
		{
			if(string[i] != ' ')
			{
				rtn = 1;
				break;
			}
			else
			{
				rtn = 0;
			}

		}


	return rtn;
}

void getString(char string[], int lenght, char text[])
{
	char auxiliar[1024];


	printf("\n%s", text);
	fflush(stdin);
	gets(auxiliar);

	while(strlen(auxiliar) < 1 || strlen(auxiliar) > lenght || stringEmpty(auxiliar) == 0)
	{
		printf("\nError, ingrese al menos un caracter distinto de vacio, y un texto menor a %d caracteres:  ", lenght);
		fflush(stdin);
		gets(auxiliar);
	}

	strcpy(string, auxiliar);
}

int isName(char string[])
{
	int rtn;
	int i;
	rtn = 0;

	/*
	  65A  90Z  97a 122z  ||129 u:  154 U:||  130 é 144 É || desde 160 a- i -o- u- con acento- ñ- Ñ  hasta 165||
	  */

	for(i=0;i<strlen(string);i++)
	{
		if(isalpha(string[i]) == 0 && string[i] != ' ' && string[i] != '\0' && string[i] != '\n')
		{
			if((string[i] != 154 && string[i] != 129) && (string[i] < 160 || string[i] > 165) && (string[i] != 130 && string[i] != 144))
			{
				rtn = 0;
			}
			else
			{
				rtn = 1;
			}
		}
		else
		{
			rtn = 1;
		}

	}


	return rtn;
}


void getName(char string[], int lenght, char text[])
{
	char auxName[1024];

	getString(auxName, lenght, text);
	while(isName(auxName) == 0)
	{
		getString(auxName, lenght, "\nError, ingrese un nombre valido:  ");
	}


	strcpy(string, auxName);
}


int isInteger(char auxInteger[])
{
	int rtn, i, alphaCounter;
	alphaCounter = 0;
	rtn = 0;

	if(auxInteger != NULL){
		for(i=0;i<strlen(auxInteger);i++){
			if(isdigit(auxInteger[i]) == 0){
				alphaCounter++;
			}
		}
	}
	if(alphaCounter > 1 || (auxInteger[0] != 45 && (auxInteger[0] < 48 || auxInteger[0] > 57))){
		return rtn;
	}
	else{
		if(strlen(auxInteger) == 1 && auxInteger[0] == 45){
			return rtn;
		}
		else{
			rtn = 1;
		}
	}


	return rtn;
}


int getInt(int min, int max, char text[])
{
	char intAuxiliar[25];

	getString(intAuxiliar, 25, text);
	while((isInteger(intAuxiliar) == 0) || (atoi(intAuxiliar) < min || atoi(intAuxiliar) > max)){
		printf("\nError, ingrese un valor numerico entre: [> %d  &&  < %d] ", min, max);
		getString(intAuxiliar, 25," ");

	}

	return atoi(intAuxiliar);
}

int isFloat(char auxFloat[])
{
	int rtn, i;
	int alphaCounter, dotCounter, minusCounter;
	rtn = 0;
	alphaCounter = 0, dotCounter = 0, minusCounter = 0;


	if(auxFloat != NULL){
		for(i=0;i<strlen(auxFloat);i++)
		{
			if(isdigit(auxFloat[i]) == 0 && auxFloat[i] != 45 && auxFloat[i] != 46){
				alphaCounter++;
			}
			else{
				if(auxFloat[i] == 45){
					minusCounter++;
				}
				else
				{
					if(auxFloat[i] == 46){
						dotCounter++;
					}
				}
			}

		}
	}
	else{
		return rtn;
	}


	if(alphaCounter > 0 || dotCounter > 1 || minusCounter > 1){
		return rtn;
	}
	else{
		if(auxFloat[0] != 45 && (auxFloat[0] < 48 || auxFloat[0] > 57)){
			return rtn;
		}
		else{
			if(strlen(auxFloat) == 1 && auxFloat[0] == 45){
				return rtn;
			}
			else{
				if(strlen(auxFloat) > 1 && auxFloat[0] == 45 && auxFloat[1] == 46){
					return rtn;
				}
				else{
					rtn = 1;
				}
			}
		}
	}


	return rtn;
}

float getFloat(float min, float max, char text[])
{
	char floatAuxiliar[25];
	float retornoFloat;

		getString(floatAuxiliar, 25, text);
		while((isFloat(floatAuxiliar) == 0) || (atof(floatAuxiliar) < min || atof(floatAuxiliar) > max)){
			printf("\nError, ingrese un valor numerico entre: [> %.2f  &&  < %.2f] ", min, max);
			getString(floatAuxiliar, 25," ");
		}

	retornoFloat = atof(floatAuxiliar);
	return retornoFloat;
}


char getChar(char text[])
{
	char auxChar;


	printf("\n%s", text);
	fflush(stdin);
	scanf("%c", &auxChar);
	while(auxChar == ' ' || auxChar == '\n')
	{
		printf("\nError, ingrese al menos un caracter: ");
		fflush(stdin);
		scanf("%c", &auxChar);
	}

	return auxChar;
}



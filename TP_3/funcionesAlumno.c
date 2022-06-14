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




int validarDatosPasajero(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	int rtn;
	rtn = -1;


	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoStr != NULL && tipoPasajeroStr != NULL && estadoVueloStr != NULL)
	{
		if(strlen(idStr) < 6 || strlen(nombreStr) < 50 || strlen(apellidoStr) < 50
		   || strlen(precioStr) < 10 || strlen(codigoStr) < 11 || strlen(tipoPasajeroStr) < 15  || strlen(estadoVueloStr) < 15)
		{
			if(strlen(idStr) > 0 && strlen(nombreStr) > 0 && strlen(apellidoStr) > 0
		       && strlen(precioStr) > 0 && strlen(codigoStr) > 0 && strlen(tipoPasajeroStr) > 0 && strlen(estadoVueloStr) > 0)
			{
				rtn = 0;
			}
		}
	}


	return rtn;
}

int validarCodigoVuelo(char* codigoVuelo, char* estadoVueloStr)
{
	int rtn;
	int opcion;
	rtn = -1;

	/*
		FLYCODES  ESTADO VUELO
IB0800A - Aterrizado
MM0987B  - En Horario
TU6789B  - Aterrizado
GU2345F  - En Vuelo
HY4567D  - Demorado
FR5678G  - En Horario
BR3456J -  Demorado
		*/
	if(codigoVuelo != NULL && estadoVueloStr != NULL)
	{
		printf("\n==========  CODIGOS DE VUELO  ==========\n1- IB0800A\t\t2- MM0987B\n3- TU6789B\t\t4- GU2345F\n5- HY4567D\t\t6- FR5678G\n7- BR3456J\n=======================================\n");
		opcion = getInt(1, 7, "\nSeleccione el codigo de vuelo: ");
		printf("\nPASA LA OPCION");
		rtn = 0;

		switch(opcion)
		{
			case 1:
				strcpy(codigoVuelo,"IB0800A");
				strcpy(estadoVueloStr,"Aterrizado");
					break;
			case 2:
				strcpy(codigoVuelo,"MM0987B");
				strcpy(estadoVueloStr,"En Horario");
					break;
			case 3:
				strcpy(codigoVuelo,"TU6789B");
				strcpy(estadoVueloStr,"Aterrizado");
					break;
			case 4:
				strcpy(codigoVuelo,"GU2345F");
				strcpy(estadoVueloStr,"En Vuelo");
					break;
			case 5:
				strcpy(codigoVuelo,"HY4567D");
				strcpy(estadoVueloStr,"Demorado");
					break;
			case 6:
				strcpy(codigoVuelo,"FR5678G");
				strcpy(estadoVueloStr,"En Horario");
					break;
			case 7:
				strcpy(codigoVuelo,"BR3456J");
				strcpy(estadoVueloStr,"Demorado");
					break;
		}
	}


	return rtn;
}

int validarTipoPasajero(char* tipoPasajeroChar)
{
	int tipoPasajero;
	tipoPasajero = -1;

	printf("\n==========  TIPOS DE PASAJERO  ==========\n1- FIRST CLASS\n2- EXECUTIVE CLASS\n3- ECONOMY CLASS\n========================================\n");
	tipoPasajero = getInt(1, 3, "\nSeleccione un tipo de pasajero(1, 2, 3): ");

	switch(tipoPasajero)
	{
	case 1:
		strcpy(tipoPasajeroChar,"FirstClass");
		break;
	case 2:
		strcpy(tipoPasajeroChar,"ExecutiveClass");
		break;
	case 3:
		strcpy(tipoPasajeroChar,"EconomyClass");
		break;
	}


	return tipoPasajero;
}

int newId(void)
{
	FILE* pFile;
	char idAux[10];
	int idInt;
	int rtn;


	pFile = fopen("newID.txt","r");
	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", idAux);
		idInt = atoi(idAux);
		rtn = idInt;
		fclose(pFile);

		pFile = fopen("newID.txt","w");
		idInt++;

		if(pFile != NULL)
		{
			fprintf(pFile,"%d\n",idInt);
			fclose(pFile);
		}
	}

	return rtn;
}

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

int modifyMenu()
{
	int opcion;

	printf("\n\n==================  MENU EDITAR  ======================\n1- NOMBRE\n2- APELLIDO\n3- PRECIO\n4- TIPO DE PASAJERO\n5- CODIGO DE VUELO\n\n6- SALIR DEL MENU MODIFICAR"
			"\n========================================================\n");
	opcion = getInt(1, 6, "\nIngrese una opcion: ");


	return opcion;
}

int mainMenu()
{
	int opcion;

	printf("\n\n==================  MENU PRINCIPAL  ==================================================\n\n"
			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
			"3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n"
			"6. Listar pasajeros\n7. Ordenar pasajeros\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n\n10. Salir\n"
			"=======================================================================================\n");
	opcion = getInt(1, 10, "Ingrese una opcion: ");


	return opcion;
}

int sortMenu(void)
{
	int opcion;
	opcion = -1;

	printf("\n==========================   MENU ORDENAR  ==========================\n1- ORDERNAR POR NOMBRE\n2- ORDENAR POR APELLIDO\n3- ORDENAR POR PRECIO\n4- ORDENAR POR ID\n\n5- SALIR\n=====================================================================\n");
	opcion = getInt(1, 5, "\nIngrese una opcion: ");

	return opcion;
}

int ordenarPorNombre(void* pPassengerA, void* pPassengerB)
{
	int rtn;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char auxNombreA[50];
	char auxNombreB[50];
	rtn = -1;

	if(pPassengerA != NULL && pPassengerB != NULL)
	{
		pasajeroUno = (Passenger*)pPassengerA;
		pasajeroDos = (Passenger*)pPassengerB;

		Passenger_getNombre(pasajeroUno, auxNombreA);
		Passenger_getNombre(pasajeroDos, auxNombreB);


		rtn = stricmp(auxNombreA, auxNombreB);
	}


	return rtn;
}

int ordenarPorApellido(void* pPassengerA, void* pPassengerB)
{
	int rtn;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	char auxApellidoA[50];
	char auxApellidoB[50];
	rtn = -1;

	if(pPassengerA != NULL && pPassengerB != NULL)
	{
		pasajeroUno = (Passenger*)pPassengerA;
		pasajeroDos = (Passenger*)pPassengerB;

		Passenger_getApellido(pasajeroUno, auxApellidoA);
		Passenger_getApellido(pasajeroDos, auxApellidoB);

		rtn = stricmp(auxApellidoA, auxApellidoB);
	}


	return rtn;
}

int ordenarPorPrecio(void* pPassengerA, void* pPassengerB)
{
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	float auxPrecioA;
	float auxPrecioB;
	int rtn;
	rtn = -1;


	if(pPassengerA  != NULL && pPassengerB != NULL)
	{
		pasajeroUno = (Passenger*)pPassengerA;
		pasajeroDos = (Passenger*)pPassengerB;

		Passenger_getPrecio(pasajeroUno, &auxPrecioA);
		Passenger_getPrecio(pasajeroDos, &auxPrecioB);

		if(auxPrecioA > auxPrecioB)
		{
			rtn = 1;
		}
		else
		{
			if(auxPrecioA == auxPrecioB)
			{
				rtn = 0;
			}
		}

	}



	return rtn;
}

int ordenarPorId(void* pPassengerA, void* pPassengerB)
{
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;
	int auxIdA;
	int auxIdB;
	int rtn;
	rtn = -1;

	if(pPassengerA != NULL && pPassengerB != NULL)
	{
		pasajeroUno = (Passenger*)pPassengerA;
		pasajeroDos = (Passenger*)pPassengerB;

		Passenger_getId(pasajeroUno, &auxIdA);
		Passenger_getId(pasajeroDos, &auxIdB);

		if(auxIdA > auxIdB)
		{
			rtn = 1;
		}
		else
		{
			if(auxIdA == auxIdB)
			{
				rtn = 0;
			}
		}
	}


	return rtn;
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
		if(limite > 0)
		{
			printf("\n====================================================================  LISTADO DE PASAJEROS  ====================================================================\n");
			printf("\n  ID\t       NOMBRE\t\t     APELLIDO\t\t   PRECIO\t     CODIGO\t\t    TIPO\t\t  ESTADO");
			printf("\n================================================================================================================================================================\n");
			for(i=0;i<limite;i++)
			{
				passengerAux = (Passenger*)ll_get(pArrayPassengers, i);

				if(passengerAux != NULL)
				{
					printOnePassenger(passengerAux);
					rtn = 0;
				}
			}
			printf("\n================================================================================================================================================================\n");

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


int guardar_texto(FILE* pFile, LinkedList* pListaPasajeros)
{
	Passenger* auxPassenger;
	int intTipoPasajero;
	int intEstadoVuelo;
	char auxTipoPasajero[25];
	char auxEstadoVuelo[25];
	char auxName[50];
	char auxApellido[50];
	char auxCodigoVuelo[10];
	int auxId;
	float auxPrecio;

	int i;
	int rtn;
	rtn = -1;

	if(pFile != NULL && pListaPasajeros != NULL)
	{
		fprintf(pFile,"ID,NAME,LASTNAME,PRICE,FLYCODE,TYPEPASSENGER,STATUSFLIGHT\n");

		for(i=0;i<ll_len(pListaPasajeros);i++)
		{
			auxPassenger = (Passenger*)ll_get(pListaPasajeros, i);
			if(auxPassenger != NULL)
			{
				Passenger_getNombre(auxPassenger, auxName);
				Passenger_getApellido(auxPassenger, auxApellido);
				Passenger_getCodigoVuelo(auxPassenger, auxCodigoVuelo);
				Passenger_getId(auxPassenger, &auxId);
				Passenger_getPrecio(auxPassenger, &auxPrecio);

				Passenger_getTipoPasajero(auxPassenger, &intTipoPasajero);
				Passenger_getEstadoVuelo(auxPassenger, &intEstadoVuelo);
				charTipoPasajero(&intTipoPasajero, auxTipoPasajero);
				charEstadoVuelo(&intEstadoVuelo, auxEstadoVuelo);

				fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId, auxName, auxApellido, auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
			}
		}

		rtn = 0;
	}


	return rtn;
}



//==========VALIDACIONES

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

	char auxString[1];

	printf("\n%s", text);
	fflush(stdin);
	gets(auxString);
	while(strlen(auxString) > 1 || strcmp(auxString," ") == 0 || strcmp(auxString, "\n") == 0 || strcmp(auxString,"") == 0)
	{
		printf("\nError, ingrese solo un caracter: ");
		fflush(stdin);
		gets(auxString);
	}

	return auxString[0];
}


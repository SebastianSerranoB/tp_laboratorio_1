/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesAlumno.h"
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* newPassenger;

	newPassenger = (Passenger*)malloc(sizeof(Passenger)*1);
	if(newPassenger != NULL)
	{
		strcpy(newPassenger->nombre,"");
		strcpy(newPassenger->apellido,"");
		strcpy(newPassenger->codigoVuelo,"");
		newPassenger->id = 0;
		newPassenger->precio = -1;
		newPassenger->tipoPasajero = -1;
		newPassenger->estadoVuelo = -1;
	}

	return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* newPassenger;
	int estadoVuelo;
	int tipoPasajero;

	newPassenger = Passenger_new();
	if(newPassenger != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoStr != NULL && tipoPasajeroStr != NULL && estadoVueloStr != NULL)
	{
		Passenger_setId(newPassenger, atoi(idStr));
		Passenger_setNombre(newPassenger, nombreStr);
		Passenger_setApellido(newPassenger, apellidoStr);
		Passenger_setCodigoVuelo(newPassenger, codigoStr);
		Passenger_setPrecio(newPassenger, atof(precioStr));

		estadoVuelo = conversorEstadoVuelo(estadoVueloStr);
		tipoPasajero = conversorTipoPasajero(tipoPasajeroStr);

		Passenger_setEstadoVuelo(newPassenger, estadoVuelo);
		Passenger_setTipoPasajero(newPassenger, tipoPasajero);
	}

	return newPassenger;
}
//void Passenger_delete()


int Passenger_setId(Passenger* this,int id)
{
	int rtn;
	rtn = -1;


	if(this != NULL && id > 0)
	{
		this->id = id;


		rtn = 0;
	}

	return rtn;
}

int Passenger_getId(Passenger* this,int* id)
{
	int rtn;
	rtn = -1;


	if(this != NULL && id > 0)
	{
		*id = this->id;

		rtn = 0;
	}

	return rtn;
}


int Passenger_setNombre(Passenger* this,char* nombre)
{
	int rtn;
	rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int rtn;
	rtn = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		rtn = 0;
	}

	return rtn;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int rtn;
	rtn = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		rtn = 0;
	}

	return rtn;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int rtn;
	rtn = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		rtn = 0;
	}

	return rtn;
}


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn;
	rtn = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		rtn = 0;
	}

	return rtn;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rtn;
	rtn = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		rtn = 0;
	}

	return rtn;
}


int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int rtn;
	rtn = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		rtn = 0;
	}

	return rtn;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int rtn;
	rtn = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		*tipoPasajero = this->tipoPasajero;
		rtn = 0;
	}

	return rtn;
}


int Passenger_setPrecio(Passenger* this,float precio)
{
	int rtn;
	rtn = -1;

	if(this != NULL && precio > -1)
	{
		this->precio = precio;
		rtn = 0;
	}

	return rtn;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int rtn;
	rtn = -1;

	if(this != NULL && precio > 0)
	{
		*precio = this->precio;
		rtn = 0;
	}

	return rtn;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int rtn;
	rtn = -1;

	if(this != NULL && estadoVuelo >-1)
	{
		this->estadoVuelo = estadoVuelo;
		rtn = 0;
	}

	return rtn;
}


int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int rtn;
	rtn = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		rtn = 0;
	}

	return rtn;
}


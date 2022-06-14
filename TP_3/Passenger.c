/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
	Passenger* newPassenger = NULL;
	Passenger* rtn = NULL;
	int estadoVuelo;
	int tipoPasajero;

	newPassenger = Passenger_new();
	if(newPassenger != NULL)
	{
		if(validarDatosPasajero(idStr, nombreStr, apellidoStr, precioStr, codigoStr, tipoPasajeroStr, estadoVueloStr) == 0)
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

			rtn = newPassenger;
		}
		else
		{
			Passenger_delete(newPassenger);
		}

	}


	return rtn;
}

int Passenger_add(LinkedList* pListaPasajeros)
{
	Passenger* newPassenger;

	int rtn;
	rtn = -1;

	if(pListaPasajeros != NULL)
	{
		newPassenger = loadPassenger();
		if(newPassenger != NULL)
		{
			ll_add(pListaPasajeros, newPassenger);
			rtn = 0;
		}
	}


	return rtn;
}

Passenger* loadPassenger(void)
{
	Passenger* auxPassenger;
	char auxId[10];
	int id;
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecioChar[10];
	float auxPrecio;
	char auxCodigoVuelo[10];
	char auxTipoPasajero[25];
	char auxEstadoVuelo[25];


	 id= newId();
	 sprintf(auxId,"%d",id);
	 getName(auxNombre, 50, "\nIngrese el nombre del pasajero: ");
	 getName(auxApellido, 50, "\nIngrese el apellido del pasajero: ");
	 auxPrecio = getFloat(1, 1000000, "\nIngrese el precio del pasaje: ");
	 sprintf(auxPrecioChar,"%.2f",auxPrecio);
	 validarTipoPasajero(auxTipoPasajero);
	 validarCodigoVuelo(auxCodigoVuelo, auxEstadoVuelo);


	 auxPassenger = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecioChar, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);


	return auxPassenger;
}


int Passenger_modify(LinkedList* pListaPasajeros)
{
	Passenger* auxPassenger;
	char auxNombre[50];
	char auxApellido[50];
	char auxCodigoVuelo[10];
	float auxPrecio;
	char auxTipoPasajero[31];
	int tipoPasajeroInt;
	char auxEstadoVuelo[31];
	int estadoVueloInt;

	int index;
	int opcion;
	char respuesta;
	int rtn;

	rtn = -1;


	if(pListaPasajeros != NULL)
	{
		index = Passenger_buscarPorId(pListaPasajeros);
		if(index > -1)
		{
			auxPassenger = (Passenger*)ll_get(pListaPasajeros, index);
			printf("\n  ID\t       NOMBRE\t\t     APELLIDO\t\t   PRECIO\t     CODIGO\t\t    TIPO\t\t  ESTADO");
			printOnePassenger(auxPassenger);
			respuesta = getChar("\n Desea modificar este pasajero? S o N ");
			while(toupper(respuesta) != 'S' && toupper(respuesta) != 'N')
			{
				respuesta = getChar("\nError, ingrese una respuesta valida(S o N): ");
			}
			if(toupper(respuesta) == 'S')
			{
				rtn = 0;
				do{
					opcion = modifyMenu();
					switch(opcion)
					{
					case 1:
						getName(auxNombre, 50, "\nIngrese el nuevo nombre del pasajero: ");
						Passenger_setNombre(auxPassenger, auxNombre);
						printf("\nSe ha modificado el nombre.");
						break;
					case 2:
						getName(auxApellido, 50, "\nIngrese el nuevo apellido del pasajero: ");
						Passenger_setApellido(auxPassenger, auxApellido);
						printf("\nSe ha modificado el apellido.");
						break;
					case 3:
						auxPrecio = getFloat(1, 1000000, "\nIngrese el nuevo precio de ticket: ");
						Passenger_setPrecio(auxPassenger, auxPrecio);
						printf("\nSe ha modificado el precio.");
						break;
					case 4:
						 validarTipoPasajero(auxTipoPasajero);
						 tipoPasajeroInt = conversorTipoPasajero(auxTipoPasajero);
						 Passenger_setTipoPasajero(auxPassenger, tipoPasajeroInt);
						 printf("\nSe ha modificado el tipo de pasajero.");
						break;
					case 5:
						validarCodigoVuelo(auxCodigoVuelo, auxEstadoVuelo);
						estadoVueloInt = conversorEstadoVuelo(auxEstadoVuelo);
						Passenger_setCodigoVuelo(auxPassenger, auxCodigoVuelo);
						Passenger_setEstadoVuelo(auxPassenger, estadoVueloInt);
						printf("\nSe ha modificado el codigo de vuelo.");
						break;
					case 6:
						printf("\nRegresando al menu principal.");
						break;
					}
				}while(opcion != 6);
			}
			else
			{
				printf("\nNingun pasajero ha sido modificado.");
			}
		}
		else
		{
			printf("\nEl ID no coincide con ningun pasajero en lista.");
		}
	}

	return rtn;
}

int Passenger_buscarPorId(LinkedList* pListaPasajeros)
{
	Passenger* auxPassenger;
	int idPassenger;
	int id;
	int i;
	int rtn;
	rtn = -1;

	if(pListaPasajeros != NULL)
	{
		id = getInt(0, 1000000, "\nIngrese el ID del pasajero: ");
		for(i=0;i<ll_len(pListaPasajeros);i++)
		{
			auxPassenger = (Passenger*)ll_get(pListaPasajeros, i);
			if(auxPassenger != NULL)
			{
				Passenger_getId(auxPassenger, &idPassenger);
				if(id == idPassenger)
				{
					rtn = i;
					break;
				}
			}
		}

	}


	return rtn;
}

int removePassenger(LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* auxPassenger;
	int auxId;
	float auxPrecio;
	char auxNombre[50];
	char auxApellido[50];
	char auxCodigoVuelo[10];
	int intAuxTipo;
	int intAuxEstado;
	char auxTipo[25];
	char auxEstado[25];
	char respuesta;
	int index;
	int rtn;
	rtn = -1;

	if(pArrayListPassenger != NULL)
	{
		index = Passenger_buscarPorId(pArrayListPassenger);
		if(index > -1)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, index);
			printf("\n  ID\t       NOMBRE\t\t     APELLIDO\t\t   PRECIO\t     CODIGO\t\t    TIPO\t\t  ESTADO");
			printOnePassenger(auxPassenger);
			respuesta = getChar("\nDesea dar de baja este pasajero(S o N): ");
			while(toupper(respuesta) != 'S' && toupper(respuesta) != 'N')
			{
				respuesta = getChar("\nError, ingrese una respuesta valida(S o N): ");
			}
			if(toupper(respuesta) == 'S')
			{
				pFile = fopen("Passenger_bajas.txt","a");
				if(pFile != NULL)
				{
					Passenger_getNombre(auxPassenger, auxNombre);
					Passenger_getApellido(auxPassenger, auxApellido);
					Passenger_getCodigoVuelo(auxPassenger, auxCodigoVuelo);
					Passenger_getId(auxPassenger, &auxId);
					Passenger_getPrecio(auxPassenger, &auxPrecio);

					Passenger_getTipoPasajero(auxPassenger, &intAuxTipo);
					Passenger_getEstadoVuelo(auxPassenger, &intAuxEstado);
					charTipoPasajero(&intAuxTipo, auxTipo);
					charEstadoVuelo(&intAuxEstado, auxEstado);


					fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId, auxNombre, auxApellido, auxPrecio, auxCodigoVuelo, auxTipo, auxEstado);
					fclose(pFile);
				}

				ll_remove(pArrayListPassenger, index);
				printf("\nEl pasajero fue dado de baja.");
				rtn = 0;
			}
			else
			{
				printf("\nEl pasajero no ha sido dado de baja.");
			}

		}
		else
		{
			printf("\nEl ID no coincide con ningun pasajero en lista.");
		}
	}


	return rtn;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}

}


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


	if(this != NULL && id != NULL)
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

	if(this != NULL && tipoPasajero != NULL)
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

	if(this != NULL && precio != NULL)
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


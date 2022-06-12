/*
 * arrayPassenger.c
 *
 ============================================================================

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
#include <string.h>
#include <ctype.h>

#include "arrayPassenger.h"
#include "funcionesAlumno.h"

//========== FUNCIONES CATEDRA ==========
int initPassengers(sPassenger list[], int len)
{
	int rtn;
	int i;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = EMPTY;
		}
		rtn = 0;
	}

	return rtn;
}

int addPassenger(sPassenger list[], int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{
	int rtn;
	int index;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		index = findEmptySlot(list, len);
		if(index > -1)
		{
			list[index].price = price;
			list[index].typePassenger = typePassenger;
			strcpy(list[index].lastName, lastName);
			strcpy(list[index].name, name);
			strcpy(list[index].flycode,flycode);

			list[index].id = id;
			list[index].isEmpty = OCCUPIED;
			rtn = 0;
		}
	}

	return rtn;
}

int findPassengerById(sPassenger list[], int len,int id)
{
	int rtn;
	int i;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCCUPIED && list[i].id == id)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int removePassenger(sPassenger list[], int len, int id)
{
	int rtn;
	int i;
	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCCUPIED && list[i].id == id)
			{
				rtn = 0;
				list[i].isEmpty = REMOVED;
				printf("\nPassenger was removed succesfully.");
				break;
			}
		}

	}

	return rtn;
}

int sortPassengersBySurname(sPassenger list[], int len, int order)
{
	int rtn;
	int i;
	int j;
	sPassenger aux;
	rtn = -1;


	if(list != NULL && len > 0)
	{
		rtn = 0;
		for(i=0;i<len;i++){
			if(list[i].isEmpty == OCCUPIED){
				strupr(list[i].lastName);
				strupr(list[i].name);
			}
		}

		if(order == 1)
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].typePassenger < list[j].typePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}
		else
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].typePassenger > list[j].typePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}

	}

	return rtn;
}

int sortPassengersByFlightCode(sPassenger list[], int len, int order)
{
	int rtn;
	int i;
	int j;
	sPassenger aux;
	rtn = -1;


	if(list != NULL && len > 0)
	{
		rtn = 0;
		for(i=0;i<len;i++){
			if(list[i].isEmpty == OCCUPIED){
				strupr(list[i].lastName);
				strupr(list[i].name);
			}
		}
		if(order == 1)
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[i].flycode, list[j].flycode) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].flycode, list[j].flycode) == 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
		else
		{
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[i].flycode, list[j].flycode) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].flycode, list[j].flycode) == 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}

	}

	return rtn;
}

int printPassengers(sPassenger passengerList[], int passengerlength, sFlight flightList[], int flightLen)
{
	int rtn;
	int i;
	rtn = -1;

	if(passengerList != NULL && flightList != NULL && passengerlength > 0 && passengerlength > 0)
	{
		rtn = 0;
		for(i=0;i<passengerlength;i++)
		{
			if(passengerList[i].isEmpty == OCCUPIED)
			{
				printPassenger(passengerList[i], flightList, flightLen);
			}
		}
	}

	return rtn;
}


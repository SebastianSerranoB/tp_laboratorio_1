#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "funcionesAlumno.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
    int rtn;
    rtn = -1;

    if(path != NULL && pArrayListPassenger != NULL)
    {
    	pFile = fopen(path, "r");

    	if(parser_PassengerFromText(pFile, pArrayListPassenger) == 0)
    	{
    		printf("\nLISTA CARGADA EXITOSAMENTE!");
    		rtn = 0;
    		fclose(pFile);
    	}
    	else
    	{
    		printf("\nERROR, NO PUDO LEERSE EL ARCHIVO.");
    	}
    }
    else
    {
    	printf("\nERROR...");
    }

    return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int rtn;

	rtn = -1;
	pFile = fopen(path,"rb");


	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "r");
		if(parser_PassengerFromBinary(pFile, pArrayListPassenger) == 0)
		{
			printf("\nLISTA CARGADA EXITOSAMENTE!");
			rtn = 0;
		}
		else
		{
			printf("\nERROR, NO PUDO LEERSE EL ARCHIVO.");
		}
	}
	else
	{
		printf("\nEL ARCHIVO NO EXISTE!");
	}

	return rtn;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int rtn;
    rtn = -1;

    if(pArrayListPassenger != NULL)
    {
    	if(listPassengers(pArrayListPassenger) == 0)
		{
    		rtn = 0;

    		printf("\nSE LISTARON!");
		}
    	else
    	{
    		printf("\nNO EXISTEN PASAJEROS EN LISTA.");
    	}
    }

    return rtn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}


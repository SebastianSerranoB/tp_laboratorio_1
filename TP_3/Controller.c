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

    	}
    	else
    	{
    		printf("\nERROR, NO PUDO LEERSE EL ARCHIVO.");
    	}

    	fclose(pFile);
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


	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "rb");
		if(parser_PassengerFromBinary(pFile, pArrayListPassenger) == 0)
		{
			printf("\nLISTA CARGADA EXITOSAMENTE!");

			rtn = 0;
		}
		else
		{
			printf("\nERROR, NO PUDO LEERSE EL ARCHIVO.");
		}

		fclose(pFile);
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
	int rtn;
	rtn = -1;

	if(pArrayListPassenger != NULL)
	{
		if(Passenger_add(pArrayListPassenger) == 0)
		{
			printf("\nSe ha agregado un nuevo pasajero a la lista.");
			rtn = 0;
		}
		else
		{
			printf("\n..Regresando al menu principal.");
		}
	}
	else
	{
		printf("\nError, no se han agregado pasajeros.");
	}


    return rtn;
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
	int rtn;
	rtn = -1;

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		if(Passenger_modify(pArrayListPassenger) == 0)
		{
			rtn = 0;
		}
		else
		{
			printf("\n..Regresando al menu principal.");
		}
	}
	else
	{
		printf("\nError, no se encuentran pasajeros en lista.");
	}


    return rtn;
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
	int rtn;
	rtn = -1;

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		if(removePassenger(pArrayListPassenger) == 0)
		{
			rtn = 0;
		}
		else
		{
			printf("\nRegresando al menu principal.");
		}
	}
	else
	{
		printf("\nNo se encuentran pasajeros en lista.");
	}

    return rtn;
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
		}
    	else
    	{
    		printf("\nNO EXISTEN PASAJEROS EN LISTA.");
    	}
    }
    else
    {
    	printf("\nError.. lista no valida.");
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
	int rtn;
	int menuOpcion;
	rtn = -1;

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 1)
	{
		rtn = 0;
		do{
			menuOpcion = sortMenu();
			switch(menuOpcion)
			{
			case 1:
				printf("\nOrdenando lista.. aguarde un segundo.");
				ll_sort(pArrayListPassenger, ordenarPorNombre, 1);
				printf("\nLista ordenada por nombre exitosamente.");
				break;
			case 2:
				printf("\nOrdenando lista.. aguarde un segundo.");
				ll_sort(pArrayListPassenger, ordenarPorApellido, 1);
				printf("\nLista ordenada por apellido exitosamente.");
				break;
			case 3:
				printf("\nOrdenando lista.. aguarde un segundo.");
				ll_sort(pArrayListPassenger, ordenarPorPrecio, 0);
				printf("\nLista ordenada por precio exitosamente.");
				break;
			case 4:
				printf("\nOrdenando lista.. aguarde un segundo.");
				ll_sort(pArrayListPassenger, ordenarPorId, 1);
				printf("\nLista ordenada por ID exitosamente.");
				break;
			case 5:
				printf("\nSaliendo al menu principal.");
				break;
			}

		}while(menuOpcion != 5);

	}
	else
	{
		printf("\nDebe cargar al menos dos pasajeros para ordenarlos.");
	}


    return rtn;
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
	FILE* pFile;
	int rtn;
	rtn = -1;

	if(path != NULL && pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			guardar_texto(pFile, pArrayListPassenger);
			printf("\nARCHIVO DE TEXTO GUARDADO EXITOSAMENTE.");
			fclose(pFile);
			rtn = 0;
		}
		else
		{
			printf("\ERROR, EL ARCHIVO NO FUE GUARDADO.");
		}
	}
	else
	{
		printf("\nERROR, VERIFIQUE QUE EXISTAN PASAJEROS EN LISTA.");
	}


    return rtn;
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
	FILE* pFile;
	Passenger* auxPassenger;
	int i;
	int rtn;

	rtn = -1;

	if(path != NULL && pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			for(i=0;i<ll_len(pArrayListPassenger);i++)
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
				if(auxPassenger != NULL)
				{
					fwrite(auxPassenger,sizeof(Passenger),1,pFile);
				}
			}

			rtn = 0;
			printf("\nARCHIVO GUARDADO EXITOSAMENTE EN BINARIO.");
			fclose(pFile);
		}
		else
		{
			printf("\ERROR, NO SE GUARDO EL ARCHIVO.");
		}
	}
	else
	{
		printf("\nERROR, VERIFIQUE QUE EXISTAN PASAJEROS EN LISTA.");
	}


    return rtn;
}


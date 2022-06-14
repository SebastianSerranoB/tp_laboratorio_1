/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoVuelo;
	int isEmpty;

}Passenger;

/**
 * @brief constructor de pasajero, asigna memoria para un pasajero e inicializa los diferentes campos que lo componen
 *
 * @return Si puede reservar memoria, retorna un puntero a el pasajero, de caso contrario, retorna NULL
 */
Passenger* Passenger_new();

/**
 * @brief constructor de pasajero, asigna memoria para un pasajero y carga sus diferentes campos con los parametros recibidos
 *
 * @param idStr		id del pasajero en formato string(char)
 * @param nombreStr	nombre del pasajero en formato string(char)
 * @param apellidoStr	apellido del pasajero en formato string(char)
 * @param precioStr	precio del pasajero en formato string(char)
 * @param codigoStr	codigo de vuelo del pasajero en formato string(char)
 * @param tipoPasajeroStr	tipo de pasajero en formato string(char)
 * @param estadoVueloStr estado de vuelo  en formato string(char)
 *
 * @return	Si puede cargar un pasajero con exito, retorna un puntero al mismo, de caso contrario retorna NULL
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoVueloStr);

/**
 * @brief	Funcion que da de alta un pasajero en la estructura linkedList pListaPasajeros , validando y pidiendole los datos al usuario.
 *
 * @param pListaPasajeros puntero a la estructura linkedList de Passengers
 * @return	Si un pasajero es agregado a la estructura con exito retorna (0), sino, retorna (-1)
 */
int Passenger_add(LinkedList* pListaPasajeros);

/**
 * @brief Funcion que pide y valida los datos correspondientes a los campos de la estructura de un pasajero.
 *
 * @return Si puede cargar los datos en los campos del pasajero , retorna un puntero al mismo, sino, retorna NULL
 */
Passenger* loadPassenger(void);

/**
 * @brief Funcion que le permite al usuario modifar los campos seleccionados de un pasajero de la lista pListaPasajeros
 *
 * @param pListaPasajeros	pListaPasajeros puntero a la estructura linkedList de Passengers
 * @return Si el pasajero existe y la opcion de modificacion elegida por el usuario es valida, retorna (0), sino, retorna(-1)
 */
int Passenger_modify(LinkedList* pListaPasajeros);

/**
 * @brief	Funcion que pide al usuario la id de un pasajero existente en la lista, si es valida, retorna la posicion del pasajero.
 *
 * @param pListaPasajeros puntero a la estructura linkedList de pasajeros
 * @return	si la id coincide con la de un pasajero de la lista, retorna la posicion del mismo, sino, retorna (-1)
 */
int Passenger_buscarPorId(LinkedList* pListaPasajeros);


/**
 * @brief Si this es != NULL libera la asignacion de memoria de this (free).
 *
 * @param this	puntero a un elemento(pasajero) de la linkedList passengers
 */
void Passenger_delete(Passenger* this);

/**
 * @brief Funcion que da de baja(logica) un pasajero determinado por el usuario, pidiendole confirmacion, de ser dado de baja, sus datos se guardan en un archivo txt de bajas
 *
 * @param pArrayListPassenger puntero a la estructura linkedList de pasajeros
 * @return Si el pasajero fue dado de baja retorna(0), de caso contrario, retorna (-1)
 */
int removePassenger(LinkedList* pArrayListPassenger);

/**
 * @brief	funcion setter para el campo ID de pasajero, recibe como parametro el id y lo asigna en el campo correspondiente.
 *
 * @param this puntero a un elemento(pasajero) de la estructura Passenger
 * @param id	id que sera asignado en el campo correspondiente de pasajero
 * @return	si this es != NULL e ID es mayor a 0 retorna (0), sino, retorna (-1).
 */
int Passenger_setId(Passenger* this,int id);

/**
 * @brief	Funcion getter, asigna el ID de un pasajero(this) en una variable id
 *
 * @param this	puntero a un elemento(pasajero) de la estructura Passenger
 * @param id	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Passenger_getId(Passenger* this,int* id);

/**
 * @brief 	funcion setter para el campo nombre de pasajero, recibe como parametro el nombre y lo asigna en el campo correspondiente.
 *
 * @param this	 puntero a un elemento(pasajero) de la estructura Passenger
 * @param nombre parametro que se asignara en en el campo nombre de a estructura
 * @return Si this y nombre son != NULL retorna (0), sino , retorna (-1)
 */
int Passenger_setNombre(Passenger* this,char* nombre);

/**
 * @brief	Funcion getter, asigna el nombre de un pasajero(this) en una variable nombre
 *
 * @param this	puntero a un elemento(pasajero) de la estructura Passenger
 * @param nombre	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Passenger_getNombre(Passenger* this,char* nombre);


/**
 * @brief 	funcion setter para el campo apellido de pasajero, recibe como parametro el apellido y lo asigna en el campo correspondiente.
 *
 * @param this	 puntero a un elemento(pasajero) de la estructura Passenger
 * @param apellido	 parametro que se asignara en en el campo apellido de a estructura
 * @return	si this es != NULL y apellido es valido retorna (0), sino, retorna (-1)
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/**
 * @brief	Funcion getter, asigna el apellido de un pasajero(this) en una variable apellido
 *
 * @param this	puntero a un elemento(pasajero) de la estructura Passenger
 * @param apellido	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Passenger_getApellido(Passenger* this,char* apellido);


/**
 * @brief 	funcion setter para el campo codigo de pasajero, recibe como parametro el codgioVuelo y lo asigna en el campo correspondiente.
 *
 * @param this  puntero a un elemento(pasajero) de la estructura Passenger
 * @param codigoVuelo	 parametro que se asignara en en el campo codigoVuelo de a estructura
 * @return	si this es != NULL y codigoVuelo es valido retorna (0), sino, retorna (-1)
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @brief	Funcion getter, asigna el codigoVuelo de un pasajero(this) en una variable codigoVuelo
 *
 * @param this		puntero a un elemento(pasajero) de la estructura Passenger
 * @param codigoVuelo	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);


/**
 * @brief 	funcion setter para el campo tipo  de pasajero, recibe como parametro el tipo y lo asigna en el campo correspondiente.
 *
 * @param this	this puntero a un elemento(pasajero) de la estructura Passenger
 * @param tipoPasajero	 parametro que se asignara en en el campo tipoPasajero de a estructura
 * @return	si this es != NULL y tipoPasajero es valido retorna (0), sino, retorna (-1)
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/**
 * @brief	Funcion getter, asigna el tipoPasajero de un pasajero(this) en una variable tipoPasajero
 *
 * @param this	puntero a un elemento(pasajero) de la estructura Passenger
 * @param tipoPasajero	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);


/**
 * @brief 	funcion setter para el campo precio de pasajero, recibe como parametro el precio y lo asigna en el campo correspondiente.
 *
 * @param this	this puntero a un elemento(pasajero) de la estructura Passenger
 * @param precio	 parametro que se asignara en en el campo precio de a estructura
 * @return	si this es != NULL y precio es valido retorna (0), sino, retorna (-1)
 */
int Passenger_setPrecio(Passenger* this,float precio);

/**
 * @brief	Funcion getter, asigna el precio de un pasajero(this) en una variable precio
 *
 * @param this	puntero a un elemento(pasajero) de la estructura Passenger
 * @param precio	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Passenger_getPrecio(Passenger* this,float* precio);


/**
 * @brief 	funcion setter para el campo estadoVuelo de pasajero, recibe como parametro el estadoVuelo y lo asigna en el campo correspondiente.
 *
 * @param this	this puntero a un elemento(pasajero) de la estructura Passenger
 * @param estadoVuelo	 parametro que se asignara en en el campo estadoVuelo de a estructura
 * @return si this es != NULL y estadoVuelo es valido retorna (0), sino, retorna (-1)
 */
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);

/**
 * @brief	Funcion getter, asigna el estadoVuelo de un pasajero(this) en una variable estadoVuelo
 *
 * @param this	puntero a un elemento(pasajero) de la estructura Passenger
 * @param estadoVuelo	parametro donde se asignara el campo correspondiente de la estructura
 * @return	si this y el campo a asignar son != NULL retorna (0), sino, retorna (-1)
 */
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);



#endif /* PASSENGER_H_ */

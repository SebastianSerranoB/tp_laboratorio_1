/*
 * funcionesAlumno.h
 *
 *  Created on: 8 jun 2022
 *      Author: admin
 */

#ifndef FUNCIONESALUMNO_H_
#define FUNCIONESALUMNO_H_

#include <stdio.h>
#include "Passenger.h"
#include "LinkedList.h"


/**
 * @brief	recibe en formato char los diferentes campos de la estrucrura Passenger, valida que se corresponda con el formato declarado en la estructura.
 *
 * @param idStr   		    puntero char, contiene el ID del pasajero recibido como texto(char)
 * @param nombreStr			puntero char, contiene el nombre del pasajero recibido como texto(char)
 * @param apellidoStr		puntero char, contiene el apellido del pasajero recibido como texto(char)
 * @param precioStr			puntero char, contiene el precio del pasajero recibido como texto(char)
 * @param codigoStr			puntero char, contiene el codigo de vuelo del pasajero recibido como texto(char)
 * @param tipoPasajeroStr	puntero char, contiene el tipo de pasajero recibido como texto(char)
 * @param estadoVueloStr	puntero char, contiene el estado de vuelo del pasajero recibido como texto(char)
 *
 * @return	si los parametros recibidos son != NULL y se corresponden con el formato de la estructura devuelve (0), de no ser el caso, devuelve (-1)
 */
int validarDatosPasajero(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoVueloStr);

/**
 * @brief	guarda todos los elementos de la lista de pasajeros en un archivo csv.
 *
 * @param pFile	puntero hacia archivo de texto abierto
 * @param pListaPasajeros	puntero hacia la lista de pasajeros(estructura linkedlist)
 *
 * @return	si pFile es != NULL y pListaPasajeros es != NULL devuelve (0), de no ser el caso, retorna -1;
 */
int guardar_texto(FILE* pFile, LinkedList* pListaPasajeros);

/**
 * @brief	Funcion que realiza una comparacion por nombre entre dos pasajeros
 *
 * @param pPassengerA	puntero al primer pasajero
 * @param pPassengerB	puntero al segundo pasajero
 *
 * @return Retorna 1 si el nombre del primer pasajero es mayor que el del segundo, 0 si son iguales y -1 si es menor.
 */
int ordenarPorNombre(void* pPassengerA, void* pPassengerB);

/**
 * @brief Funcion que realiza una comparacion por apellido entre dos pasajeros
 *
 * @param pPassengerA	puntero hacia el primero pasajero
 * @param pPassengerB puntero hacia el segundo pasajero
 *
 * @return	Retorna 1 si el apellido del primer pasajero es mayor que el del segundo, 0 si son iguales y -1 si es menor.
 */
int ordenarPorApellido(void* pPassengerA, void* pPassengerB);

/**
 * @brief	Funcion que realiza una comparacion por precio entre dos pasajeros.
 *
 * @param pPassengerA	puntero al primer pasajero
 * @param pPassengerB	puntero al segundo pasajero
 *
 * @return Retorna 1 si el primero es mayor que el segundo, 0 si son iguales y -1 si es menor
 */
int ordenarPorPrecio(void* pPassengerA, void* pPassengerB);

/**
 * @brief 	Funcion que realiza una comparacion por ID entre dos pasajeros.
 *
 * @param pPassengerA	puntero al primer pasajero
 * @param pPassengerB	puntero al segundo pasajero
 *
 * @return	retorna 1 si el primero es mayor que el segundo, 0 si son iguales y -1 si es menor.
 *
 */
int ordenarPorId(void* pPassengerA, void* pPassengerB);

/**
 * @brief	Funcion que muestra en consola un menu de opciones de ordenamiento de lista y devuelve la opcion ingresada por el usuario.
 *
 * @return	retorna la opcion(int) de ordenamiento elegida por el usuario.
 */
int sortMenu(void);

/**
 * @brief Funcion que muestra en consola un menu de opciones de Modificacion de pasajero y devuelve la opcion ingresada por el usuario.
 *
 * @return	retorna la opcion(int) de modificacion elegida por el usuario.
 */
int modifyMenu(void);

/**
 * @brief	Funcion que asigna un estado de vuelo correspondiente al codigo de vuelo recibido.
 *
 * @param codigoVuelo	puntero char hacia codigo de vuelo
 * @param estadoVueloStr	puntero char hacia estado de vuelo en formato texto(char)
 *
 * @return Si codigoVuelo y estadoVueloStr son != NULL retorna (0), de caso contrario, retorna (-1)
 */
int validarCodigoVuelo(char* codigoVuelo, char* estadoVueloStr);

/**
 * @brief	Funcion que recibe el tipo de pasajero en formato char y retorna un valor numerico correspondiente al tipo de pasajero.
 *
 * @param tipoPasajeroChar puntero char al tipo de pasajero recibido en formato texto(char).
 * @return si tipoPasajeroChar es != NULL retorna el numero correspondiente al tipo de pasajero, de caso contrario retorna (-1).
 */
int validarTipoPasajero(char* tipoPasajeroChar);

/**
 * @brief	Funcion que lee archivo de ID para pasajero, tomando y retornando la nueva(unica) y cargando en el archivo la siguiente ID.
 *
 * @return	Retorna el nuevo ID(unico) del pasajero en formato integer.
 */
int newId(void);

/**
 * @brief Funcion que recibe el tipo(int) en formato numerico y asigna en tipoChar(char) el texto correspondiente a ese valor numerico.
 *
 * @param tipo puntero al tipo de pasajero en formato integer
 * @param tipoChar puntero char donde se alojara el "tipo de pasajero" en formato texto(char)
 */
void charTipoPasajero(int* tipo, char* tipoChar);

/**
 * @brief Funcion que recibe el estado(int) en formato numerico y asigna en estadoChar(char) el texto correspondiente a ese valor numerico.
 *
 * @param estado	puntero al estado de vuelo en formato integer
 * @param estadoChar	puntero char donde se alojara el "estado de vuelo" en formato texto(char)
 */
void charEstadoVuelo(int* estado, char* estadoChar);

/**
 * @brief	Recibe el tipo de pasajero en formato texto(char) y retorna un valor numerico(int) correspondiente a dicho tipo de pasajero.
 *
 * @param 	tipoPasajeroAux puntero char al tipo de pasajero en formato texto(char)
 * @return	retorna un numero(int) correspondiente al tipo de pasajero recibito en formato texto(char), de no corresponderse con ninguno, retorna -1
 */
int conversorTipoPasajero(char* tipoPasajeroAux);

/**
 * @brief	Recibe el estado de vuelo en formato texto(char) y retorna un valor numerico(int) correspondiente a dicho estado de vuelo.
 *
 * @param estadoVueloAux	puntero char al tipo de pasajero en formato texto(char)
 * @return	retorna un numero(int) correspondiente al estado de vuelo recibido en formato texto(char), de no corresponderse con ninguno, retorna -1
 */
int conversorEstadoVuelo(char* estadoVueloAux);

/**
 * @brief Funcion que muestra por consola los diferentes campos del pasajero recibido como parametro.
 *
 * @param this	puntero al pasajero a ser mostrado
 * @return	retorna (0) si this es != NULL, de caso contrario, retorna (-1)
 */
int printOnePassenger(Passenger* this);

/**
 * @brief Funcion que muestra por consola todos los pasajeros cargados en lista
 *
 * @param pArrayPassengers puntero a lista de pasajeros.
 * @return Si pArrayPassenger es != NULL y existe al menos un pasajero en lista, retorna (0), de caso contrario, retorna (-1)
 */
int listPassengers(LinkedList* pArrayPassengers);

/**
 * @brief Funcion que muestra en consola las diferentes opciones del menu principal y retorna la opcion elegida por el usuario.
 *
 * @return	retorna en formato numerico(integer) la opcion de menu elegida por el usuario.
 */
int mainMenu();

/**
 * @brief Ask's to the user, validates and loads array of chars(string).
 * @param string array of chars
 * @param lenght max lenght of char array
 * @param text text to be printed as entry instructions for the user
 */
void getString(char string[], int lenght, char text[]);

/**
 * @brief validates emptiness of array of chars(string)
 * @param string array of chars(string)
 * @return if array of chars(string) is empty, returns 0, else, returns 1(ok).
 */
int stringEmpty(char string[]);

/**
 * @brief Validates that the string received is a valid integer number.
 * @param auxInteger array of chars(string)
 * @return if array of chars(string) is a valid integer number returns 1(ok), else, returns 0.
 */
int isInteger(char auxInteger[]);

/**
 * @brief ask's to the user, validates and returns integer.
 * @param min min integer value allowed for entry
 * @param max max integer value allowed for entry
 * @param text text to be printed as entry instructions for the user.
 * @return returns validated integer entered by the user
 */
int getInt(int min, int max, char text[]);

/**
 * @brief Validates that the array of chars(string) is a float number.
 * @param auxFloat array of chars(string)(float)
 * @return if array of chars(string) is a valid float number it returns 1(ok), else, returns 0.
 */
int isFloat(char auxFloat[]);

/**
 * @brief ask's to the user, validates and returns a float number.
 * @param min min float value allowed for entry.
 * @param max max float value allowed for entry.
 * @param text text to be printed as entry instructions for the user.
 * @return returns a validated float number, entered by the user.
 */
float getFloat(float min, float max, char text[]);

/**
 * @brief Ask's to the user and returns a char variable
 * @param text text to be printed as entry instructions for the user
 * @return returns a char variable entered by the user.
 */
char getChar(char text[]);

/**
 * @brief ask's to the user, validates and loads name
 * @param string array of char(string(name)
 * @param lenght max lenght of array of chars(string)
 * @param text text to be printed as entry instructons.
 */
void getName(char string[], int lenght, char text[]);

/**
 * @brief Validates that the array of chars(string) is a name.
 * @param string array of chars(string)
 * @return if array of chars(string) is a valid name it returns 1, else, returns 0.
 */
int isName(char string[]);


#endif /* FUNCIONESALUMNO_H_ */

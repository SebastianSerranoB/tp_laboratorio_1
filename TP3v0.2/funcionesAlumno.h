/*
 * funcionesAlumno.h
 *
 *  Created on: 8 jun 2022
 *      Author: admin
 */

#ifndef FUNCIONESALUMNO_H_
#define FUNCIONESALUMNO_H_

#include "Passenger.h"
#include "LinkedList.h"

void charTipoPasajero(int* tipo, char* tipoChar);
void charEstadoVuelo(int* estado, char* estadoChar);
int conversorTipoPasajero(char* tipoPasajeroAux);
int conversorEstadoVuelo(char* estadoVueloAux);
int printOnePassenger(Passenger* this);
int listPassengers(LinkedList* pArrayPassengers);
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

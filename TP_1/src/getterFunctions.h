

 /** @file getterFunctions.h
 * @version 1.2
 * @date 11/04/2022
 * @author Serrano Belloso Sebastian
 * @title funcionesGet_TP1
 * @brief Funciones get para el trabajo practico 1-Laboratorio de programacion 1, UTN.
 */


#ifndef GETTERFUNCTIONS_H_
#define GETTERFUNCTIONS_H_


/**
 * @brief mainMenu Shows an options menu in the console, returning the selected option.
 * @param km  shows distance in kilometers.
 * @param aerolineas shows entered flight price for Aerolines enterprise.
 * @param latam shows entered flight price for Latam enterprise.
 * @return returns option entered by user.
 */
int mainMenu(float km, float aerolineas, float latam);

/**
 * @brief subMenu shows a flight company menu, returning the user entered option.
 * @param void // receives void(nothing).
 * @return returns menu option entered by the user.
 */
char subMenu(void);

/**
 * @brief getFloat receives a minimun and maximun range number and a char that indicates the type, returning an user entry positive float.
 * @param min receives an  integer for the minimun number allowed for entry.
 * @param max receives an integer for the maximun number allowed for entry.
 * @param type receives a char that indicates the type of data returned.
 * @return returns a positive float number in a range.
 */
float getFloat(int min, int max, char type);


#endif /* GETTERFUNCTIONS_H_ */

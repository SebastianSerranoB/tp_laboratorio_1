/**
 * @file utn.h
 * @version 1.0
 * @date 11/04/2022
 * @author Serrano Belloso Sebastian
 * @title funciones_TP1
 * @brief Funciones para el trabajo practico 1-Laboratorio de programacion 1, UTN.
 */


#ifndef UTN_H_
#define UTN_H_

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

/**
 * @brief calculatePrice calculates the percentaje of a number.
 * @param price receives price number.
 * @param percentaje receives percentaje number to be calculated.
 * @return returns float percentaje of the price.
 */
float calculatePrice(float price, float percentaje);

/**
 * @brief divide calculates the division of two numbers returning the result.
 * @param operatorA receives dividend.
 * @param operatorB receives divider.
 * @return returns a float number, result of the division.
 */
float divide(float operatorA, float operatorB);

/**
 *@brief calculateDifference calculates the difference between two numbers, returning a positive number.
 * @param minuend the number to be substracted.
 * @param subtrahend the subtracting number.
 * @return returns a positive number as result of the substraction.
 */
float calculateDifference(float minuend, float subtrahend);

/**
 * @brief printAerolineas shows Aerolineas fee for each payment option and flight price per kilometer.
 * @param price receives aerolineas flight fee.
 * @param debit receives aerolineas debit fee.
 * @param credit receives aerolineas credit fee
 * @param bitcoin receives aerolineas fee in bitcoins.
 * @param unitPrice receives aerolineas flight price per kilometer.
 */
void printAerolineas(float price, float debit, float credit, float bitcoin, float unitPrice);

/**
 * @brief printLatam printLatam shows latam's fee for each payment option and price per kilometer.
 * @param price receives latam flight fee.
 * @param debit receives latam debit fee.
 * @param credit receives latam credit fee.
 * @param bitcoin receives latam fee in bitcoins.
 * @param unitPrice receives latam flight per kilometer.
 */
void printLatam(float price, float debit, float credit, float bitcoin, float unitPrice);


#endif /* UTN_H_ */

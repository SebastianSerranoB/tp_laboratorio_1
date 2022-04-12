/**
 * @file arithmeticCalculus.h
 * @version 1.2
 * @date 11/04/2022
 * @author Serrano Belloso Sebastian
 * @title funcionesCalculo_TP1
 * @brief Funciones de calculo aritmetico para el trabajo practico 1-Laboratorio de programacion 1, UTN.
 *
 */

#ifndef ARITHMETICCALCULUS_H_
#define ARITHMETICCALCULUS_H_

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


#endif /* ARITHMETICCALCULUS_H_ */

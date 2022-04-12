/**
 * @file printFunctions.h
 * @version 1.2
 * @date 11/04/2022
 * @author Serrano Belloso Sebastian
 * @title funciones print_TP1
 * @brief Funciones para mostrar texto en consola para el trabajo practico 1-Laboratorio de programacion 1, UTN.
 *
 */

#ifndef PRINTFUNCTIONS_H_
#define PRINTFUNCTIONS_H_

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


#endif /* PRINTFUNCTIONS_H_ */

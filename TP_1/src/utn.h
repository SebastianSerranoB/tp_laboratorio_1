/*
 * utn.h
 * Header file TP1
 *  Created on: 10 abr 2022
 *  Autor: Serrano Sebastian
 */

#ifndef UTN_H_
#define UTN_H_

int mainMenu(float, float, float);
char subMenu(void);

float getFloat(int, int, char);
float calculatePrice(float, float);
float divide(float, float);
float calculateDifference(float, float);

void printAerolineas(float, float, float, float, float);
void printLatam(float, float, float, float, float);


#endif /* UTN_H_ */

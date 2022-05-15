/*
 * input.h
 *
 *  Created on: 21 abr. 2022
 *      Author: Nahuel A
 */

#ifndef INPUT_H_
#define INPUT_H_

int getInt(char mensaje[]);
void getString(char nombre[], char mensaje[]);
void getVector(int numeros[], int size);
char getChar(char mensaje[]);
int confirmChange(char mensaje[]);
int myGets(char* cadena, int longitud);

#endif /* INPUT_H_ */

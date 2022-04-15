/*
 * funciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Nahuel A
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>

int main(void);

/// @fn void mostrarOpciones(int)
/// @brief Permite acceder al menu de opciones
/// @param Toma la opcion elegida
void mostrarOpciones(int);


/// @fn float pedirDato(char*)
/// @brief Pide el dato con mensaje
/// @param Mensaje personalizado para el dato a pedir
/// @return El valor del dato
float pedirDato(char *);


/// @fn float calcularCostoDebito(float)
/// @brief Calcula el precio con el uso de debito
/// @param El tipo de aerolinea
/// @return El costo final de debito
float calcularCostoDebito(float);


/// @fn float calcularCostoCredito(float)
/// @brief Calcula el precio con el uso de credito
/// @param El tipo de aerolinea
/// @return El costo final de credito
float calcularCostoCredito(float);


/// @fn float calcularCostoBitcoin(float)
/// @brief Calcula el precio con el uso de bitcoin
/// @param El tipo de aerolinea
/// @return El costo final con bitcoin
float calcularCostoBitcoin(float);


/// @fn float mostrarPrecioKM(float, float)
/// @brief Calcula y muestra el precio unitario del vuelo
/// @param Cantidad de kilometros
/// @param Tipo de aerolinea
/// @return EL precio unitario
float mostrarPrecioKM(float, float);


/// @fn float mostrarDiferencia(float, float)
/// @brief Calcula la diferencia de precio entre las dos empresas
/// @param Aerolineas
/// @param Latam
/// @return La diferencia entre las 2 empresas
float mostrarDiferencia(float, float);


/// @fn int preguntar(void)
/// @brief Pregunta nuevamente despues de elegir una opcion
/// @return La opcion elegida
int preguntar(void);


/// @fn void imprimirValores(float, float, float, float, float, float, float, float, float, float)
/// @brief Imprime los valores calculados
/// @param El costo de tarjeta de debito de Aerolineas
/// @param El costo de tarjeta de debito de Latam
/// @param El costo de tarjeta de credito de Aerolineas
/// @param El costo de tarjeta de credito de Latam
/// @param El costo de Aerolineas y Latam con bitcoin
/// @param El costo del precio unitario
/// @param La diferencia de precio entre ambas empresas
/// @param El valor ingresado en kilometros
/// @param El valor ingresado en Aerolineas
/// @param El valor ingresado en Latam
void imprimirValores(float, float, float, float, float, float, float, float, float, float);

#endif /* FUNCIONES_H_ */

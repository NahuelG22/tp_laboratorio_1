/*
 ============================================================================
 Name        : TP1.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;

	opcion = preguntar();

	mostrarOpciones(opcion);
}

void mostrarOpciones(int opcion)//char* mensaje, int
{
	float x;
	float y;
	float z;
	float costoTarjetaDebitoY;
	float costoTarjetaDebitoZ;
	float costoTarjetaCreditoY;
	float costoTarjetaCreditoZ;
	float costoBTC;
	float precioUnitario;
	float diferenciaPrecio;
	int ingresoUno;
	int ingresoDos;
	int ingresoTres;

	ingresoUno=0;
	ingresoDos=0;
	ingresoTres=0;

	do
	{
		switch(opcion)
		{
			case 1:
				x=pedirDato("\nIngrese kilometros: ");
				if(x<=0)
				{
					x=pedirDato("Cantidad invalida, ingrese kilometros: \n\n");
				}
				opcion = preguntar();
				if(ingresoUno==0)
				{
					ingresoUno=1;
				}
			break;
			case 2:
				printf("\nIngrese el precio de vuelo.\n");
				y=pedirDato("\nIngrese el precio de Aerolineas: ");
				z=pedirDato("\nIngrese el precio de Latam: ");
				if(y<=0 || z<=0)
				{
					printf("\nDebe ingresar el precio en las 2 aerolineas\n\n");
					opcion = preguntar();
				}
				else
				{
					opcion = preguntar();
				}
				if(ingresoDos==0)
				{
					ingresoDos=1;
				}
			break;
			case 3:
				if(ingresoUno==0 || ingresoDos==0)
				{
					printf("Faltan ingresar datos para calcular, intente de nuevo.\n\n");
					opcion = preguntar();
				}
				else
				{
					costoTarjetaDebitoY=calcularCostoDebito(y);
					costoTarjetaCreditoY=calcularCostoCredito(y);
					costoBTC=calcularCostoBitcoin(y);
					precioUnitario=mostrarPrecioKM(x, y);
					diferenciaPrecio=mostrarDiferencia(y, z);
					costoTarjetaDebitoZ=calcularCostoDebito(z);
					costoTarjetaCreditoZ=calcularCostoCredito(z);
					costoBTC=calcularCostoBitcoin(z);
					precioUnitario=mostrarPrecioKM(x, z);
					diferenciaPrecio=mostrarDiferencia(z, y);
					printf("\nSe han calculado los costos\n\n");
				}
				if(ingresoTres==0)
				{
					ingresoTres=1;
				}
				opcion = preguntar();
			break;
			case 4:
				if(ingresoUno==0 || ingresoDos==0 || ingresoTres==0)
				{
					printf("\nNo se puede informar debido a que no se selecciono alguna opcion anterior.\n\n");
					opcion = preguntar();
				}
				else
				{
					imprimirValores(costoTarjetaDebitoY,  costoTarjetaDebitoZ, costoTarjetaCreditoY, costoTarjetaCreditoZ, costoBTC, precioUnitario, diferenciaPrecio, x, z, y);
					opcion = preguntar();
				}
			break;
			case 5:
				x=7090;
				y=162965;
				z=159339;

				costoTarjetaDebitoY=calcularCostoDebito(y);
				costoTarjetaCreditoY=calcularCostoCredito(y);
				costoBTC=calcularCostoBitcoin(y);
				precioUnitario=mostrarPrecioKM(x, y);
				diferenciaPrecio=mostrarDiferencia(y, z);
				costoTarjetaDebitoZ=calcularCostoDebito(z);
				costoTarjetaCreditoZ=calcularCostoCredito(z);
				costoBTC=calcularCostoBitcoin(z);
				precioUnitario=mostrarPrecioKM(x, z);
				diferenciaPrecio=mostrarDiferencia(z, y);

				imprimirValores(costoTarjetaDebitoY, costoTarjetaDebitoZ, costoTarjetaCreditoY, costoTarjetaCreditoZ, costoBTC, precioUnitario, diferenciaPrecio, x, z, y);

				opcion = preguntar();
			break;
			case 6:
				printf("\nUsted salio del programa.");
				opcion = 0;
			break;
		}
	}while(opcion!=0);
}

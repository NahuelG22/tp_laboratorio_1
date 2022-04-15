/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Nahuel A
 */
#include "funciones.h"

#define BTC 4606954.55

float pedirDato(char * mensaje)
{
    float dato;
    printf("%s", mensaje);
    scanf("%f", &dato);
    return dato;
}

int preguntar(void)
{
	int opcion;

	printf("¿Que desea ingresar?\n1.Ingresar Kilometros\n2.Ingresar precio de vuelos\n3.Calcular costos\n4.Informar resultados\n5.Carga forzada de datos\n6.Salir\n\nIngresar: ");
	fflush(stdin);
	scanf("%d", &opcion);
	if(opcion<0 || opcion>6)
	{
		printf("Opcion no valida, ¿Que desea ingresar?\n1.Ingresar Kilometros\n2.Ingresar precio de vuelos\n3.Calcular costos\n4.Informar resultados\n5.Carga forzada de datos\n6.Salir\n\nIngresar: ");
		scanf("%d", &opcion);
	}

	return opcion;
}

float calcularCostoDebito(float y)
{
	float descuento;
	float costoFinalDebito;

	descuento=y*10/100;
	costoFinalDebito=y-descuento;

	return costoFinalDebito;
}

float calcularCostoCredito(float aerolinea)
{
	float interes;
	float costoFinalCredito;

	interes=aerolinea*10/100;
	costoFinalCredito=aerolinea+interes;

	return costoFinalCredito;
}

float calcularCostoBitcoin(float aerolinea)
{
	float costoFinalBitcoin;

	costoFinalBitcoin=aerolinea/BTC;

	return costoFinalBitcoin;
}

float mostrarPrecioKM(float x, float aerolinea)
{
	float precioPorKM;

	precioPorKM=aerolinea/x;

	return precioPorKM;
}

float mostrarDiferencia(float primerNumero, float segundoNumero)
{
	float diferencia;

	if(primerNumero<segundoNumero)
	{
		diferencia=segundoNumero-primerNumero;
	}
	else
	{
		if(primerNumero>segundoNumero)
		{
			diferencia=primerNumero-segundoNumero;
		}
	}

	return diferencia;
}

void imprimirValores(float costoTarjetaDebitoY, float costoTarjetaDebitoZ, float costoTarjetaCreditoY, float costoTarjetaCreditoZ, float costoBTC, float precioUnitario, float diferenciaPrecio, float x, float z, float y)
{
	printf("\nKMs Ingresados: %.2f\n", x);
	printf("\nPrecio Aerolineas: $ %.2f\n", y);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", costoTarjetaDebitoY);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", costoTarjetaCreditoY);
	printf("c) Precio pagando con bitcoin: $ %f BTC\n", costoBTC);
	printf("d) Precio unitario: $ %.2f\n", precioUnitario);
	printf("\nPrecio Latam: $%.2f", z);
	printf("\nPrecio Aerolineas: $ %f\n", y);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", costoTarjetaDebitoZ);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", costoTarjetaCreditoZ);
	printf("c) Precio pagando con bitcoin: $ %f BTC\n", costoBTC);
	printf("d) Precio unitario: $ %.2f\n", precioUnitario);
	printf("\nLa diferencia de precio es: $ %.2f \n", diferenciaPrecio);
}


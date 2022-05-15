/*
 ============================================================================
 Name        : TP2.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "ArrayPassenger.h"
#include "input.h"

int main(void)
{
	setbuf(stdout, NULL);
	Passenger listaPasajeros[5];
	Passenger listaPasajerosInit[5]={{2590, "Mariano", "Alvarez",5400.00, 0, "LM 2090", 1, 0}, {1012, "Pedro", "Gomez",10000.00, 0, "H 300", 1, 0}, {1456, "Jorge", "Reyna", 3000.00, 1, "P 2200", 0, 0}, {1367, "Lionel", "Maradona", 25000, 1, "J 220", 0, 0}, {1536, "Cristiano", "Pele", 2300.3, 1, "PH 100", 0, 0}};
	int opcion;
	int retorno;
	int id;
	char nombre[15];
	char apellido[15];
	float precio;
	int tipoPasajero;
	char codigo[10];
	int largoLista;

	id=1000;
	opcion=0;
	largoLista=2000;
	retorno=initPassengers(listaPasajeros, largoLista);
	printf("1. Altas\n2. Modificar\n3. Baja\n4. Informar\n5. Alta forzada\n\nIngresar: ");
	scanf("%d", &opcion);
	do
	{
		switch(opcion)
		{
			case 1:
				id++;
				printf("\nIngrese nombre: \n");
				fflush(stdin);
				gets(nombre);
				printf("\nIngrese el apellido: \n");
				fflush(stdin);
				gets(apellido);
				printf("\nIngrese el precio del vuelo\n");
				scanf("%f", &precio);
				printf("\nIngrese el tipo de pasajero; 0 para primera clase, 1 para ejecutivo: ");
				scanf("%d", &tipoPasajero);
				printf("\nIngrese el codigo de vuelo: \n");
				fflush(stdin);
				gets(codigo);
				retorno=addPassenger(listaPasajeros, largoLista, id, nombre, apellido, precio, tipoPasajero, codigo);
			break;
			case 2:
				retorno=printPassenger(listaPasajeros,largoLista);
				retorno=modifyPassenger(listaPasajeros,largoLista);
				if(retorno==-1)
				{
					printf("\nLa lista no se modifico, no se encontro id\n");
				}
			break;
			case 3:
				retorno=printPassenger(listaPasajeros, largoLista);
				printf("Ingrese el id del pasajero a eliminar: ");
				scanf("%d", &id);
				retorno=removePassenger(listaPasajeros, largoLista, id);
				if(retorno==-1)
				{
					printf("\nNo se pudo eliminar al pasajero, no se encontro id\n");
				}
			break;
			case 4:
				retorno=informAboutPassengers(listaPasajeros, largoLista);
			break;
			case 5:
				retorno=forcedPassengersAdd(listaPasajeros, listaPasajerosInit, largoLista);
				retorno=printPassenger(listaPasajeros, largoLista);
			break;
		}
	}while(opcion!=6);
	return 0;
}



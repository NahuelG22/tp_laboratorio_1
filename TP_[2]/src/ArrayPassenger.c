/*
 * ArrayPassenger.c
 *
 *  Created on: 8 may. 2022
 *      Author: Nahuel A
 */

#include "ArrayPassenger.h"
#include "input.h"

int initPassengers(Passenger list[], int len)
{
	int index;

	index=-1;

	for(int i=0; i<len; i++)
	{
		list[i].isEmpty=1;
	}

	if(len>0 && len<=2000)
	{
		index=0;
	}

	return index;
}

int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==1)
		{
			list[i].id=id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].price=price;
			list[i].typePassenger=typePassenger;
			strcpy(list[i].flycode, flycode);
			list[i].isEmpty=0;
		}
	}
	return 0;
}

int findPassengerById(Passenger list[], int len,int id)
{
	int index=-1;
	for(int i=0; i<len; i++)
	{
		for(int j=i+1; j<len; j++)
		{
			if(list[i].isEmpty==0 && list[i].id==list[j].id)
			{
				index=i;
				break;
			}
		}
	}
	return index;
}

int removePassenger(Passenger list[], int len, int id)
{
	int remove;
	remove=-1;

	for(int i=0; i<len; i++)
	{
		if(list[i].id==id)
		{
			list[i].isEmpty=1;
			remove=1;
			break;
		}
	}
	return remove;
}

int sortPassengers(Passenger list[], int len, int order)//pedir orden- 1: ascendente-0:descendente
{
	Passenger aux;
	for(int i=0; i<len-1; i++)
	{
		for(int j=i+1; j<len; j++)
		{
			if(order==0)//descendente
			{
				if(strcmp(list[i].lastName,list[j].lastName)>0)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else
				{
					if(strcmp(list[i].lastName,list[j].lastName)==0)
					{
						if(list[i].typePassenger>list[j].typePassenger)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
					}
				}
			}
			if(order==1)
			{
				if(strcmp(list[i].lastName,list[j].lastName)<0)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else
				{
					if(strcmp(list[i].lastName, list[j].lastName)==0)
					{
						if(list[i].typePassenger<list[j].typePassenger)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
					}
				}
			}
		}
	}
	printPassenger(list, len);
	return 0;
}

int printPassenger(Passenger list[], int length)
{
	for(int i=0; i<length; i++)
	{
		if(list[i].isEmpty==0)
		{
			printf("\n%d     |    %s    |    %s   |   %f   |   %s   |   %d   |   %d\n",
				list->id, list->name, list->lastName, list->price,
				list->flycode, list->typePassenger, list->statusFlight);
		}
		else
		{
			printf("Aun no se ingresaron pasajeros");
		}
	}
	return 0;
}

int sortPassengersByCode(Passenger list[], int len, int order)
{
	Passenger aux;
	for(int i=0; i<len-1; i++)
	{
		for(int j=i+1; j<len; j++)
		{
			if(order==0)//descendente
			{
				if(strcmp(list[i].flycode, list[j].flycode)>0 || list[i].isEmpty==1)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else
				{
					if(strcmp(list[i].flycode, list[j].flycode)==0)
					{
						if(list[i].statusFlight>list[j].statusFlight)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
					}
				}
			}
			if(order==1)
			{
				if(strcmp(list[i].flycode, list[j].flycode)<0)
				{
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else
				{
					if(strcmp(list[i].flycode, list[j].flycode)==0)
					{
						if(list[i].statusFlight<list[j].statusFlight)
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
					}
				}
			}
		}
	}
	printPassenger(list, len);
	return 0;
}

int modifyPassenger(Passenger list[], int len)
{
	int id;
	int modificacion;
	int opcion;

	modificacion=printPassenger(list, len);
	modificacion=-1;
	printf("Ingrese el id a modificar: ");
	scanf("%d", &id);

	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==0 && list[i].id==id)
		{
			printf("¿Que desea modificar?\n"
					"1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de pasajero"
					"\n5-Codigo de vuelo");
			scanf("%d", &opcion);
			switch(opcion)
			{
				case 1:
					printf("\nIngrese el nombre: \n");
					fflush(stdin);
					gets(list[i].name);
					modificacion=1;
				break;
				case 2:
					printf("Ingrese el apellido\n");
					fflush(stdin);
					gets(list[i].lastName);
					modificacion=1;
				break;
				case 3:
					printf("Ingrese el nuevo precio: \n");
					scanf("%f", &list[i].price);
					modificacion=1;
				break;
				case 4:
					printf("Ingrese el tipo de pasajero: \n");
					scanf("%d", &list[i].typePassenger);
					modificacion=1;
				break;
				case 5:
					printf("Ingrese el nuevo codigo de vuelo: \n");
					fflush(stdin);
					gets(list[i].flycode);
					modificacion=1;
				break;
			}
		}
	}
	return modificacion;
}

int informAboutPassengers(Passenger list[], int len)
{
	int informar;
	printf("1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
			"2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n"
			"3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
	scanf("%d", &informar);
	switch(informar)
	{
		int order;
		case 1:
			printf("\n¿En que orden desea ver la informacion? 1 ascendente 0 descendente: ");
			scanf("%d", &order);
			informar=sortPassengers(list, len, order);
		break;
		case 2:
			informar=calculateAverage(list, len);
		break;
		case 3:
			printf("\n¿En que orden desea ver la informacion? 1 ascendente 0 descendente: ");
			scanf("%d", &order);
			informar=sortPassengersByCode(list, len, order);
		break;
	}
	return 0;
}

int calculateAverage(Passenger list[], int len)
{
	float acumuladorPrecio;
	float promedioPrecios;
	int acumuladorPromedioSuperado;
	acumuladorPrecio=0;
	acumuladorPromedioSuperado=0;
	for(int i=0; i<len; i++)
	{
		acumuladorPrecio+=list[i].price;//acumulo
	}
	promedioPrecios=acumuladorPrecio/len;
	printf("\nEl precio total de los pasajes es de %f y el promedio es de %f", acumuladorPrecio, promedioPrecios);
	for(int i=0; i<len; i++)
	{
		if(list[i].price>promedioPrecios)
		{
			acumuladorPromedioSuperado++;
		}
	}
	printf("\nLa cantidad de pasajeros que superan el precio promedio es de %d", acumuladorPromedioSuperado);
	return 0;
}

int forcedPassengersAdd(Passenger list[], Passenger listH[],int len)
{
	int retorno;
	for(int i=0; i<5; i++)
	{
		retorno=addPassenger(list, len, listH[i].id, listH[i].name, listH[i].lastName, listH[i].price, listH[i].typePassenger, listH[i].flycode);
	}

	return retorno;
}



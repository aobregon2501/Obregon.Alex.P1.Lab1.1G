/*
 * menuMascotas.c
 *
 *  Created on: 13/05/2022
 *      Author: Alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include "menuMascotas.h"

int menuPrincipal()
{
	int opcion;
	int opcionValida;

	system("cls");
	printf("1. Alta mascota\n");
	printf("2. Modificar mascota\n");
	printf("3. Baja mascota\n");
	printf("4. Listar mascotas\n");
	printf("5. Listar tipos\n");
	printf("6. Listar colores\n");
	printf("7. Listar servicios\n");
	printf("8. Alta trabajo\n");
	printf("9. Listar trabajos\n");

	printf("Ingrese opción: ");
	opcionValida = scanf("%d", &opcion);

	if(opcionValida == 0)
	{
		opcion = 0;
	}

	fflush(stdin);

	return opcion;
}

int menuModificacion()
{
	int opcion;
	int opcionValida;

	system("cls");
	printf("1. Modificar tipo.\n");
	printf("2. Modificar estado de vacunacion.\n");

	printf("Ingrese opción: ");
	opcionValida = scanf("%d", &opcion);

	if(opcionValida == 0)
	{
		opcion = 0;
	}

	fflush(stdin);

	return opcion;
}

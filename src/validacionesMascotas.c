/*
 * validacionesMascotas.c
 *
 *  Created on: 20/05/2022
 *      Author: Alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesMascotas.h"

int validarEntero()
{
	int ingresoValido;
	int numeroInt;

	fflush(stdin);
	ingresoValido = scanf("%d", &numeroInt);

	while(!ingresoValido || numeroInt <= 0)
	{
		printf("Ingreso invalido, vuelva a ingresar el numero: ");
		fflush(stdin);
		ingresoValido = scanf("%d", &numeroInt);
	}

	return numeroInt;
}

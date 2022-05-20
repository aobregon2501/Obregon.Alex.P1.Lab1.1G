/*
 * serviciosMascotas.c
 *
 *  Created on: 20/05/2022
 *      Author: Alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serviciosMascotas.h"

int listarServicios(eServiciosMascotas servicio[], int tamServicio)
{
	int todoOk = 0;
	if(servicio != NULL && tamServicio > 0 ){

		printf("   *** Listado de Servicios ***\n");
		printf("  id           descripcion          precio\n");
		printf("---------------------------------------------\n");

		 for(int i= 0; i < tamServicio; i++){

		   printf("    %4d      %15s\t    %.2f\n",
				   servicio[i].id,
				   servicio[i].descripcion,
				   servicio[i].precio
				   );

		 }
	}
	return todoOk;
}

int validarServicios(eServiciosMascotas vec[], int tamServicio, int id)
{
	int esValido = 0;
	int indice;

	if (buscarServicio(vec, tamServicio, id, &indice) )
	{
		if(indice != -1)
		{
			esValido = 1;
		}
	}
	return esValido;
}

int buscarServicio(eServiciosMascotas vec[], int tamServicio, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tamServicio > 0 )
    {
        *pIndex = -1;
        for(int i = 0; i < tamServicio; i++)
        {
            if(vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

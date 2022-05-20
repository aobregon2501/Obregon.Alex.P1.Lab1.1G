/*
 * tipoMascotas.c
 *
 *  Created on: 20/05/2022
 *      Author: Alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipoMascotas.h"

int listarTipos(eTipoMascotas tipo[], int tamTipos)
{
	int todoOk = 0;
	if(tipo != NULL && tamTipos > 0 ){

		printf("   *** Listado de Tipos ***\n");
		printf("  id      descripcion\n");
		printf("-----------------------\n");

		 for(int i= 0; i < tamTipos; i++){

		   printf("    %4d      %10s\n", tipo[i].id, tipo[i].descripcion);

		 }
	}
	return todoOk;
}

int validarTipo(eTipoMascotas vec[], int tamTipo, int id)
{
	int esValido = 0;
	int indice;

	if (buscarTipo(vec, tamTipo, id, &indice) )
	{
		if(indice != -1)
		{
			esValido = 1;
		}
	}
	return esValido;
}

int buscarTipo(eTipoMascotas vec[], int tamTipo, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tamTipo > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tamTipo; i++)
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

int cargarDescripcionTipo(eTipoMascotas tipos[], int tamTipo, int id, char desc[])
{
	int todoOk = 0;
	if(tipos != NULL && tamTipo > 0 && desc != NULL){

		 for(int i= 0; i < tamTipo; i++){

			if( tipos[i].id == id){
				strcpy( desc, tipos[i].descripcion);
				todoOk = 1;
				break;
			}

		 }
	}
	return todoOk;
}

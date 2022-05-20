/*
 * colorMascotas.c
 *
 *  Created on: 20/05/2022
 *      Author: Alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorMascotas.h"

int listarColores(eColorMascotas color[], int tamColor)
{
	int todoOk = 0;
	if(color != NULL && tamColor > 0 ){

		printf("   *** Listado de Colores ***\n");
		printf("  id      descripcion\n");
		printf("-----------------------\n");

		 for(int i= 0; i < tamColor; i++){

		   printf("    %4d      %10s\n", color[i].id, color[i].nombreColor);

		 }
	}
	return todoOk;
}

int validarColores(eColorMascotas vec[], int tamColor, int id){
 int esValido = 0;
 int indice;

 if (buscarColores(vec, tamColor, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}

int buscarColores(eColorMascotas vec[], int tamColor, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tamColor > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tamColor; i++)
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

int cargarDescripcionColor(eColorMascotas color[], int tamColor, int id, char desc[])
{
	int todoOk = 0;
	if(color != NULL && tamColor > 0 && desc != NULL){

		 for(int i= 0; i < tamColor; i++){

			if( color[i].id == id){
				strcpy( desc, color[i].nombreColor);
				todoOk = 1;
				break;
			}

		 }
	}
	return todoOk;
}

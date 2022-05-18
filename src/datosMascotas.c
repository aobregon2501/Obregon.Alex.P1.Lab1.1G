/*
 * datosMascotas.c
 *
 *  Created on: 13/05/2022
 *      Author: Alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include "datosMascotas.h"
#include "tipoMascotas.h"
#include "colorMascotas.h"

int altaMascota(eDatosMascotas vec[], int tam, eTipoMascotas tipos[], int tamTipos, eColorMascotas color[], int tamColor, int* pNextId)
{
	int todoOk = 0;
	int indice;
	int idTipo;
	int idColor;
	eDatosMascotas nuevaMascota;

	if( vec != NULL && pNextId != NULL && tipos != NULL && color != NULL && tam > 0 && tamTipos > 0 && tamColor > 0)
	{
		system("cls");
		printf("    *** Alta Mascota ***\n\n");
		buscarLibre(vec, tam, &indice);

		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			nuevaMascota.id = *pNextId;
			printf("Ingrese nombre: ");
			fflush(stdin);
			gets(nuevaMascota.nombre);

			listarTipos(tipos, tamTipos);

			printf("Ingrese el id del tipo: ");
			scanf("%d", &idTipo);

			while(!validarTipo(tipos, tamTipos, idTipo) )
			{
				printf("Id invalido. Reingrese id del tipo: ");
				scanf("%d", &idTipo);
			}

			nuevaMascota.idTipo = idTipo;

			listarColores(color, tamColor);

			printf("Ingrese el id del color: ");
			scanf("%d", &idColor);

			while( !validarColores(color, tamColor, idColor) )
			{
				printf("Id invalido. Reingrese id del color: ");
				scanf("%d", &idColor);
			}

			nuevaMascota.idColor = idColor;

			printf("Ingrese edad: ");
			scanf("%d", &nuevaMascota.edad);

			printf("Ingrese vacunacion('s' o 'n'): ");
			fflush(stdin);
			scanf("%c", &nuevaMascota.vacunado);

			nuevaMascota.isEmpty = 0;

			vec[indice] = nuevaMascota;

			(*pNextId)++;

			todoOk = 1;
		}
	}
	return todoOk;
}



int buscarLibre(eDatosMascotas vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


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


int validarTipo(eTipoMascotas vec[], int tamTipo, int id){
 int esValido = 0;
 int indice;

 if (buscarTipo(vec, tamTipo, id, &indice) ){
    if(indice != -1){
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

int modificarTipo(eDatosMascotas vec[], int tam)
{
	int id;

	eDatosMascotas mascotaModificada;

	listarMascotas(vec, tam);

	printf("Ingrse id de la mascota a modificar");

	scanf("%d", &id);

	while(!validarMascotas(vec, tam, id))
	{
		printf("Id invalido. Reingrese id: ");
		scanf("%d", &id);
	}

	listarTipos(tipos, tamTipos);

	printf("Ingrese el id del tipo: ");
	scanf("%d", &idTipo);

	while(!validarTipo(tipos, tamTipos, idTipo) )
	{
		printf("Id invalido. Reingrese id del tipo: ");
		scanf("%d", &idTipo);
	}

	mascotaModificada.idTipo = idTipo;
}


int modificarVacunacion(eDatosMascotas vec[], int tam)
{
	int id;

	eDatosMascotas mascotaModificada;

	listarMascotas(vec, tam);

	printf("Ingrse id de la mascota a modificar");

	scanf("%d", &id);

	while(!validarMascotas(vec, tam, id))
	{
		printf("Id invalido. Reingrese id: ");
		scanf("%d", &id);
	}

	mascotaModificada.vacuna = id;
}


int listarMascotas(eDatosMascotas vec[], int tam)
{
    int todoOk = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Listado de Mascotas ***\n");
        printf("   id       nombre       tipo  color     edad   vacunacion\n");
        printf("------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                mostrarMascotaFila(vec[i]);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay mascotas en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;

}

void mostrarMascotaFila(eDatosMascotas emp)
{
    printf("    %4d    %10s      %c    %2d    %7.2f   %02d/%02d/%d  %10s\n",
           emp.id,
           emp.nombre,
           emp.idTipo,
           emp.idColor,
           emp.edad,
           emp.vacunado
          );
}

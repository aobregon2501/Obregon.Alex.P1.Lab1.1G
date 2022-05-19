/*
 * datosMascotas.c
 *
 *  Created on: 13/05/2022
 *      Author: Alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datosMascotas.h"



int inicializarMascotas(eDatosMascotas vec[], int tam)
{
	int todoOk = 0;
	if(vec != NULL && tam >0)
	{
		for(int i = 0; i < tam; i++)
		{
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int harcodeo(eDatosMascotas vec[], int tam, int prox)
{
	eDatosMascotas hardc[5] =
	{
		{prox, "Rodolfo", 1004, 5003, 300, 'n', 0},//pez
		{prox + 1, "Zuri", 1000, 5000, 4, 'n', 0},//ave
		{prox + 2, "Cuchi", 1002, 5001, 12, 's', 0},//roedor
		{prox + 3, "Iri", 1000, 5000, 4, 'n', 0},//ave
		{prox + 4, "Jose", 1000, 5004, 15, 's', 0}//ave
	};

	for(int i = 0; i < 5; i++)
	{
		vec[i] = hardc[i];
	}

	return prox + 5;
}

int altaMascota(eDatosMascotas vec[], int tam, eTipoMascotas tipos[], int tamTipos, eColorMascotas color[], int tamColor, int* pNextId)
{
	int todoOk = 0;
	int indice;
	int idTipo;
	int idColor;
	int edad;
	char vacuna;
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

			system("cls");

			listarTipos(tipos, tamTipos);

			printf("Ingrese el id del tipo: ");
			scanf("%d", &idTipo);

			while(!validarTipo(tipos, tamTipos, idTipo) )
			{
				printf("Id invalido. Reingrese id del tipo: ");
				scanf("%d", &idTipo);
			}

			nuevaMascota.idTipo = idTipo;

			system("cls");

			listarColores(color, tamColor);

			printf("Ingrese el id del color: ");
			scanf("%d", &idColor);

			while( !validarColores(color, tamColor, idColor) )
			{
				printf("Id invalido. Reingrese id del color: ");
				scanf("%d", &idColor);
			}

			nuevaMascota.idColor = idColor;

			system("cls");

			printf("Ingrese edad: ");
			scanf("%d", &edad);

			while(edad < 0)
			{
				printf("Edad invalida. Reingrese edad: ");
				scanf("%d", &edad);
			}

			nuevaMascota.edad = edad;

			system("cls");

			printf("Ingrese vacunacion('s' o 'n'): ");
			fflush(stdin);
			scanf("%c", &vacuna);

			while(vacuna != 's' && vacuna != 'n')
			{
				printf("Ingreso no valido. Reingrese vacunacion('s' o 'n'): ");
				fflush(stdin);
				scanf("%c", &vacuna);
			}

			nuevaMascota.vacunado = vacuna;

			system("cls");

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

void modificarTipo(eDatosMascotas vec[], int tam, eTipoMascotas tipo[], int tamTipo)
{
	int id;
	int idTipo;

	printf("Ingrse id de la mascota a modificar: ");

	scanf("%d", &id);

	while(!validarMascota(vec, tam, id))
	{
		printf("Id invalido. Reingrese id: ");
		scanf("%d", &id);
	}

	listarTipos(tipo, tamTipo);

	printf("Ingrese el id del tipo: ");
	scanf("%d", &idTipo);

	while(!validarTipo(tipo, tamTipo, idTipo) )
	{
		printf("Id invalido. Reingrese id del tipo: ");
		scanf("%d", &idTipo);
	}

	for(int i = 0; i < tam; i++)
	{
		if(vec[i].id == id)
		{
			vec[i].idTipo = idTipo;
		}
	}
}


void modificarVacunacion(eDatosMascotas vec[], int tam)
{
	int id;
	char vacuna;

	printf("Ingrse id de la mascota a modificar: ");

	scanf("%d", &id);

	while(!validarMascota(vec, tam, id))
	{
		printf("Id invalido. Reingrese id: ");
		scanf("%d", &id);
	}

	printf("Ingrese vacunacion('s' o 'n'): ");
	fflush(stdin);
	scanf("%c", &vacuna);

	while(vacuna != 's' && vacuna != 'n')
	{
		printf("Ingreso no valido. Reingrese vacunacion('s' o 'n'): ");
		fflush(stdin);
		scanf("%c", &vacuna);
	}

	for(int i = 0; i < tam; i++)
		{
			if(vec[i].id == id)
			{
				vec[i].vacunado = vacuna;
			}
		}
}


int listarMascotas(eDatosMascotas vec[], int tam, eTipoMascotas tipos[], int tamTipo, eColorMascotas colores[], int tamColor)
{
    int todoOk = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
    	ordenarLista(vec, tam, tipos, tamTipo);
        system("cls");
        printf("       *** Listado de Mascotas ***\n");
        printf("   id         nombre          tipo         color  edad          vacunacion\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                mostrarMascotaFila(vec[i], tipos, tamTipo, colores, tamColor);
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

void mostrarMascotaFila(eDatosMascotas emp, eTipoMascotas tipos[], int tamTipo, eColorMascotas colores[], int tamColor)
{
	char descripcionTipo[20];
	char descripcionColor[20];
	char descripcionVacuna[20];

	cargarDescripcionTipo(tipos, tamTipo, emp.idTipo, descripcionTipo);
	cargarDescripcionColor(colores, tamColor, emp.idColor, descripcionColor);
	cargarDescripcionVacuna(emp.vacunado, descripcionVacuna);

    printf("  %4d  %12s    %10s    %10s    %d      \t%12s\n",
           emp.id,
           emp.nombre,
           descripcionTipo,
           descripcionColor,
           emp.edad,
           descripcionVacuna
          );
}



int validarMascota(eDatosMascotas vec[], int tam, int id){
 int esValido = 0;
 int indice;

 if (buscarMascota(vec, tam, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}

int buscarMascota(eDatosMascotas vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
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


int cargarDescripcionVacuna(char v, char desc[])
{
	int todoOk = 0;

	if(v == 's')
	{
		strcpy( desc, "vacunado");
	}
	else
	{
		strcpy( desc, "no vacunado");
	}
	return todoOk;
}


void ordenarLista(eDatosMascotas vec[], int tam, eTipoMascotas tipo[], int tamTipo)
{
	int cont = 0;
	int comp;
	char descripcion[20];
	char descripcionSiguiente[20];
	eDatosMascotas aux;

	for(int i = 0; i < tam; i++)
	{
		if(!(vec[i].isEmpty))
		{
			cont++;
		}
	}


	for(int i = 0; i < cont - 1; i++)
	{
		if(!(vec[i].isEmpty))
		{
			cargarDescripcionTipo(tipo, tamTipo, vec[i].idTipo, descripcion);

			for(int j = i + 1; j < cont; j++)
			{
				if(!(vec[j].isEmpty))
				{
					cargarDescripcionTipo(tipo, tamTipo, vec[j].idTipo, descripcionSiguiente);

					comp = strcmp(descripcion, descripcionSiguiente);

					if(comp > 0)
					{
						aux = vec[i];
						vec[i] = vec[j];
						vec[j] = aux;
						cargarDescripcionTipo(tipo, tamTipo, vec[i].idTipo, descripcion);
						cargarDescripcionTipo(tipo, tamTipo, vec[j].idTipo, descripcionSiguiente);
					}
					else
					{
						if(comp == 0)
						{
							if(strcmp(vec[i].nombre, vec[j].nombre) > 0)
							{
								aux = vec[i];
								vec[i] = vec[j];
								vec[j] = aux;
								cargarDescripcionTipo(tipo, tamTipo, vec[i].idTipo, descripcion);
								cargarDescripcionTipo(tipo, tamTipo, vec[j].idTipo, descripcionSiguiente);
							}
						}
					}
				}

			}
		}

	}
}


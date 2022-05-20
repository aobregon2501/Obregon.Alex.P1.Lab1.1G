/*
 * trabajoMascotas.c
 *
 *  Created on: 20/05/2022
 *      Author: Alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajoMascotas.h"

int altaTrabajos(eTrabajoMascotas trabajos[],int tamTrabajos, int* cantidadTrabajos, eDatosMascotas vec[], eServiciosMascotas servicio[], int tamServicios, int* pNextId, int tam, eTipoMascotas tipos[], int tamTipo, eColorMascotas colores[], int tamColor)
{
	int todoOk = 0;
	int idMascota;
	int idServicio;
	int dia;
	int mes;
	int anio;
	int maxDia;
	eFechaMascotas fecha;
	eTrabajoMascotas nuevoTrabajo;

	if(vec != NULL && pNextId != NULL && trabajos != NULL && tamTrabajos > 0)
	{
		system("cls");
		printf("    *** Alta Trabajo ***\n\n");

		if(*cantidadTrabajos == tamTrabajos)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			nuevoTrabajo.id = *pNextId;

			listarMascotas(vec, tam, tipos, tamTipo, colores, tamColor);

			printf("Ingrese el id de la mascota: ");
			idMascota = validarEntero();

			while(!validarMascota(vec, tam, idMascota) )
			{
				printf("Id invalido. Reingrese id de la mascota: ");
				idMascota = validarEntero();
			}

			nuevoTrabajo.idMascota = idMascota;

			system("cls");

			listarServicios(servicio, tamServicios);

			printf("Ingrese el id del servicio: ");
			idServicio = validarEntero();

			while( !validarServicios(servicio, tamServicios, idServicio) )
			{
				printf("Id invalido. Reingrese id del servicio: ");
				idServicio = validarEntero();
			}

			nuevoTrabajo.idServicio = idServicio;

			system("cls");

			printf("Ingrese anio del trabajo (anio actual 2022): ");
			anio = validarEntero();

			while(anio < 2022)
			{
				printf("Anio invalido. Reingrese el anio: ");
				anio = validarEntero();
			}

			fecha.anio = anio;

			printf("Ingrese mes del trabajo: ");
			mes = validarEntero();

			while(mes < 1 || mes > 12)
			{
				printf("Mes invalido. Reingrese el mes: ");
				mes = validarEntero();
			}

			fecha.mes = mes;

			switch(mes)
			{
				case 2:
					maxDia = 28;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					maxDia = 30;
					break;

				default:
					maxDia = 31;
				break;
			}

			printf("Ingrese dia del trabajo: ");
			dia = validarEntero();

			while(dia <= 0 || dia > maxDia)
			{
				printf("Dia invalido. Reingrese el dia: ");
				dia = validarEntero();
			}

			fecha.dia = dia;

			nuevoTrabajo.fTrabajo = fecha;

			trabajos[*cantidadTrabajos] = nuevoTrabajo;

			(*cantidadTrabajos)++;
			(*pNextId)++;

			printf("Trabajo cargado con exito.\n");
			todoOk = 1;
		}
	}
	return todoOk;
}

int listarTrabajos(eTrabajoMascotas trabajos[], int cantidadTrabajos, eDatosMascotas vec[], int tam, eServiciosMascotas servicio[], int tamServicios)
{
	int todoOk = 0;
	char nombreTrabajo[20];
	char servicioTrabajo[20];
	float precioTrabajo;

	if(trabajos != NULL && cantidadTrabajos > 0){

		printf("   *** Listado de Trabajos ***\n");
		printf("   id             nombre                servicio       precio        fecha\n");
		printf("----------------------------------------------------------------------------\n");

		 for(int i= 0; i < cantidadTrabajos; i++)
		 {
			 buscarNombreYServicio(vec, tam, trabajos[i].idMascota, nombreTrabajo, servicio, tamServicios, trabajos[i].idServicio, servicioTrabajo, &precioTrabajo);

			 printf("    %4d      %10s\t    %15s    $%.2f   %2d/%2d/%4d\n",
				   trabajos[i].id,
				   nombreTrabajo,
				   servicioTrabajo,
				   precioTrabajo,
				   trabajos[i].fTrabajo.dia,
				   trabajos[i].fTrabajo.mes,
				   trabajos[i].fTrabajo.anio
				   );

		 }

		 todoOk = 1;
	}
	else
	{
		printf("No hay trabajos cargados.\n");
	}
	return todoOk;
}


int buscarNombreYServicio(eDatosMascotas vec[], int tam, int idMascota, char nombreT[], eServiciosMascotas servicio[], int tamServicio, int idServicio, char servicioT[], float* precio)
{
	int todoOk = 0;
	if(vec != NULL && tam > 0 && servicio != NULL && tamServicio > 0 && nombreT != NULL && servicioT != NULL){

		 for(int i= 0; i < tam; i++){

			if( vec[i].id == idMascota){
				strcpy( nombreT, vec[i].nombre);
				todoOk = 1;
				break;
			}

		 }

		 for(int i= 0; i < tamServicio; i++){

			if( servicio[i].id == idServicio){
				strcpy( servicioT, servicio[i].descripcion);
				*precio = servicio[i].precio;
				todoOk = 1;
				break;
			}

		 }
	}
	return todoOk;
}

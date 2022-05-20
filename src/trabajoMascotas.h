/*
 * trabajoMascotas.h
 *
 *  Created on: 13/05/2022
 *      Author: Alumno
 */

#include "datosMascotas.h"

#ifndef TRABAJOMASCOTAS_H_
#define TRABAJOMASCOTAS_H_

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFechaMascotas fTrabajo;
} eTrabajoMascotas;

#endif /* TRABAJOMASCOTAS_H_ */

int altaTrabajos(eTrabajoMascotas trabajos[], int tamTrabajos, int* cantidadTrabajos, eDatosMascotas vec[], eServiciosMascotas servicio[], int tamServicios, int* pNextId, int tam, eTipoMascotas tipos[], int tamTipo, eColorMascotas colores[], int tamColor);
int listarTrabajos(eTrabajoMascotas trabajos[], int cantidadTrabajos, eDatosMascotas vec[], int tam, eServiciosMascotas servicio[], int tamServicios);
int buscarNombreYServicio(eDatosMascotas vec[], int tam, int idMascota, char nombreT[], eServiciosMascotas servicio[], int tamServicio, int idServicio, char servicioT[], float* precio);

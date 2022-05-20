/*
 * serviciosMascotas.h
 *
 *  Created on: 13/05/2022
 *      Author: Alumno
 */

#ifndef SERVICIOSMASCOTAS_H_
#define SERVICIOSMASCOTAS_H_

typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eServiciosMascotas;

#endif /* SERVICIOSMASCOTAS_H_ */

int listarServicios(eServiciosMascotas servicio[], int tamServicio);
int validarServicios(eServiciosMascotas vec[], int tamServicio, int id);
int buscarServicio(eServiciosMascotas vec[], int tamServicio, int id, int* pIndex);

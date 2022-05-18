/*
 * datosMascotas.h
 *
 *  Created on: 13/05/2022
 *      Author: Alumno
 */

#include "fechaMascotas.h"
#include "tipoMascotas.h"
#include "colorMascotas.h"
#include "serviciosMascotas.h"
#include "trabajoMascotas.h"

#ifndef DATOSMASCOTAS_H_
#define DATOSMASCOTAS_H_

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
} eDatosMascotas;



#endif /* DATOSMASCOTAS_H_ */

int altaMascota(eDatosMascotas vec[], int tam, eTipoMascotas tipos[], int tamTipos, eColorMascotas color[], int tamColor, int* pNextId);
int buscarLibre(eDatosMascotas vec[], int tam, int* pIndex);
int listarTipos(eTipoMascotas tipo[], int tamTipos);
int listarColores(eColorMascotas color[], int tamColor);
int validarColores(eColorMascotas vec[], int tamColor, int id);
int buscarColores(eColorMascotas vec[], int tamColor, int id, int* pIndex);
int validarTipo(eTipoMascotas vec[], int tamTipo, int id);
int buscarTipo(eTipoMascotas vec[], int tamTipo, int id, int* pIndex);
int modificarTipo(eDatosMascotas vec[], int tam);
int modificarVacunacion(eDatosMascotas vec[], int tam);
int listarMascotas(eDatosMascotas vec[], int tam);
void mostrarMascotaFila(eDatosMascotas emp);

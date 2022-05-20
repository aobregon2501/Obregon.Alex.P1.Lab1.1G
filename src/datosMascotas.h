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

int altaMascota(eDatosMascotas vec[], int tam, eTipoMascotas tipos[], int tamTipos, eColorMascotas color[], int tamColor, int* pNextId, int* flagIngreso);
int buscarLibre(eDatosMascotas vec[], int tam, int* pIndex);
int listarTipos(eTipoMascotas tipo[], int tamTipos);
int listarColores(eColorMascotas color[], int tamColor);
int validarColores(eColorMascotas vec[], int tamColor, int id);
int buscarColores(eColorMascotas vec[], int tamColor, int id, int* pIndex);
int validarTipo(eTipoMascotas vec[], int tamTipo, int id);
int buscarTipo(eTipoMascotas vec[], int tamTipo, int id, int* pIndex);
void modificarTipo(eDatosMascotas vec[], int tam, eTipoMascotas tipo[], int tamTipo);
void modificarVacunacion(eDatosMascotas vec[], int tam);
int listarMascotas(eDatosMascotas vec[], int tam, eTipoMascotas tipos[], int tamTipo, eColorMascotas colores[], int tamColor);
void mostrarMascotaFila(eDatosMascotas emp, eTipoMascotas tipos[], int tamTipo, eColorMascotas colores[], int tamColor);
void mostrarMascota(eDatosMascotas emp, eTipoMascotas tipos[], int tamTipo, eColorMascotas colores[], int tamColor);
int validarMascota(eDatosMascotas vec[], int tam, int id);
int buscarMascota(eDatosMascotas vec[], int tam, int id, int* pIndex);
int cargarDescripcionTipo(eTipoMascotas tipos[], int tamTipo, int id, char desc[]);
int cargarDescripcionColor(eColorMascotas color[], int tamColor, int id, char desc[]);
int cargarDescripcionVacuna(char v, char desc[]);
int inicializarMascotas(eDatosMascotas vec[], int tam);
int harcodeo(eDatosMascotas vec[], int tam, int* pNextId, int* flagIngreso);
void ordenarLista(eDatosMascotas vec[], int tam, eTipoMascotas tipo[], int tamTipo);
int listarServicios(eServiciosMascotas servicio[], int tamServicio);
int bajaMascota(eDatosMascotas vec[], int tam, eTipoMascotas tipo[], int tamTipo, eColorMascotas colores[], int tamColores);

int altaTrabajos(eTrabajoMascotas trabajos[], int tamTrabajos, int* cantidadTrabajos, eDatosMascotas vec[], eServiciosMascotas servicio[], int tamServicios, int* pNextId, int tam, eTipoMascotas tipos[], int tamTipo, eColorMascotas colores[], int tamColor);
int validarServicios(eServiciosMascotas vec[], int tamServicio, int id);
int buscarServicio(eServiciosMascotas vec[], int tamServicio, int id, int* pIndex);
int buscarNombreYServicio(eDatosMascotas vec[], int tam, int idMascota, char nombreT[], eServiciosMascotas servicio[], int tamServicio, int idServicio, char servicioT[], float* precio);

int listarTrabajos(eTrabajoMascotas trabajos[], int cantidadTrabajos, eDatosMascotas vec[], int tam, eServiciosMascotas servicio[], int tamServicios);
int buscarNombreYServicio(eDatosMascotas vec[], int tam, int idMascota, char nombreT[], eServiciosMascotas servicio[], int tamServicio, int idServicio, char servicioT[], float* precio);

int validarEntero();

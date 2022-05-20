/*
 * tipoMascotas.h
 *
 *  Created on: 13/05/2022
 *      Author: Alumno
 */
#ifndef TIPOMASCOTAS_H_
#define TIPOMASCOTAS_H_

typedef struct{
    int id;
    char descripcion[20];
}eTipoMascotas;

#endif /* TIPOMASCOTAS_H_ */

int listarTipos(eTipoMascotas tipo[], int tamTipos);
int validarTipo(eTipoMascotas vec[], int tamTipo, int id);
int buscarTipo(eTipoMascotas vec[], int tamTipo, int id, int* pIndex);
int cargarDescripcionTipo(eTipoMascotas tipos[], int tamTipo, int id, char desc[]);

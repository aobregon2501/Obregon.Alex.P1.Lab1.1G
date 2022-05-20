/*
 * colorMascotas.h
 *
 *  Created on: 13/05/2022
 *      Author: Alumno
 */


#ifndef COLORMASCOTAS_H_
#define COLORMASCOTAS_H_

typedef struct{
    int id;
    char nombreColor[20];
}eColorMascotas;

#endif /* COLORMASCOTAS_H_ */

int listarColores(eColorMascotas color[], int tamColor);
int validarColores(eColorMascotas vec[], int tamColor, int id);
int buscarColores(eColorMascotas vec[], int tamColor, int id, int* pIndex);
int cargarDescripcionColor(eColorMascotas color[], int tamColor, int id, char desc[]);

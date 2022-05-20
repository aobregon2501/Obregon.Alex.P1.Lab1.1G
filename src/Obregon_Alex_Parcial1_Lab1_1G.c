#include <stdio.h>
#include <stdlib.h>
#include "menuMascotas.h"
#include "fechaMascotas.h"
#include "tipoMascotas.h"
#include "colorMascotas.h"
#include "datosMascotas.h"
#include "serviciosMascotas.h"
#include "trabajoMascotas.h"
#include "validacionesMascotas.h"

#define TAM_MASCOTAS 8
#define ID_MASCOTAS 6000
#define TAM_TIPOS 5
#define TAM_COLORES 5
#define TAM_SERVICIOS 3
#define TAM_TRABAJOS 20
#define ID_TRABAJOS 13000

int main(void) {

	setbuf(stdout, NULL);

	int proximoId = ID_MASCOTAS;
	int proximoIdTrabajo = ID_TRABAJOS;
	int cantidadTrabajos = 0;
	int flagIngreso = 0;

	eDatosMascotas lista[TAM_MASCOTAS];
	inicializarMascotas(lista, TAM_MASCOTAS);
	harcodeo(lista, TAM_MASCOTAS, &proximoId, &flagIngreso);

	eTrabajoMascotas trabajos[TAM_TRABAJOS];

	eTipoMascotas tipos[TAM_TIPOS] =
	{
		{1000, "Ave" },
		{1001, "Perro" },
		{1002, "Roedor" },
		{1003, "Gato" },
		{1004, "Pez" }
	};

	eColorMascotas colores[TAM_COLORES] =
	{
		{5000, "Negro" },
		{5001, "Blanco" },
		{5002, "Rojo" },
		{5003, "Gris" },
		{5004, "Azul" }
	};

	eServiciosMascotas servicios[TAM_SERVICIOS]=
	{
		{20000, "Corte", 450},
		{20001, "Desparasitado", 800 },
		{20002, "Castrado", 600}
	};


	char salir = 'n';


	do
	{
		switch(menuPrincipal())
		{
			case 1:
				if(altaMascota(lista, TAM_MASCOTAS, tipos, TAM_TIPOS, colores, TAM_COLORES, &proximoId, &flagIngreso))
				{
					printf("Mascota cargada con exito.\n");
				}
				else
				{
					printf("No se pudo cargar la mascota.\n");
				}
				system("pause");
				system("cls");
				break;

			case 2:
				if(flagIngreso)
				{
					switch(menuModificacion())
					{
						case 1:
							listarMascotas(lista, TAM_MASCOTAS, tipos, TAM_TIPOS, colores, TAM_COLORES);
							modificarTipo(lista, TAM_MASCOTAS, tipos, TAM_TIPOS);
							printf("Tipo modificado con exito.\n");

							break;

						case 2:
							listarMascotas(lista, TAM_MASCOTAS, tipos, TAM_TIPOS, colores, TAM_COLORES);
							modificarVacunacion(lista, TAM_MASCOTAS);
							printf("Vacunacion modificada con exito.\n");

							break;
						default:
							printf("Opcion invalida.\n");
							break;
					}
				}
				else
				{
					printf("No se puede utilizar la opcion sin realizar al menos un Alta mascota.\n");
				}
				system("pause");
				system("cls");
				break;

			case 3:
				if(flagIngreso)
				{
					bajaMascota(lista, TAM_MASCOTAS, tipos, TAM_TIPOS, colores, TAM_COLORES);
				}
				else
				{
					printf("No se puede utilizar la opcion sin realizar al menos un Alta mascota.\n");
				}
				system("pause");
				system("cls");
				break;

			case 4:
				listarMascotas(lista, TAM_MASCOTAS, tipos, TAM_TIPOS, colores, TAM_COLORES);
				system("pause");
				system("cls");
				break;

			case 5:
				listarTipos(tipos, TAM_TIPOS);
				system("pause");
				system("cls");
				break;

			case 6:
				listarColores(colores, TAM_COLORES);
				system("pause");
				system("cls");
				break;

			case 7:
				listarServicios(servicios, TAM_SERVICIOS);
				system("pause");
				system("cls");
				break;

			case 8:
				if(flagIngreso)
				{
					altaTrabajos(trabajos, TAM_TRABAJOS, &cantidadTrabajos, lista, servicios, TAM_SERVICIOS, &proximoIdTrabajo, TAM_MASCOTAS, tipos, TAM_TIPOS, colores, TAM_COLORES);
				}
				else
				{
					printf("No se puede utilizar la opcion sin realizar al menos un Alta mascota.\n");
				}
				system("pause");
				system("cls");
				break;

			case 9:
				if(flagIngreso)
				{
					listarTrabajos(trabajos, cantidadTrabajos, lista, TAM_MASCOTAS, servicios, TAM_SERVICIOS);
				}
				else
				{
					printf("No se puede utilizar la opcion sin realizar al menos un Alta mascota.\n");
				}
				system("pause");
				system("cls");
				break;
			case 10:
				salir = 's';
				printf("Programa finalizado.\n");
				break;

			default:
				printf("Opcion invalida.\n");
				system("pause");
				system("cls");
				break;
		}

	}while(salir != 's');

	return EXIT_SUCCESS;
}

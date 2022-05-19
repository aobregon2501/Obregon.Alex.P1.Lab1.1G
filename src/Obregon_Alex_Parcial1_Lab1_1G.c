#include <stdio.h>
#include <stdlib.h>
#include "menuMascotas.h"
#include "fechaMascotas.h"
#include "tipoMascotas.h"
#include "colorMascotas.h"
#include "datosMascotas.h"
#include "serviciosMascotas.h"
#include "trabajoMascotas.h"

#define TAM_MASCOTAS 8
#define INICIO_ID 100
#define TAM_TIPOS 5
#define TAM_COLORES 5
#define TAM_SERVICIOS 3

int main(void) {

	setbuf(stdout, NULL);

	int proximoId = INICIO_ID;

	eDatosMascotas lista[TAM_MASCOTAS];

	inicializarMascotas(lista, TAM_MASCOTAS);

	proximoId = harcodeo(lista, TAM_MASCOTAS, INICIO_ID);

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
				if(altaMascota(lista, TAM_MASCOTAS, tipos, TAM_TIPOS, colores, TAM_COLORES, &proximoId))
				{
					printf("Mascota cargada con exito.\n");
				}
				else
				{
					printf("No se pudo cargar la mascota.\n");
				}
				break;

			case 2:
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

				break;

			case 3:
				printf("3");
				break;

			case 4:
				listarMascotas(lista, TAM_MASCOTAS, tipos, TAM_TIPOS, colores, TAM_COLORES);
				break;

			case 5:
				listarTipos(tipos, TAM_TIPOS);
				break;

			case 6:
				listarColores(colores, TAM_COLORES);
				break;

			case 7:
				listarServicios(servicios, TAM_SERVICIOS);
				break;

			case 8:
				printf("8");
				break;

			case 9:
				printf("9");
				break;

			default:
				printf("Opcion invalida.\n");
				break;
		}

		system("pause");
		system("cls");

	}while(salir != 's');

	return EXIT_SUCCESS;
}

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
#define TAM_TIPO 5
#define TAM_COLOR 5
#define TAM_SERVICIOS 3

int main(void) {

	setbuf(stdout, NULL);

	int proximoId = 1000;

	eDatosMascotas lista[TAM_MASCOTAS];

	eTipoMascotas tipos[TAM_TIPO] =
	{
		{1000, "Ave" },
		{1001, "Perro" },
		{1002, "Roedor" },
		{1003, "Gato" },
		{1004, "Pez" }
	};

	eColorMascotas color[TAM_COLOR] =
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
				if(altaMascota(lista, TAM_MASCOTAS, tipos, TAM_TIPO, color, TAM_COLOR, &proximoId))
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
						if(modificarTipo())
						{
							printf("Tipo modificado con exito.\n");
						}
						else
						{
							printf("No se pudo modificar el tipo.\n");
						}
						break;

					case 2:
						if(modificarVacunacion())
						{
							printf("Vacunacion modificada con exito.\n");
						}
						else
						{
							printf("No se pudo modificar la vacunacion.\n");
						}
						break;

					default:
						printf("Opcion invalida.\n");
				}

				break;

			case 3:
				printf("3");
				break;

			case 4:
				printf("4");
				break;

			case 5:
				printf("5");
				break;

			case 6:
				printf("6");
				break;

			case 7:
				printf("7");
				break;

			case 8:
				printf("8");
				break;

			case 9:
				printf("9");
				break;

			default:
				printf("Opcion invalida.\n");
		}

	}while(salir != 's');

	return EXIT_SUCCESS;
}

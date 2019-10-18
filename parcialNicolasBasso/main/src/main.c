#include <stdio.h>
#include <stdlib.h>

#include "Cliente.h"
#include "Informes.h"
#include "Recoleccion.h"

#define TAMANIO_CLIENTES 100
#define TAMANIO_PEDIDOS 1000
#define TEXT_SIZE 51

int menu();

int main(void) {
	fflush(stdin);
	char continuar = 's';
	int idSeleccionado;
	int posicion;

	int id;
	char nombre[TEXT_SIZE];
	int cuit;
	char direccion[TEXT_SIZE];
	char localidad[TEXT_SIZE];
	int isEmpty;
	Cliente clientes[TAMANIO_CLIENTES];
//			{0,"Telefonica",30112233445,"Lima 1234","CABA",1},
//			{1,"DATASOFT",30445566776,"Corrientes 2547","CABA",1},
//			{2,"NESTLE",30889955219,"cucha cucha 555","LANUS",1},
//			{3,"TERRABUSI",30567814235,"rocha 784","QUILMES",1},
//			{4,"DIA",31545812533,"Mitre 750","AVELLANEDA",1},
//			{5,"QUILMES","30-51485759-6","Crocha 741","QUILMES",1},
//			};
	iniciarClientes(clientes, TAMANIO_CLIENTES);

	Recoleccion recolecciones[TAMANIO_PEDIDOS];
	iniciarRecolecciones(recolecciones, TAMANIO_PEDIDOS);
	int countIDClientes = 0;
	int countIDRecolecciones = 0;

	do {
		switch (menu()) {
		case 1:
			printf("\nAlta cliente\n\n");
			if (altaCliente(clientes, TAMANIO_CLIENTES, &countIDClientes) == 0)
				printf("\nSe ha efectuado el alta del cliente.\n\n");
			else
				printf("\nNo se efectuo el alta del cliente.\n\n");
			break;
		case 2:
			printf("\nModificar datos de cliente\n\n");
			imprimirClientes(clientes, TAMANIO_CLIENTES);
			if (modificarCliente(clientes, TAMANIO_CLIENTES) == 0)
				printf("\nSe ha efectuado la modificacion del cliente.\n\n");
			else
				printf("\nNo se efectuo la modificacion del cliente.\n\n");
			break;
		case 3:
			printf("\nBaja de cliente\n\n");
			imprimirClientes(clientes, TAMANIO_CLIENTES);
			if (bajaCliente(clientes, TAMANIO_CLIENTES) == 0)
				printf("\nSe ha efectuado la baja del cliente.\n\n");
			else
				printf("\No se efectuo la baja del cliente.\n\n");
			break;
		case 4:
			printf("\nCrear pedido de recoleccion\n\n");
			imprimirClientes(clientes, TAMANIO_CLIENTES);

			fflush(stdin);
			scanf("%d", &idSeleccionado);

			if (buscarCliente(clientes, TAMANIO_CLIENTES, idSeleccionado,
					&posicion) == -1) {
				printf("\nNo existe este ID");
			} else {
				if (altaRecolecciones(recolecciones, TAMANIO_PEDIDOS,
						&countIDRecolecciones, idSeleccionado) == 0)
					printf(
							"\nSe ha efectuado el alta del pedido de recoleccion.\n\n");
				else
					printf(
							"\nNo se efectuo el alta del pedido de recoleccion.\n\n");
			}

			break;
		case 5:
			printf("\nProcesar residuos\n\n");
			procesaReciduos(recolecciones, TAMANIO_CLIENTES);
			break;
		case 6:
			printf("\nImprimir clientes con pedidos pendientes\n\n");
			imprimirClientesConPendiente(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 7:
			printf("\nImprimir imprimir pedidos pendientes\n\n");
			imprimirClientesConPendiente(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 8:
			printf("\nImprimir imprimir pedidos procesados\n\n");
			imprimirRecoleccionCompletadas(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			printf("\nSalir\n\n");
			break;
		case 9:
			printf("\nImprimir cliente con mas pedidos pendientes\n\n");
			imprimirClienteMasConPendiente(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 10:
			printf("\nImprimir cliente con mas pedidos completados\n\n");
			imprimirClienteMasConCompletado(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 11:
			printf("\nImprimir cliente con mas pedidos\n\n");

			imprimirClienteMasConPedidos(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 12:
			printf("\nImprimir cliente con mas kg procesados\n\n");
			imprimirClienteMasKgProcesados(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 13:
			printf("\nImprimir cliente con menos kg procesados\n\n");
			imprimirClienteMenosKgProcesados(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 14:
			printf("\nImprimir cliente con mas de 1000 kg procesados\n\n");
			imprimirClienteMasCienProcesados(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 15:
			printf("\nImprimir cliente con mas de 1000 kg procesados\n\n");
			imprimirClienteMenosCienProcesados(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 16:
			printf("\nImprimir recoleccionescompletas\n\n");
			imprimirRecoleccionCompletadas(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
			break;
		case 17:
			printf("\nImprimir recoleccionescompletas ConPorcentaje\n\n");

			imprimirRecoleccionCompletadasConPorcentaje(clientes,
					TAMANIO_CLIENTES, recolecciones, TAMANIO_PEDIDOS);
			break;
		case 18:
			printf("\nClientesConPendientePorLocalidad\n\n");

			imprimirClientesConPendientePorLocalidad(clientes, TAMANIO_CLIENTES,
					recolecciones, TAMANIO_PEDIDOS);
		}
		printf("\nDesea continuar 's': ");

	} while (continuar == 's');

	return 0;
}

int menu() {
	int opcion;
	system("cls");
	printf("\nBIENVENIDO\n");
	printf("\n1--Alta cliente\n");
	printf("2--Modificar datos de cliente\n");
	printf("3--Baja de cliente\n");
	printf("4--Crear pedido de recoleccion\n");
	printf("5--Procesar residuos:\n");
	printf("5- Imprimir clientes:\n");
	printf("6--Imprimir pedidos pendientes:\n");
	printf("7--Imprimir imprimir pedidos procesados:\n");
	printf("8--SALIR\n\n");
	printf("9--CLIENTES CON MAS PENDIENTE\n\n");
	printf("10--CLIENTES CON MAS COMPLETADOS\n\n");
	printf("11--CLIENTES CON MAS PEDIDOS\n\n");
	printf("12--cliente con mas kg procesados\n\n");
	printf("13--cliente con menos kg procesados\n\n");
	printf("14--cliente con mas de 10000 kg procesados\n\n");
	printf("15--cliente con menos de 10000 kg procesados\n\n");
	printf("16--	Imprimir recoleccionescompletas\n\n");
	printf("17--	Imprimir recoleccionescompletas ConPorcentaje\n\n");

	printf("\n Ingrese opcion: ");
	scanf("%d", &opcion);
	fflush(stdin);
	return opcion;
}

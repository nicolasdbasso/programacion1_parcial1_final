#include "Recoleccion.h"

#include <stdio.h>

#include "Cliente.h"
#include "Utils.h"


#define TEXT_SIZE 51

void iniciarRecolecciones(Recoleccion recolecciones[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		recolecciones[i].isEmpty = 0;
	}
}

int buscarRecoleccionLibre(Recoleccion recolecciones[], int tamanio,
		int *posicion) /** Si isEmptyBuscado==1 busca isEmpty==1, si isEmptyBuscado==0 busca isEmpty==0 */
{
	int retorno = -1;
	if (recolecciones != NULL && tamanio >= 0 && posicion != NULL) {

		int i;
		for (i = 0; i < tamanio; i++) {
			printf("LLEGUE");
			if (recolecciones[i].isEmpty == 0) {
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int altaRecolecciones(Recoleccion *recolecciones, int len, int *countID,
		int clienteID) {
	int retorno = -1;
	int posicion;
	int kgAProcesar;
	if (recolecciones != NULL && len > 0) {
		if (buscarRecoleccionLibre(recolecciones, len, &posicion) == -1) {
			printf("\nNo hay lugares vacios");
		} else {
			(*countID)++;
			recolecciones[posicion].id = *countID;
			recolecciones[posicion].clienteId = clienteID;
			recolecciones[posicion].isEmpty = 1;
			recolecciones[posicion].hdpe = 0;
			recolecciones[posicion].ldpe = 0;
			recolecciones[posicion].pp = 0;
			recolecciones[posicion].estado = 0;
			Utils_getNumero("\nKg a procesar: ", " ERROR\n", 1, TEXT_SIZE, 0, 1,
					1, &kgAProcesar);
			recolecciones[posicion].cantKgTotales = kgAProcesar;
			printf("\n ID: %i\n ClienteID asociado: %i\n KG a procesar: %i",
					recolecciones[posicion].id, clienteID,
					recolecciones[posicion].cantKgTotales);
			retorno = 0;
		}
	}
	return retorno;
}

int imprimirRecolecciones(Recoleccion *recolecciones, int length) {

	int retorno = -1;
	int i;
	if (recolecciones != NULL && length >= 0) {
		for (i = 0; i < length; i++) {
			if (recolecciones[i].isEmpty == 0)
				continue;
			else
				printf("\n ID Pedido: %d\n ID Cliente asociado: %d",
						recolecciones[i].id, recolecciones[i].clienteId);
		}
	}
	return retorno;
}

int buscarRecoleccion(Recoleccion recolecciones[], int len, int idSearch,
		int *position) {
	int retorno = -1;
	int i;

	if (recolecciones != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (recolecciones[i].isEmpty == 1
					&& recolecciones[i].id == idSearch) {
				*position = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}





int imprimirRecoleccionPendiente(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
		for (j = 0; j < lengthR; j++) {

			for (i = 0; i < lengthC; i++) {

				if (clientes[i].isEmpty == 0)
					continue;
				else {
					if (recolecciones[j].clienteId == clientes[i].id && recolecciones[j].estado == 0)
							printf(
									"\n ID del Pedido: %d\nKG a procesar: %d\n  ID del Cliente: %d\nNombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
									recolecciones[j].id,recolecciones[j].cantKgTotales,clientes[i].id, clientes[i].nombre,
									clientes[i].cuit, clientes[i].direccion,
									clientes[i].localidad);
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}


int agregarKgObtenidosRecoleccion(Recoleccion recolecciones[], int len) {
	int retorno = -1;
	int position;
	int id;                                      //cambiar si no se busca por ID
	if (recolecciones != NULL && len > 0) {
		Utils_getNumero("\nID a modificar: ", " ERROR\n", 1, TEXT_SIZE, 0, 1, 1,
				&id);
		if (buscarRecoleccion(recolecciones, len, id, &position) == -1) {
			printf("\nNo existe este ID");
		} else {
			recolecciones[position].estado = 1;
			printf("AGREGAR LOS KG OBTENIDOS:");
			Utils_getNumero("\nKg obtenidos de HDPE: ", " ERROR\n", 1,
					TEXT_SIZE, 0, 1, 1, &recolecciones[position].hdpe);
			recolecciones[position].cantKgTotales =recolecciones[position].cantKgTotales - recolecciones[position].hdpe;
			Utils_getNumero("\nKg obtenidos de LDPE: ", " ERROR\n", 1,
					TEXT_SIZE, 0, 1, 1, &recolecciones[position].ldpe);
			recolecciones[position].cantKgTotales =recolecciones[position].cantKgTotales - recolecciones[position].ldpe;
			Utils_getNumero("\nKg obtenidos de PP: ", " ERROR\n", 1, TEXT_SIZE,
					0, 1, 1, &recolecciones[position].pp);
			recolecciones[position].cantKgTotales =recolecciones[position].cantKgTotales - recolecciones[position].pp;
			printf("\nProcesador con exito\n");
			retorno = 0;
		}
	}
	return retorno;

}

#include <stdio.h>

#include "Cliente.h"
#include "Recoleccion.h"



void procesaReciduos(Recoleccion recolecciones[],int tamanio){
	imprimirRecolecciones(recolecciones, tamanio);

	agregarKgObtenidosRecoleccion(recolecciones, tamanio);
}


int imprimirRecoleccionCompletadas(Cliente *clientes, int lengthC,
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
					if (recolecciones[j].clienteId == clientes[i].id && recolecciones[j].estado == 1)
							printf(
									"\n ID del Pedido: %d\nKG del tipo HDPE: %d\n KG del tipo LDPE: %d\n KG del tipo PP: %d\n KG residuales: %d\nID del Cliente: %d\nNombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
									recolecciones[j].id,recolecciones[j].hdpe,recolecciones[j].ldpe,recolecciones[j].pp,recolecciones[j].cantKgTotales,clientes[i].id, clientes[i].nombre,
									clientes[i].cuit, clientes[i].direccion,
									clientes[i].localidad);
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}


int imprimirRecoleccionCompletadasConPorcentaje(Cliente *clientes, int lengthC,
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
					if (recolecciones[j].clienteId == clientes[i].id && recolecciones[j].estado == 1)
							printf(
									"\n ID del Pedido: %d\nCUIT Cliente: %d\n % Reciclado %d\n",
									recolecciones[j].id,clientes[i].cuit,((recolecciones[j].ldpe+recolecciones[j].pp+recolecciones[j].hdpe)/recolecciones[j].cantKgTotales));
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}


int imprimirClientesConPendientePorLocalidad(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	char localidad[TEXT_SIZE];
	int contador= 0;
	int auxId;
	int retorno = -1;
	int i;
	int j;

	Utils_getTexto("Decime la localidad","ERROR",1,
			TEXT_SIZE, 1, &localidad);

	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
		for (j = 0; j < lengthR; j++) {

			for (i = 0; i < lengthC; i++) {

				if (clientes[i].isEmpty == 0 && clientes[i].localidad == localidad)
					continue;
				else {
					if (recolecciones[j].clienteId == clientes[i].id)
						if (recolecciones[j].estado == 0)
							printf(
									"\n ID: %d\n Nombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s \n ID DEL PEDIDO: %d\n",
									clientes[i].id, clientes[i].nombre,
									clientes[i].cuit, clientes[i].direccion,
									clientes[i].localidad, recolecciones[j].id);
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}


int imprimirClientesConMasPendiente(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int contador= 0;
	int auxId;
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
					if (recolecciones[j].clienteId == clientes[i].id)
						if (recolecciones[j].estado == 0)
							printf(
									"\n ID: %d\n Nombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s \n ID DEL PEDIDO: %d\n",
									clientes[i].id, clientes[i].nombre,
									clientes[i].cuit, clientes[i].direccion,
									clientes[i].localidad, recolecciones[j].id);
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}

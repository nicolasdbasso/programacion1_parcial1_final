#include "Cliente.h"

#include <stdio.h>
#include <string.h>

#include "Utils.h"

#define TEXT_SIZE 51


void iniciarClientes(Cliente clientes[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		clientes[i].isEmpty = 0;
	}
}

int altaCliente(Cliente *clientes, int len, int *countID) {
	int retorno = -1;
	int position;
	if (clientes != NULL && len > 0) {
		if (buscarEmptyCliente(clientes, len, &position) == -1) {
			printf("\nNo hay lugares vacios");
		} else {
			(*countID)++;
			clientes[position].id = *countID;
			clientes[position].isEmpty = 1;
			Utils_getNumero("Ingrese cuit: ", " ERROR\n", 1, TEXT_SIZE, 0, 1, 1,
					&clientes[position].cuit);
			Utils_getTexto(" Ingrese nombre de la empresa: ", " ERROR\n", 1,
			TEXT_SIZE, 1, &clientes[position].nombre);
			Utils_getTexto(" Ingrese localidad de la empresa: ", " ERROR\n", 1,
			TEXT_SIZE, 1, &clientes[position].localidad);
			Utils_getTexto(" Ingrese direccion de la empresa: ", " ERROR\n", 1,
			TEXT_SIZE, 1, &clientes[position].direccion);
			printf(
					"\n ID: %d\n Nombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
					clientes[position].id, clientes[position].nombre,
					clientes[position].cuit, clientes[position].direccion,
					clientes[position].localidad);
			retorno = 0;
		}
	}
	return retorno;
}

int buscarEmptyCliente(Cliente array[], int tamanio, int *posicion) /** Si isEmptyBuscado==1 busca isEmpty==1, si isEmptyBuscado==0 busca isEmpty==0 */
{
	int retorno = -1;

	if (array != NULL && tamanio >= 0 && posicion != NULL) {

		int i;
		for (i = 0; i < tamanio; i++) {
			if (array[i].isEmpty == 0) {
				*posicion = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int modificarCliente(Cliente clientes[], int len) {
	int reintentos = 1;
	int retorno = -1;
	int position;
	int id;                                      //cambiar si no se busca por ID
	int opcion;
	if (clientes != NULL && len > 0) {
		Utils_getNumero("\nID a modificar: ", " ERROR\n", 1, TEXT_SIZE, 0, 1, 1,
				&id);
		if (buscarCliente(clientes, len, id, &position) == -1) {
			printf("\nNo existe este ID");
		} else {
			do {
				Utils_getNumero(
						"\n\nSolo puedes modificar la direccion(1) y localidad(2) (1, 2 o 3 para salir): ",
						" ERROR\n", 1, TEXT_SIZE, 0, 1, 1, &opcion);
				switch (opcion) {
				case 1:
					Utils_getTexto("\nIngrese la nueva direccion: ", "\nError",
							1,
							TEXT_SIZE, reintentos,
							&clientes[position].direccion);
					break;
				case 2:
					Utils_getTexto("\nIngrese la nueva localidad: ", "\nError",
							1,
							TEXT_SIZE, reintentos,
							&clientes[position].localidad);
					break;
				default:
					printf("\nOpcion no valida");
				}
			} while (opcion != 3);
			retorno = 0;
		}
	}
	return retorno;

}

int imprimirClientesConPendiente(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
			for (i = 0; i < lengthC; i++) {
				contador = 0;
				if (clientes[i].isEmpty == 0)
					continue;
				else {
					printf("\nID del Cliente: %d\nNombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
														clientes[i].id, clientes[i].nombre,
														clientes[i].cuit, clientes[i].direccion,
														clientes[i].localidad);
					for (j = 0 ; j < lengthR ; j++){
						if (recolecciones[j].isEmpty == 1 && recolecciones[j].clienteId == clientes[i].id && recolecciones[j].estado ==0)
							contador++;
					}
					printf("Cantidad de pedidos pendientes: %d",contador);

				}

			retorno = 0;
		}
	}
	return retorno;
}



int imprimirClienteMasConPendiente(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	int idConMas = 0;
	int contadorAux;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
			for (i = 0; i < lengthC; i++) {


				if (contador > contadorAux)
					idConMas = i-1;


				contador = 0;
				if (clientes[i].isEmpty == 0)
					continue;
				else {
					for (j = 0 ; j < lengthR ; j++){
						if (recolecciones[j].isEmpty == 1 && recolecciones[j].clienteId == clientes[i].id && recolecciones[j].estado ==0)
							contador++;
					}
				}

			retorno = 0;
		}
	}
				printf("\nID del Cliente: %d\nNombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
																		clientes[idConMas].id, clientes[idConMas].nombre,
																		clientes[idConMas].cuit, clientes[idConMas].direccion,
																		clientes[idConMas].localidad);
	return retorno;
}

int imprimirClienteMasConCompletado(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	int idConMas = 0;
	int contadorAux;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
			for (i = 0; i < lengthC; i++) {
				if (contador > contadorAux)
					idConMas = i-1;
				contador = 0;
				if (clientes[i].isEmpty == 0)
					continue;
				else {
					for (j = 0 ; j < lengthR ; j++){
						if (recolecciones[j].isEmpty == 1 && recolecciones[j].clienteId == clientes[i].id && recolecciones[j].estado ==1)
							contador++;
					}
				}

			retorno = 0;
		}
	}
				printf("\nID del Cliente: %d\nNombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
																		clientes[idConMas].id, clientes[idConMas].nombre,
																		clientes[idConMas].cuit, clientes[idConMas].direccion,
																		clientes[idConMas].localidad);
	return retorno;
}

int imprimirClienteMasConPedidos(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	int idConMas = 0;
	int contadorAux;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
			for (i = 0; i < lengthC; i++) {
				if (contador > contadorAux)
					idConMas = i-1;
				contador = 0;
				if (clientes[i].isEmpty == 0)
					continue;
				else {
					for (j = 0 ; j < lengthR ; j++){
						if (recolecciones[j].isEmpty == 1 && recolecciones[j].clienteId == clientes[i].id)
							contador++;
					}
				}

			retorno = 0;
		}
	}
				printf("\nID del Cliente: %d\nNombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
																		clientes[idConMas].id, clientes[idConMas].nombre,
																		clientes[idConMas].cuit, clientes[idConMas].direccion,
																		clientes[idConMas].localidad);
	return retorno;
}


int imprimirClienteMasKgProcesados(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	int idConMas = 0;
	int contadorAux;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
			for (i = 0; i < lengthC; i++) {
				if (contador < recolecciones[j].cantKgTotales)
					idConMas = i-1;
				contador = 0;
				if (clientes[i].isEmpty == 0)
					continue;
				else {
					for (j = 0 ; j < lengthR ; j++){
						if (recolecciones[j].isEmpty == 1 && recolecciones[j].clienteId == clientes[i].id)
							contador = contador + recolecciones[j].cantKgTotales;
					}
				}

			retorno = 0;
		}
	}
				printf("\nID del Cliente: %d\nNombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
																		clientes[idConMas].id, clientes[idConMas].nombre,
																		clientes[idConMas].cuit, clientes[idConMas].direccion,
																		clientes[idConMas].localidad);
	return retorno;
}


int imprimirClienteMenosKgProcesados(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	int idConMas = 0;
	int contadorAux;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
			for (i = 0; i < lengthC; i++) {
				if (contador > recolecciones[j].cantKgTotales)
					idConMas = i-1;
				contador = 0;
				if (clientes[i].isEmpty == 0)
					continue;
				else {
					for (j = 0 ; j < lengthR ; j++){
						if (recolecciones[j].isEmpty == 1 && recolecciones[j].clienteId == clientes[i].id)
							contador =contador + recolecciones[j].cantKgTotales;
					}
				}

			retorno = 0;
		}
	}
				printf("\nID del Cliente: %d\nNombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
																		clientes[idConMas].id, clientes[idConMas].nombre,
																		clientes[idConMas].cuit, clientes[idConMas].direccion,
																		clientes[idConMas].localidad);
	return retorno;
}


int imprimirClienteMasCienProcesados(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	int idConMas = 0;
	int contadordos = 0;
	int contadorAux;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
			for (i = 0; i < lengthC; i++) {
				if (contador > 1000)
					contadordos++;
				contador = 0;
				if (clientes[i].isEmpty == 0)
					continue;
				else {
					for (j = 0 ; j < lengthR ; j++){
						if (recolecciones[j].isEmpty == 1 && recolecciones[j].clienteId == clientes[i].id)
							contador = contador + recolecciones[j].cantKgTotales;
					}
				}

			retorno = 0;
		}
	}
				printf("\nClientes que procesaron mas de 1000: %d",contadordos);
	return retorno;
}



int imprimirClienteMenosCienProcesados(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR) {

	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	int idConMas = 0;
	int contadordos = 0;
	int contadorAux;
	if (clientes != NULL && lengthC >= 0 && recolecciones != NULL
			&& lengthR >= 0) {
			for (i = 0; i < lengthC; i++) {
				if (contador < 1000)
					contadordos++;
				contador = 0;
				if (clientes[i].isEmpty == 0)
					continue;
				else {
					for (j = 0 ; j < lengthR ; j++){
						if (recolecciones[j].isEmpty == 1 && recolecciones[j].clienteId == clientes[i].id)
							contador = contador + recolecciones[j].cantKgTotales;
					}
				}

			retorno = 0;
		}
	}
	printf("\nClientes que procesaron menos de 1000: %d",contadordos);
	return retorno;
}


int imprimirClientes(Cliente *clientes, int length) {

	int retorno = -1;
	int i;
	if (clientes != NULL && length >= 0) {
		for (i = 0; i < length; i++) {
			if (clientes[i].isEmpty == 0)
				continue;
			else
				printf(
						"\n ID: %d\n Nombre de la empresa: %s\n CUIT: %d\n Direccion: %s\n Localidad: %s",
						clientes[i].id, clientes[i].nombre, clientes[i].cuit,
						clientes[i].direccion, clientes[i].localidad);
		}
		retorno = 0;
	}
	return retorno;
}

int buscarPorIdCliente(Cliente clientes[], int tamanio, int idSearch,
		int *position) {
	int retorno = -1;

	if (clientes != NULL && tamanio >= 0) {
		int i;
		for (i = 0; i < tamanio; i++) {
			if (clientes[i].isEmpty == 1) {
				continue;
			} else if (clientes[i].id == idSearch) {
				*position = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int buscarCliente(Cliente clientes[], int len, int idSearch, int *position) {

	int retorno = -1;
	int i;
	if (clientes != NULL && len >= 0) {
		for (i = 0; i < len; i++) {
			if (clientes[i].isEmpty == 1 && clientes[i].id == idSearch) {
				printf("pongo retorno en 0");
				retorno = 0;
				*position = i;
				break;

			}
		}
		return retorno;
	}
}

int bajaCliente(Cliente *clientes, int len) {
	int retorno = -1;
	int position;
	int id;
	if (clientes != NULL && len > 0) {
		Utils_getNumero("\nID a dar de baja: ", " ERROR\n", 1, TEXT_SIZE, 0, 1,
				1, &id);
		if (buscarCliente(clientes, len, id, &position) == -1) {
			printf("\nNo existe este ID");
		} else {
			clientes[position].id = 0;
			clientes[position].cuit = 0;
			strcpy(clientes[position].nombre, "");
			strcpy(clientes[position].direccion, "");
			strcpy(clientes[position].localidad, "");
			clientes[position].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

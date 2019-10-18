#ifndef CLIENTE_H_
#define CLIENTE_H_



#define TEXT_SIZE 51
#include "Recoleccion.h"

typedef struct {
	int id;
	char nombre[TEXT_SIZE];
	int cuit;
	char direccion[TEXT_SIZE];
	char localidad[TEXT_SIZE];
	int isEmpty;
} Cliente;

void iniciarClientes(Cliente clientes[], int tam);
int altaCliente(Cliente *clientes, int len, int *countID);
int buscarClienteLibre(Cliente clientes[], int tam, int *position);
int modificarCliente(Cliente clientes[], int len);
int buscarCliente(Cliente clientes[], int len, int idSearch, int *position);
int bajaCliente(Cliente *clientes, int len);
int buscarEmptyCliente(Cliente array[], int tamanio, int* posicion);
int buscarPorIdCliente(Cliente clientes[], int tamanio, int idSearch, int* position);
int imprimirClientes(Cliente *clientes, int length) ;
int imprimirClientesConPendiente(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR);
int imprimirClienteMasConCompletado(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR);
int imprimirClienteMasConPedidos(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR);

int imprimirClienteMasKgProcesados(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR);
int imprimirClienteMenosKgProcesados(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR);
int imprimirClienteMasCienProcesados(Cliente *clientes, int lengthC,
		Recoleccion *recolecciones, int lengthR);


#endif

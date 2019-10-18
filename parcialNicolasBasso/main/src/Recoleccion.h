#ifndef Recoleccion_H_
#define Recoleccion_H_


typedef struct {
	int id;
	int cantKgTotales;
	int clienteId;
	int hdpe;
	int ldpe;
	int pp;
	int estado; //(0 pendiente || 1 procesado)
	int isEmpty;
} Recoleccion;


int buscarRecoleccion(Recoleccion recolecciones[], int len, int idSearch,
		int *position);

int buscarRecoleccionLibre(Recoleccion recolecciones[], int tam, int *posicion);
void iniciarRecolecciones(Recoleccion recolecciones[], int tam);
int altaRecolecciones(Recoleccion *recolecciones, int len, int *countID,
		int clienteID);
int agregarKgObtenidosRecoleccion(Recoleccion recolecciones[], int len);
int imprimirRecolecciones(Recoleccion *recolecciones, int length);

#endif

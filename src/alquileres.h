
#ifndef ALQUILERES_H_
#define ALQUILERES_H_


#include "cliente.h"
#include "fecha.h"
#include "categoria.h"
#include "juego.h"


typedef struct {
	int id;
	int idCliente;
	int idJuego;
	Fecha fecha;
	int isEmpty;
} Alquiler;


/** funcion para inicializar todos los alquileres
 * param lista de alquileres
 * param tamaño de los alquileres
 *
 * return 1 ok/ 0 error
 */
int initAlquileres(Alquiler aList[], int aLen);

/** funcion para buscar una posicion libre dentro de la lista de alquileres
 * param lista de alquileres
 * param tamaño de los alquileres
 *
 * return -1 error/ > -1 el indice del alquiler en la lista
 */
int searchIsEmptyAlquiler(Alquiler aList[], int aLen);


int addAlquiler(Alquiler aList[], int aLen, int* idAlquiler, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen);


int printAlquileres(Alquiler aList[], int aLen, Cliente cList[], int cLen, Juego jList[], int jLen);

void printAlquiler(Alquiler alquiler, Cliente cList[], int cLen, Juego jList[], int jLen);


#endif /* ALQUILERES_H_ */

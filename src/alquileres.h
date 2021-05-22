
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


/** \brief funcion para inicializar todos los alquileres
 * \param lista de alquileres
 * \param tamaño de los alquileres
 *
 * \return 1 ok/ 0 error
 */
int initAlquileres(Alquiler aList[], int aLen);

/** \brief funcion para buscar una posicion libre dentro de la lista de alquileres
 * \param lista de alquileres
 * \param tamaño de los alquileres
 *
 * \return -1 error/ > -1 el indice del alquiler en la lista
 */
int searchIsEmptyAlquiler(Alquiler aList[], int aLen);

/** \brief funcion para agregar un alquiler
 *  \param aList lista de alquileres
 *  \param aLen tamaño de la lista de alquileres
 *  \param idAlquiler id autoincremental de alquileres
 *  \param cList lista de clientes
 *  \param catList lista de categorias
 *  \param catLen tamaño de la lista de categorias
 *  \param jList lista de juegos
 *  \param jLen tamaño de la lista de juegos
 *
 *  \return 1 ok/ 0 error
 */
int addAlquiler(Alquiler aList[], int aLen, int* idAlquiler, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen);

/** \brief funcion para imprimir la lista de alquileres
 * \param aList lista de alquileres
 * \param aLen tamaño de la lista de alquileres
 * \param cList lista de clientes
 * \param cLen tamaño de la lista de clientes
 * \param catList lista de categorias
 * \param catLen tamaño de la lista de categorias
 * \param jList lista de juegos
 * \param jLen tamaño de la lista de juegos
 *
 * \return 1 ok/ 0 error
 */
int printAlquileres(Alquiler aList[], int aLen, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen);

/** \brief funcion para imprimir un alquiler
 * \param un alquiler de tipo Alquiler
 * \param cList lista de clientes
 * \param cLen tamaño de la lista de clientes
 * \param catList lista de categorias
 * \param catLen tamaño de la lista de categorias
 * \param jLists lista de juegos
 * \param jLen tamaño de la lista de juegos
 *
 * \return void
 */
void printAlquiler(Alquiler alquiler, Cliente cliente, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen);


#endif /* ALQUILERES_H_ */



#ifndef INFORMES_H_
#define INFORMES_H_


#include "cliente.h"
#include "alquileres.h"
#include "categoria.h"
#include "juego.h"

/** \brief funcion para informar Categoria Del Juego Mas Alquilado
 * \param Alquileres aList lista de alquileres
 * \param int aLen tamaño de la lista de alquileres
 * \param Categoria catList lista de categorias
 * \param int catLen tamaño de la lista de categorias
 * \param Juego jList lista de juegos
 * \param int jLen tamaño de la lista de juegos
 *
 * \return int 0 error/ 1 ok
 */
int informarCategoriaDelJuegoMasAlquilado(Alquiler aList[], int aLen, Categoria catList[], int catLen, Juego jList[], int jLen);

/** \brief funcion para informar Sumatoria De Alquileres Por Categoria
 * \param Alquileres aList lista de alquileres
 * \param int aLen tamaño de la lista de alquileres
 * \param Categoria catList lista de categorias
 * \param int catLen tamaño de la lista de categorias
 * \param Juego jList lista de juegos
 * \param int jLen tamaño de la lista de juegos
 *
 * \return int 0 error/ 1 ok
 */
int informarSumatoriaDeAlquileresPorCategoria(Alquiler aList[], int aLen, Categoria catList[], int catLen, Juego jList[], int jLen);

/** \brief funcion para informar Sumatoria De Alquileres Por Cliente
 * \param Alquileres aList lista de alquileres
 * \param int aLen tamaño de la lista de alquileres
 * \param Juego jList lista de juegos
 * \param int jLen tamaño de la lista de juegos
 *
 * \return int 0 error/ 1 ok
 */
int informarSumatoriaDeAlquileresPorCliente(Alquiler aList[], int aLen, Cliente cList[], int cLen, Juego jList[], int jLen, Localidad lList[], int lLen);

/** funcion para informar la cantidad de clientes por localidad
 * \param Cliente cList lista de clientes
 * \param int cLen tamaño de la lista de clientes
 *
 * return int 0 error/ 1 ok
 */
int informarClientesPorLocalidad(Cliente cList[], int cLen, Localidad lList[], int lLen);

/**funcion para informar la cantidad de alquileres por localidad
 * \param Alquileres aList lista de alquileres
 * \param int aLen tamaño de la lista de alquileres
 * \param Cliente cList lista de clientes
 * \param int cLen tamaño de la lista de clientes
 *
 * return int 0 error/ 1 ok
 */
int informarAlquileresPorLocalidad(Alquiler aList[], int aLen, Cliente cList[], int cLen, Localidad lList[], int lLen);

/** \brief funcion para informar Sumatoria Total De todos los Alquileres
 * \param Alquileres aList lista de alquileres
 * \param int aLen tamaño de la lista de alquileres
 * \param Cliente cList lista de clientes
 * \param int cLen tamaño de la lista de clientes
 * \param Categoria catList lista de categorias
 * \param int catLen tamaño de la lista de categorias
 * \param Juego jList lista de juegos
 * \param int jLen tamaño de la lista de juegos
 *
 * \return int 0 error/ 1 ok
 */
int informarSumatoriaTotalDeAlquileres(Alquiler aList[], int aLen, Juego jList[], int jLen);


/** \brief funcion para informar Todos Los Alquileres Hechos Por Un CLiente
 * \param Alquileres aList lista de alquileres
 * \param int aLen tamaño de la lista de alquileres
 * \param Cliente cList lista de clientes
 * \param int cLen tamaño de la lista de clientes
 * \param Categoria catList lista de categorias
 * \param int catLen tamaño de la lista de categorias
 * \param Juego jList lista de juegos
 * \param int jLen tamaño de la lista de juegos
 *
 * \return int 0 error/ 1 ok
 */
int informarTodosLosAlquileresHechosPorUnCLiente(Alquiler aList[], int aLen, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen);

#endif /* INFORMES_H_ */

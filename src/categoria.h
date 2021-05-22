

#ifndef CATEGORIA_H_
#define CATEGORIA_H_

#include "juego.h"


typedef struct {
	int id;
	char descripcion[51];
} Categoria;

/** \brief funcion que se usa para buscar un categoria
 * \param lista de categorias
 * \param tamaño de la lista de categorias
 * \param int id de la categoria a buscar
 *
 * \return -1 error/ > -1 el indice de categoria en la lista
 */
int searchCategoria(Categoria catList[], int catLen, int id);

/** \brief funcion que se usa para imprimir todos las categorias
 * \param lista de categorias
 * \param tamaño de la lista de categorias
 * \return 1 ok / 0 error
 */
int printCategorias(Categoria catList[], int catLen);

/** \brief funcion que imprime una categoria
 * \param categoria de tipo Categoria
 * \return void
 */
void printCategoria(Categoria categoria);

/** \brief funcion para buscar el nombre el juego
 * \param int id de categoria
 * \param lista de categorias
 * \param tamanio de la lista
 * \param donde se va a guardar la descripcion
 * \param importeJuego donde se guarda el valor del juego
 *
 * \return 1 ok/ 0 error
 * */
int loadCategoriaImporteDescripcion(int idJuego, Juego jList[], int jLen, Categoria catList[], int catLen, char descripcion[], float* importeJuego);

#endif /* CATEGORIA_H_ */

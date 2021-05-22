
#ifndef MENU_H_
#define MENU_H_

#include "alquileres.h"
#include "cliente.h"
#include "categoria.h"
#include "juego.h"

/** \brief funcion para seleccionar una opcion
 * \return un entero representando la opcion seleccionada
 */
int menu();

/** \brief  funcion para seleccionar una opcion de los informes
 * \return un entero representando la opcion seleccionada
 */
int informesMenu();

/** \brief funcion para mostrar las condiciones de modificion de un cliente
 * \param lista de clientes
 * \param tamaño de la lsita de cliente
 * \param int indice del cliente en la lista
 * \param int id del cliente
 * param Localidad lista de localidades
 * param int lLen tamaño de la lista de localidades
 *
 * \return 0 error / 1 ok
 */
int showClienteCondicionesMenu(Cliente cList[], int eLen, int index,  int idCliente, Localidad lList[], int lLen);

/** \brief funcion para mostrar el menu de informes
 * \param aList lista de alquileres
 * \param aLen tamaño de la lista de alquileres
 * \param cList lista de clientes
 * \param cLen tamaño de la lista de clientes
 * \param catList lista de categorias
 * \param catLen tamaño de la lista de categorias
 * \param jList lista de juegos
 * \param jLen tamaño de la lista de juegos
 *
 * \return 0 error / 1 ok
 */
int showInformesMenu(Alquiler aList[], int aLen, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen);

/** brief funcion para seleccionar una opcion
 * retorna un entero representando la opcion seleccionada
 */
int clienteConditionsMenu();

/** brief funcion para salir de la app
 * retorna un entero representando la opcion seleccionada
 */
int exitMenu();

#endif /* MENU_H_ */

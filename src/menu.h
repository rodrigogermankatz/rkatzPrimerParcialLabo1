
#ifndef MENU_H_
#define MENU_H_

#include "cliente.h"

/** brief funcion para seleccionar una opcion
 * retorna un entero representando la opcion seleccionada
 */
int menu();

/** brief funcion para mostrar las condiciones de modificion de un cliente
 * param lista de clientes
 * param tamaño de la lsita de cliente
 * param int indice del cliente en la lista
 * param int id del cliente
 */
int showClienteCondicionesMenu(Cliente cList[], int eLen, int index,  int idCliente);

/** brief funcion para seleccionar una opcion
 * retorna un entero representando la opcion seleccionada
 */
int clienteConditionsMenu();

/** brief funcion para salir de la app
 * retorna un entero representando la opcion seleccionada
 */
int exitMenu();

#endif /* MENU_H_ */

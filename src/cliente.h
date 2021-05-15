
#include "biblioteca.h"


#ifndef CLIENTE_H_
#define CLIENTE_H_




typedef struct {
	int id;
	char nombre[50];
	char apellido[50];
	char sexo;
	char telefono[21];
	int isEmpty;
} Cliente;


/** brief funcion que inicializa clientes
 * param de tipo Cliente lista de clientes
 * param int tamaño de la lista
 * return 0 error/ 1 ok
 */
int initClientes(Cliente cList[], int cLen);

/** brief funcion que busca posiciones libres en la lista de clientes
 * param de tipo Cliente lista de clientes
 * param int tamaño de la lista
 * return -1 error/ > -1 el indice del cliente en la lista
 */
int searchIsEmpty(Cliente cList[], int cLen);

/** brief funcion para agregar un nuevo cliente
 * param de tipo Cliente lista de clientes
 * param int tamaño de la lista
 * param puntero int para generar el id autoincremental
 * return 0 error/ 1 ok
 */
int addCliente(Cliente cList[], int cLen, int *idCliente);

/** brief funcion para encontrar un cliente por id
 * param de tipo Cliente lista de clientes
 * param int tamaño de la lista
 * param int id del cliente
 * return -1 error/ > -1 el indice del cliente en la lista
 */
int findClienteById(Cliente cList[], int cLen, int id);

/** brief funcion para modificar un cliente
 * param de tipo Cliente lista de clientes
 * param int tamaño de la lista
 * return 0 error/ 1 ok
 */
int modifyClienteById(Cliente cList[], int cLen);

/** brief funcion para borrar un cliente
 * param de tipo Cliente lista de clientes
 * param int tamaño de la lista
 * return 0 error/ 1 ok
 */
int deleteCliente(Cliente cList[], int cLen);

/** brief funcion para imprimir la lista de clientes
 * param de tipo Cliente lista de clientes
 * param int tamaño de la lista
 * return 0 error/ 1 ok
 */
int printClientes(Cliente cList[], int cLen);

/** brief funcion para imprimir un cliente
 * param cliente de tipo Cliente
 * return void
 */
void printCliente(Cliente cliente);

/** brief funcion para ordernar clientes
 * param lista de clientes
 * param tamaño de lista
 * param orden
 * return 1ok / 0 error
 */
int sortClientes(Cliente cList[], int cLen, int order);

/** funcion para cargar el nombre del cliente
 * param id del cliente
 * param lista de clientes
 * param tamaño de la lista
 * param donde se va a guardar el nombre
 * return 1ok / 0 error
 */
int loadClienteNombre(int id, Cliente cList[], int cLen, char description[]);

#endif /* CLIENTE_H_ */

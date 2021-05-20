/*
 ============================================================================
 Name        : katzRodrigoPrimerParcialLabo1g.c
 Author      : Rodrigo Katz
 Description : Primer parcial Labo 1 g
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "cliente.h"
#include "juego.h"
#include "alquileres.h"
#include "categoria.h"

#define QTY_CLIENTES 5
#define QTY_ALQUILERES 5
#define QTY_CATEGORIAS 5
#define QTY_JUEGOS 5



int main(void) {
	setbuf(stdout, NULL);

	// TODO: define variables
	Cliente clientes[QTY_CLIENTES];
	Alquiler alquileres[QTY_ALQUILERES];


	Categoria categorias[QTY_CATEGORIAS] = { // id, desc
			{500, "Mesa"},
			{501, "Azar"},
			{502, "Estrategia"},
			{503, "Salon"},
			{504, "Magia"}
	};

	Juego juegos[QTY_JUEGOS] = { // codigo, desc, importe, idCategoria
			{100, "Bingo", 5000, 501},
			{101, "TEG" , 4132, 502},
			{102, "Galera", 1231, 504},
			{103, "Pool", 8751, 503},
			{104, "Cartas", 6123, 500}
	};

	char response = 'n';

	int flagInit = 0;
	int flagInitAlquileres = 0;

	int flagAddition = 0;
	int flagAdditionAlquiler = 0;

	int idCliente = 5000;
	int idAlquiler = 2000;

	// TODO: initialize struct array
	flagInit = initClientes(clientes, QTY_CLIENTES);
	flagInitAlquileres = initAlquileres(alquileres, QTY_ALQUILERES);


	do {

		switch(menu()){
		case 1:
			if(flagInit == 1){
				flagAddition = addCliente(clientes, QTY_CLIENTES, &idCliente);
				if(flagAddition == 1){
					printf("\n\tCliente agregado\n\n");
				} else {
					printf("\n\tNo se pudo agregar el cliente\n\n");
				}
			} else {
				printf("\n\tLa lista de clientes tiene que estar inicializada antes de agregar\n\n");
			}
			break;
		case 2:
			if(flagAddition == 1){
				if(modifyClienteById(clientes, QTY_CLIENTES)){
					printf("\n\tEl cliente fue modificado\n\n");
				} else {
					printf("\n\tNo se pudo modificar el cliente\n\n");
				}
			} else {
				printf("\n\tHay que agregar clientes antes de modificar alguno\n\n");
			}

			break;
		case 3:
			if(flagAddition == 1){
				if(deleteCliente(clientes, QTY_CLIENTES)){
					printf("\n\tCliente borrado\n\n");
				} else {
					printf("\n\tEl cliente no se puede borrar\n\n");
				}
			} else {
				printf("\n\tHay que agregar clientes antes de borrar alguno\n\n");
			}
			break;
		case 4:
			if(flagAddition == 1){
				if(printClientes(clientes, QTY_CLIENTES)){
					printf("\n\tClientes listados\n\n");
				} else {
					printf("\n\tNo se puede listar los clientes\n\n");
				}
			} else {
				printf("\n\tNo hay clientes registrados\n\n");
			}
			break;
		case 5:
			if(flagAddition == 1 && flagInitAlquileres == 1){
				flagAdditionAlquiler = addAlquiler(alquileres, QTY_ALQUILERES, &idAlquiler, clientes, QTY_CLIENTES, categorias, QTY_CATEGORIAS, juegos, QTY_JUEGOS);
				if(flagAdditionAlquiler == 1){
					printf("\n\tAlquiler agregado\n\n");
				} else {
					printf("\n\tEl alquiler no pudo ser agregado\n\n");
				}
			} else {
				printf("\n\tLos clientes y los alquileres tienen que estar inicializados para agregar algun alquiler\n\n");
			}
			break;
		case 6:
			if(flagAddition == 1 && flagAdditionAlquiler == 1){
				if(printAlquileres(alquileres, QTY_ALQUILERES, clientes, QTY_CLIENTES, juegos, QTY_JUEGOS)){
					printf("\n\tAlquileres listados\n\n");
				} else {
					printf("\n\tLos alquileres no pudieron ser listados\n\n");
				}
			} else {
				printf("\n\tPara listar los alquileres tiene que haber clientes y alquileres registrados\n\n");
			}

			break;

		case 0:
			response = 'y';
			break;
		default:
			printf("\n\tOpcion invalida. Intente de vuelta");
			fflush(stdin);
			break;
		}

	} while (response != 'y');
	return EXIT_SUCCESS;
}

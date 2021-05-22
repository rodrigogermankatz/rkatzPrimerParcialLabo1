#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "alquileres.h"
#include "cliente.h"
#include "categoria.h"
#include "juego.h"
#include "menu.h"
#include "biblioteca.h"

int initAlquileres(Alquiler aList[], int aLen){
	int toReturn = 0;
	int count = 0;
	if(aList != NULL && aLen > 0){
		for(int i = 0; i < aLen; i++){
			aList[i].isEmpty = 1;
			count++;
		}
		if(count > 0) toReturn = 1;
	}
	return toReturn;
}

int searchIsEmptyAlquiler(Alquiler aList[], int aLen){
	int index = -1;
	if(aList != NULL && aLen > 0){
		for(int i = 0; i < aLen; i++){
			if(aList[i].isEmpty == 1){
				index = i;
				break;
			}
		}
	}
	return index;
}


int addAlquiler(Alquiler aList[], int aLen, int* idAlquiler, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen){
	int toReturn = 0;
		Alquiler auxAlquiler;
		int index = -1;
		int flagJuegoId = 0;
		int flagClienteId = 0;
		int flagDay = 0;
		int flagMonth = 0;
		int flagYear = 0;

		if(aList != NULL && aLen > 0 && idAlquiler != NULL && cList != NULL && cLen > 0 && catList != NULL && catLen > 0 && jList != NULL && jLen > 0){

			index = searchIsEmptyAlquiler(aList, aLen);
			if(index < 0){
				printf("\n\tNo se pueden agregar alquileres por el momento\n\n");
			} else {
				printClientes(cList, cLen, lList, lLen);
				flagClienteId = utn_getInt(&auxAlquiler.idCliente, "Cliente ID", "El ID del cliente debe estar entre 5000 y 5004", 5000, 5004, 3);
				if(findClienteById(cList, cLen, auxAlquiler.idCliente) < 0){
					printf("\n\tEl id del cliente es invalido\n\n");
				}
				printJuegos(jList, jLen);
				flagJuegoId = utn_getInt(&auxAlquiler.idJuego, "Juego ID", "El id del juego tiene que estar entre 100 y 104", 100, 104, 3);
				if(searchJuego(jList, jLen, auxAlquiler.idJuego) < 0){
					printf("\n\tEl id del juego es invalido\n\n");
				}
				printCategorias(catList, catLen);
				flagDay = utn_getInt(&auxAlquiler.fecha.dia, "dia ", "el dia tiene que estar entre 1 & 31", 1, 31, 3);
				flagMonth = utn_getInt(&auxAlquiler.fecha.mes, "mes ", "el mes tiene que estar entre 1 & 12", 1, 12, 3);
				flagYear = utn_getInt(&auxAlquiler.fecha.anio, "año ", "el año tiene que estar entre 1980 & 3000", 1980, 3000, 3);

				if(flagClienteId && flagJuegoId && flagDay && flagMonth && flagYear){
					auxAlquiler.isEmpty = 0;
					auxAlquiler.id =  *idAlquiler;
					aList[index] = auxAlquiler;
					(*idAlquiler)++;
					toReturn = 1;
				} else {
					printf("\n\tEl alquiler no pudo ser creado\n\n");
				}
			}
		}
		return toReturn;
}

int printAlquileres(Alquiler aList[], int aLen, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen){
	int toReturn = 0;
	int count = 0;
	if(aList != NULL && aLen > 0 && cList != NULL && cLen > 0 && catList != NULL && catLen > 0 && jList != NULL && jLen > 0){
		printf("\n\t------------------------------------------------------------------------------------------------------------------------------");
		printf("\n\t                                        LISTA DE ALQUILERES");
		printf("\n\t------------------------------------------------------------------------------------------------------------------------------");
		printf("\n\tID ALQ.    NOMBRE DEL JUEGO       IMPORTE       CATEGORIA          FECHA     ID CLIENTE       NOMBRE DEL CLIENTE    LOCALIDAD");
		printf("\n\t------------------------------------------------------------------------------------------------------------------------------");

		for(int i = 0; i < aLen; i++) {
			if(aList[i].isEmpty == 0){
				for(int c = 0; c < cLen; c++) {
					if(cList[c].isEmpty == 0 && aList[i].idCliente == cList[c].id ){
						printAlquiler(aList[i], cList[c], cList, cLen, catList, catLen, jList, jLen, lList, lLen);
						count++;
					}
					//else {aList[i].isEmpty = 1;}
				}
			}
		}
		if(count < 1) {
			printf("\n\tNo hay alquileres para imprimir\n\n");
		} else{
			toReturn = 1;
		}
		printf("\n\t------------------------------------------------------------------------------------------------------------------------------\n\n");
	}
	return toReturn;
}

void printAlquiler(Alquiler alquiler, Cliente cliente, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen){
	char nombreDelCliente[50];
	char nombreDelJuego[50];
	char descriptionLocalidad[50] = "";
	char descripcionDeCategoria[50];
	float importeJuego;

	if(
	   loadLocalidadDescripcion(cliente.idLocalidad, lList, lLen, descriptionLocalidad) &&
	   loadClienteNombre(alquiler.idCliente, cList, cLen, nombreDelCliente) &&
	   loadJuegoNombre(alquiler.idJuego, jList, jLen, nombreDelJuego) &&
	   loadCategoriaImporteDescripcion(alquiler.idJuego, jList, jLen, catList, catLen, descripcionDeCategoria, &importeJuego)
	   ){
		printf("\n\t%d   %20s      $%.2f      %10s     %02d/%02d/%d       %4d     %15s %15s", alquiler.id, nombreDelJuego, importeJuego, descripcionDeCategoria, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio, alquiler.idCliente, nombreDelCliente, descriptionLocalidad);
	} else {
		printf("\n\tHay un problema con la impresion de los alquileres\n\n");
	}
}



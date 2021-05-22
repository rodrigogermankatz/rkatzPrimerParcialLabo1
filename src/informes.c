#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "informes.h"


int informarCategoriaDelJuegoMasAlquilado(Alquiler aList[], int aLen, Categoria catList[], int catLen, Juego jList[], int jLen){
	int toReturn = 0;
	float importe[catLen];
	char descripcion[catLen][20];
	int count[catLen];
	int max;
	if(aList != NULL && aLen > 0 && catList != NULL && catLen > 0 && jList != NULL && jLen > 0){
		printf("\n\t------------------------------------------");
		printf("\n\tINFORMAR CATEGORIA DEL JUEGO MAS ALQUILADO");
		printf("\n\t------------------------------------------");
		for(int c = 0; c < catLen; c++){
			count[c] = 0;
			importe[c] = 0;
			strcpy(descripcion[c], catList[c].descripcion);
			for(int j = 0; j < jLen; j++){
				if(jList[j].idCategoria == catList[c].id){
					for(int a = 0; a < aLen; a++){
						if(aList[a].isEmpty == 0 && aList[a].idJuego == jList[j].id){
							importe[c] += jList[j].importe;
							count[c]++;
						}
					}
				}
			}
		}
		for(int i = 0; i < catLen ; i++){
			if(i == 0 || count[i] > max){
				max = count[i];
			}
		}
		for(int i = 0; i < catLen ; i++){
			if(count[i] == max){
				printf("\n\tLa categoria mas alquilada fue: %s", descripcion[i]);
				printf("\n\tCantidad de alquileres: %d", count[i]);
				printf("\n\tImporte total %.2f\n\n", importe[i]);
				toReturn = 1;
			}
		}
		printf("\n\t------------------------------------------");
	}
	return toReturn;
}

int informarSumatoriaDeAlquileresPorCategoria(Alquiler aList[], int aLen, Categoria catList[], int catLen, Juego jList[], int jLen){
	int toReturn = 0;
	int idCategoria;
	float total = 0;
	char descripcion[50];

	if(aList != NULL && aLen > 0 && catList != NULL && catLen > 0 && jList != NULL && jLen > 0){
		printCategorias(catList, catLen);
		utn_getInt(&idCategoria, "ID Categoria ", "El ID de la categoria debe ser entre 500 & 504", 500, 504, 3);
		printf("\n\t----------------------------------------------");
		printf("\n\tINFORMAR SUMATORIA DE ALQUILERES POR CATEGORIA");
		printf("\n\t----------------------------------------------");
		for(int c = 0; c < catLen; c++){
			if(catList[c].id == idCategoria){
				strcpy(descripcion, catList[c].descripcion);
				break;
			}
		}
		for(int j = 0; j < jLen; j++){
			if(jList[j].idCategoria == idCategoria){
				for(int a = 0; a < aLen; a++){
					if(aList[a].isEmpty == 0 && jList[j].id == aList[a].idJuego){
						total = total + jList[j].importe;
					}
				}
			}
		}
		if(total > 0){
			printf("\n\tLa categoria: %s", descripcion);
			printf("\n\tTiene la carga total de $%.2f", total);
			toReturn = 1;
		}
		printf("\n\t----------------------------------------------");
	}
	return toReturn;
}

int informarSumatoriaDeAlquileresPorCliente(Alquiler aList[], int aLen, Cliente cList[], int cLen, Juego jList[], int jLen, Localidad lList[], int lLen){
	int toReturn = 0;
	int flag = 0;
	int idCliente;
	int index;
	float total = 0;
	if(aList != NULL && aLen > 0 && cList != NULL && cLen > 0 && jList != NULL && jLen > 0){
		printf("\n\t-------------------------------------------------");
		printf("\n\t   INFORMAR SUMATORIA DE ALQUILERES POR CLIENTE");
		printf("\n\t-------------------------------------------------");
		printClientes(cList, cLen, lList, lLen);
		flag = utn_getInt(&idCliente, "Cliente ID", "El ID del cliente debe ser entre 5000 & 5004", 5000, 5004, 3);
		index = findClienteById(cList, cLen, idCliente);
		if(flag == 0 || index < 0){
			printf("\n\tNo hay cliente con el ID %d\n\n", idCliente);
		} else {
			for(int a = 0; a < aLen; a++){
				if(aList[a].isEmpty ==  0 && cList[index].id == aList[a].idCliente){
					for(int j = 0; j < jLen; j++){
						if(jList[j].id == aList[a].idJuego && aList[a].isEmpty ==  0){
							total = total + jList[j].importe;
						}
					}
				}
			}
		}
		if(total > 0){
			printf("\n\tCLIENTE ID %d DEBE PAGAR: $%.2f", idCliente, total);
			toReturn = 1;
		} else {
			printf("\n\tSe produjo un error al calcular el total");
		}

		printf("\n\t-------------------------------------------------");
	}
	return toReturn;
}

int informarClientesPorLocalidad(Cliente cList[], int cLen, Localidad lList[], int lLen){
	int toReturn = 0;
	int idLocalidad;
	int count = 0;
	char description[50];

	if(cList != NULL && cLen > 0 &&  lList != NULL && lLen > 0){
		printf("\n\t-------------------------------------------------");
		printf("\n\t   CANTIDAD DE CLIENTES POR LOCALIDAD");
		printf("\n\t-------------------------------------------------");
		printLocalidades(lList, lLen);
		utn_getInt(&idLocalidad, "ID Localidad ", "El ID de la Localidad debe ser entre 200 & 204", 200, 204, 3);

		for(int l = 0; l < lLen;  l++){
			if(idLocalidad == lList[l].id){
				for(int c = 0; c < cLen; c++){
					if(lList[l].id == cList[c].idLocalidad && cList[c].isEmpty == 0){
						count++;
					}
				}
			}
		}

		if(loadLocalidadDescripcion(idLocalidad, lList, lLen, description) ){
			printf("\n\tHay clientes %d en la localidad %s", count, description);
			toReturn = 1;
		} else {
			printf("\n\tNo se encontraron clientes registrados en la localidad %s", description);
		}

		printf("\n\t-------------------------------------------------");
	}
	return toReturn;
}

int informarAlquileresPorLocalidad(Alquiler aList[], int aLen, Cliente cList[], int cLen, Localidad lList[], int lLen){
	int toReturn = 0;
	int flag = 0;
	int imprimoFlag = 0;
	int idLocalidad;
	int count = 0;
	char description[50];

	if(aList != NULL && aLen > 0 && cList != NULL && cLen > 0 && lList != NULL && lLen > 0){
		printf("\n\t-------------------------------------------------");
		printf("\n\t INFORMAR CANTIDAD DE ALQUILERES POR LOCALIDAD");
		printf("\n\t-------------------------------------------------");
		imprimoFlag = printLocalidades(lList, lLen);
		flag = utn_getInt(&idLocalidad, "ID Localidad ", "El ID de la Localidad debe ser entre 200 & 204", 200, 204, 3);

		if(flag && imprimoFlag){
			for(int l = 0; l < lLen;  l++){
				for(int c = 0; c < cLen; c++){
					if(idLocalidad == lList[l].id && lList[l].id == cList[c].idLocalidad && cList[c].isEmpty == 0){
						for(int a = 0; a < aLen; a++){
							if(cList[c].id == aList[a].idCliente && aList[a].isEmpty == 0){
								count++;
							}
						}
					}
				}
			}
		}
		if(loadLocalidadDescripcion(idLocalidad, lList, lLen, description) ){
			printf("\n\tSe produjeron %d alquileres en localidad %s", count, description);
			toReturn = 1;
		} else {
			printf("\n\tNo se encontraron alquileres registrados para la localidad %s", description);
		}



		printf("\n\t-------------------------------------------------");
	}
	return toReturn;
}

int informarSumatoriaTotalDeAlquileres(Alquiler aList[], int aLen, Juego jList[], int jLen){
	int toReturn = 0;
	float total = 0;
	if(aList != NULL && aLen > 0 && jList != NULL && jLen > 0){
		printf("\n\t--------------------------------------");
		printf("\n\tINFORMAR SUMATORIA TOTAL DE ALQUILERES");
		printf("\n\t--------------------------------------");
		for(int j = 0; j < jLen; j++){
			for(int a = 0; a < aLen; a++){
				if(aList[a].isEmpty == 0 && jList[j].id == aList[a].idJuego){
					total = total + jList[j].importe;
				}
			}
		}
		if(total > 0){
			printf("\n\tTOTAL A PAGAR: $%.2f", total);
			toReturn = 1;
		} else {
			printf("\n\tSe produjo un error al calcular el total");
		}
		printf("\n\t--------------------------------------");
	}
	return toReturn;
}

int informarTodosLosAlquileresHechosPorUnCLiente(Alquiler aList[], int aLen, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen){
	int toReturn = 0;
	int flag = 0;
	int idCliente;
	int index;
	float total = 0;
	if(aList != NULL && aLen > 0 && cList != NULL && cLen > 0 && catList != NULL && catLen > 0 && jList != NULL && jLen > 0){
		//printClientes(cList, cLen);
		utn_getInt(&idCliente, "Cliente ID", "El ID del cliente debe ser entre 5000 & 5004", 5000, 5004, 3);
		index = findClienteById(cList, cLen, idCliente);
		if(flag == 1 && index < 0){
			printf("\n\tNo hay cliente con el ID %d\n\n", idCliente);
		} else {
			printf("\n\t----------------------------------------------------------------------------------------------------------------");
			printf("\n\t                        INFORMAR TODOS LOS ALQUILERES HECHOS POR CLIENTE");
			printf("\n\t----------------------------------------------------------------------------------------------------------------");
			printf("\n\tID ALQ.    NOMBRE DEL JUEGO       IMPORTE       CATEGORIA          FECHA     ID CLIENTE       NOMBRE DEL CLIENTE");
			printf("\n\t----------------------------------------------------------------------------------------------------------------");
			for(int a = 0; a < aLen; a++){
				if(aList[a].isEmpty ==  0 && cList[index].id == aList[a].idCliente){
					printAlquiler(aList[a], cList[index], cList, cLen, catList, catLen, jList, jLen, lList, lLen);
				}
			}
			for(int a = 0; a < aLen; a++){
				if(aList[a].isEmpty ==  0 && cList[index].id == aList[a].idCliente){
					for(int j = 0; j < jLen; j++){
						if(jList[j].id == aList[a].idJuego && aList[a].isEmpty ==  0){
							total = total + jList[j].importe;
						}
					}
				}
			}
			printf("\n\t----------------------------------------------------------------------------------------------------------------");
			if(total > 0){
				printf("\n\tTOTAL A PARAGR POR ALQUILERS: $%.2f", total);
				toReturn = 1;
			} else {
				printf("\n\tSe produjo un error al calcular el total");
			}
			printf("\n\t----------------------------------------------------------------------------------------------------------------");
		}

	}
	return toReturn;
}

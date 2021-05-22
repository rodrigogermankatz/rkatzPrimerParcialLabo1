#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "juego.h"

int searchJuego(Juego jList[], int jLen, int id){
	int index = -1;
	if(jList != NULL && jLen > 0){
		for(int i = 0; i < jLen; i++){
			if(jList[i].id == id){
				index = i;
				break;
			}
		}
	}
	return index;
}

int printJuegos(Juego jList[], int jLen){
	int toReturn = 0;
	if(jList != NULL && jLen > 0){
		printf("\n\t-------------------------------------------------");
		printf("\n\t              LISTA DE JUEGOS");
		printf("\n\t-------------------------------------------------");
		printf("\n\tID      DESCRIPCION     PRECIO     ID CATEGORIA  ");
		printf("\n\t-------------------------------------------------");
		for(int i = 0; i < jLen; i++){
			printJuego(jList[i]);
		}
		printf("\n\t-------------------------------------------------\n\n");
	}
	return toReturn;
}

void printJuego(Juego juego){
	printf("\n\t%3d  %10s        %7.2f     %3d", juego.id, juego.descripcion, juego.importe, juego.idCategoria);
}


int loadJuegoNombre(int id, Juego jList[], int jLen, char name[]){
	int toReturn = 0;
	if(id >= 100 && id <= 104 && jList != NULL && jLen > 0 && name != NULL){
		for(int i = 0; i < jLen; i++){
			if(jList[i].id == id){
				strcpy(name, jList[i].descripcion);
				toReturn = 1;
				break;
			}
		}
	}
	return toReturn;
}

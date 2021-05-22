#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "categoria.h"



int searchCategoria(Categoria catList[], int catLen, int id){
	int index = -1;
	if(catList != NULL && catLen > 0){
		for(int i = 0; i < catLen; i++){
			if(catList[i].id == id){
				index = i;
				break;
			}
		}
	}
	return index;
}

int printCategorias(Categoria catList[], int catLen){
	int toReturn = 0;
	if(catList != NULL && catLen > 0){
		printf("\n\t------------------------");
		printf("\n\tLISTA DE CATEGORIAS");
		printf("\n\t------------------------");
		printf("\n\tID      DESCRIPCION     ");
		printf("\n\t------------------------");
		for(int i = 0; i < catLen; i++){
			printCategoria(catList[i]);
		}
		printf("\n\t------------------------\n\n");
	}
	return toReturn;
}

void printCategoria(Categoria categoria){
	printf("\n\t%4d  %10s", categoria.id, categoria.descripcion);
}


int loadCategoriaImporteDescripcion(int idJuego, Juego jList[], int jLen, Categoria catList[], int catLen, char descripcion[], float* importeJuego){
	int toReturn = 0;
	int auxCategoria = -1;
	if(idJuego >= 100 && idJuego <= 104 && jList != NULL && jLen > 0 && catList != NULL && catLen > 0 && descripcion != NULL){
		//TODO agarrar el idCategoria del idJuego
		for(int i = 0; i < jLen; i++){
			if(jList[i].id == idJuego){
				auxCategoria = jList[i].idCategoria;
				(*importeJuego) = jList[i].importe;
				break;
			}
		}
		if(auxCategoria >= 500 && auxCategoria <= 504){
			for(int i = 0; i < catLen; i++){
				if(catList[i].id == auxCategoria){
					strcpy(descripcion, catList[i].descripcion);
					toReturn = 1;
					break;
				}
			}
		}

	}
	return toReturn;
}

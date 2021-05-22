#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "localidad.h"

int searchLocalidad(Localidad lList[], int lLen, int id){
	int index = -1;
	if(lList != NULL && lLen > 0){
		for(int i = 0; i < lLen; i++){
			if(lList[i].id == id){
				index = i;
				break;
			}
		}
	}
	return index;
}

int printLocalidades(Localidad lList[], int lLen){
	int toReturn = 0;
	if(lList != NULL && lLen > 0){
		printf("\n\t------------------------");
		printf("\n\tLISTA DE LOCALIDADES");
		printf("\n\t------------------------");
		printf("\n\tID      DESCRIPCION     ");
		printf("\n\t------------------------");
		for(int i = 0; i < lLen; i++){
			printLocalidad(lList[i]);
		}
		printf("\n\t------------------------\n\n");
	}
	return toReturn;
}

void printLocalidad(Localidad localidad){
	printf("\n\t%4d  %10s", localidad.id, localidad.descripcion);
}


int loadLocalidadDescripcion(int id, Localidad lList[], int lLen, char description[]){
		int toReturn = 0;
		if(id >= 200 && id <= 204 && lList != NULL && lLen > 0 && description != NULL){
			for(int i = 0; i < lLen; i++){
				if(lList[i].id == id){
					strcpy(description, lList[i].descripcion);
					toReturn = 1;
					break;
				}
			}
		}
		return toReturn;
	}

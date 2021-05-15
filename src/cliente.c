#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "biblioteca.h"
#include "cliente.h"
#include "menu.h"


int initClientes(Cliente cList[], int cLen){
	int toReturn = 0;
	int count = 0;
	if(cList != NULL && cLen > 0){
		for(int i = 0; i < cLen; i++){
			cList[i].isEmpty = 1;
			count++;
		}
		if(count > 0) toReturn = 1;
	}
	return toReturn;
}

int searchIsEmpty(Cliente cList[], int cLen){
	int index = -1;
	if(cList != NULL && cLen > 0){
		for(int i = 0; i < cLen; i++){
			if(cList[i].isEmpty == 1){
				index = i;
				break;
			}
		}
	}
	return index;
}

int addCliente(Cliente cList[], int cLen, int *idCliente){
	int toReturn = 0;
	Cliente auxCliente;

	int flagName = 0;
	int flagLastName = 0;
	int flagTelephone = 0;
	int flagSex = 0;

	int index;

	if(cList != NULL && cLen > 0){
		index = searchIsEmpty(cList, cLen);

		if(index < 0){
			printf("\n\tNo hay lugar para guardar un nuevo cliente\n\n");
		} else {
			flagName = utn_getString(auxCliente.nombre, "Nombre ", "El nombre debe tener entre 2-50 caracteres", 2, 50, 3);
			flagLastName = utn_getString(auxCliente.apellido, "Apellido ", "El apellido debe tener entre 2-50 caracteres", 2, 50, 3);
			flagTelephone = utn_getString(auxCliente.telefono, "Telefono ", "El telefono debe tener entre 2-20 caracteres", 2, 20, 3);
			flagSex = utn_getSex(&auxCliente.sexo, "Sexo f/m/n ", "Sexo debe ser f, m, n", 'f', 'm', 'n', 3);
			if( flagLastName && flagName && flagTelephone && flagSex){
				auxCliente.isEmpty = 0;
				auxCliente.id =  *idCliente;
				cList[index] = auxCliente;
				(*idCliente)++;
				toReturn = 1;
			} else {
				printf("\n\tEl cliente no pudo ser agregado\n\n");
			}
		}
	}
	return toReturn;
}

int findClienteById(Cliente cList[], int cLen, int id){
	int index = -1;
	if(cList != NULL && cLen > 0 && id > 0){
		for(int i = 0; i < cLen; i++){
			if(cList[i].id == id && cList[i].isEmpty == 0){
				index = i;
				break;
			}
		}
	}
	return index;
}

int modifyClienteById(Cliente cList[], int cLen){
	int toReturn = 0;
	int idCliente;
	int index = -1;
	if(cList != NULL && cLen > 0){
		// TODO: print employee list
		printClientes(cList, cLen);
		// TODO: make the user select an id from the list
		utn_getInt(&idCliente, "Cliente ID", "El ID del cliente debe ser entre 5000 & 5005", 5000, 5004, 3);
		// TODO: if the user id is not empty and id is valid return the index
		index = findClienteById(cList, cLen, idCliente);
		if(index < 0){
			printf("\n\tNo hay cliente con el ID %d\n\n", idCliente);
		} else {
			toReturn = showClienteCondicionesMenu(cList, cLen, index,  idCliente);
		}
	}
	return toReturn;
}

int deleteCliente(Cliente cList[], int cLen){
	int toReturn = 0;
	int employeeId;
	int index = -1;
	int flag = 0;
	char confirm;
	if(cList != NULL && cLen > 0){
		// TODO: print employee list
		printClientes(cList, cLen);
		// TODO: make the user select an id from the list
		utn_getInt(&employeeId, "Cliente ID", "El ID del cliente debe ser entre 5000 & 5005", 5000, 5004, 3);
		// TODO: if the user id is not empty and id is valid return the index
		index = findClienteById(cList, cLen, employeeId);
		if(flag == 1 && index < 0){
			printf("\n\tNo hay cliente con el ID %d\n\n", employeeId);
		} else {
			printf("\n\tcliente a borrar: ");
			printCliente(cList[index]);
			printf("\n\n\tEsta seguro que desea borra al cliente id %d ? n/y ", employeeId);
			fflush(stdin);
			scanf("%c", &confirm);
			if(confirm == 'y'){
				cList[index].isEmpty = 1;
				toReturn = 1;
			} else {
				printf("\n\tEl cliente no fue borrado\n\n");
			}
		}
	}
	return toReturn;
}

int printClientes(Cliente cList[], int cLen){
	int toReturn = 0;
	int count = 0;
	if(cList != NULL && cLen > 0){
		sortClientes(cList, cLen, 1);
		printf("\n\t-----------------------------------------------------");
		printf("\n\t               LISTA DE CLIENTES");
		printf("\n\t-----------------------------------------------------");
		printf("\n\tID       NOMBRE             SEXO         TELEFONO");
		printf("\n\t-----------------------------------------------------");
		for(int i = 0; i < cLen; i++) {
			if(cList[i].isEmpty == 0){
				printCliente(cList[i]);
				count++;
			}
		}
		if(count < 1) {
			printf("\n\tNo hay clientes para imprimir");
		} else {
			toReturn = 1;
		}
		printf("\n\t-----------------------------------------------------\n\n");
	}
	return toReturn;
}

void printCliente(Cliente cliente){
	char fullName[100] = "";

	strcat(fullName, cliente.apellido);
	for(int i = 0; fullName[i] != '\0'; i++){
		if(fullName[i] == '\n'){
			fullName[i] = ',';
			fullName[i+1] = ' ';
			break;
		}
	}
	strcat(fullName, cliente.nombre);
	strlwr(fullName);
	fullName[0] = toupper(fullName[0]);
	for(int i = 0; fullName[i] != '\0'; i++){
		if(fullName[i] == ' ') {
			fullName[i+1] = toupper(fullName[i+1]);
		}
	}
	for(int i = 0; fullName[i] != '\0'; i++){
		if(fullName[i] == '\n') {
			fullName[i] = '\0';
			break;
		}
	}

	printf("\n\t%3d  %15s      %2c   %20s", cliente.id, fullName, cliente.sexo, cliente.telefono);

}


int sortClientes(Cliente cList[], int cLen, int order){
	int toReturn = 0;
	Cliente auxCliente;
	if(order == 1){ // asc
		for(int i = 0; i < cLen - 1; i++){
			for(int j = i + 1; j < cLen; j++){
				if(strcmp(cList[i].apellido, cList[j].apellido) > 0 || (strcmp(cList[i].apellido, cList[j].apellido) == 0 && strcmp(cList[i].nombre, cList[j].nombre) > 0)){
					auxCliente = cList[i];
					cList[i] = cList[j];
					cList[j] = auxCliente;
					toReturn = 1;
				} else {
					toReturn = 1;
				}

			}
		}
	} else { // desc
		for(int i = 0; i < cLen - 1; i++){
			for(int j = i + 1; j < cLen; j++){
				if(strcmp(cList[i].apellido, cList[j].apellido) < 0 || (strcmp(cList[i].apellido, cList[j].apellido) == 0 && strcmp(cList[i].nombre, cList[j].nombre) < 0)){
					auxCliente = cList[i];
					cList[i] = cList[j];
					cList[j] = auxCliente;
					toReturn = 1;
				} else {
					toReturn = 1;
				}
			}
		}
	}
	return toReturn;
}

int loadClienteNombre(int id, Cliente cList[], int cLen, char description[]){
	int toReturn = 0;
	if(id >= 1000 && id <= 1004 && cList != NULL && cLen > 0 && description != NULL){
		for(int i = 0; i < cLen; i++){
			if(cList[i].id == id){
				strcpy(description, cList[i].nombre);
				toReturn = 1;
				break;
			}
		}
	}
	return toReturn;
}

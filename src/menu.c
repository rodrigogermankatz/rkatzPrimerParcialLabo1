#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"


int menu() {
	int option = 0;
	printf("\n\t-----------------------------");
	printf("\n\t  ADMINISTRADOR DE CLIENTES");
	printf("\n\t-----------------------------");
	printf("\n\t1. ALTA CLIENTE");
	printf("\n\t2. MODIFICAR CLIENTE");
	printf("\n\t3. BAJA CLIENTE");
	printf("\n\t4. LISTAR CLIENTES");
	printf("\n\t0. SALIR");
	printf("\n\t-----------------------------");
	printf("\n\tOpción: ");
	fflush(stdin);
	scanf("%i", &option);
	return option;
}


int showClienteCondicionesMenu(Cliente cList[], int eLen, int index,  int idCliente){
	int toReturn = 0;
	char response = 'n';
	Cliente auxCliente;

	int flagName = 0;
	int flagLastName = 0;
	int flagTelephone = 0;
	int flagSex = 0;

	if(cList != NULL && eLen > 0){
		do {
			switch(clienteConditionsMenu()){
			case 1:
				flagName = utn_getString(auxCliente.nombre, "Nombre ", "El nombre debe tener entre 2-50 caracteres", 2, 50, 3);
				break;
			case 2:
				flagLastName = utn_getString(auxCliente.apellido, "Apellido ", "El apellido debe tener entre 2-50 caracteres", 2, 50, 3);
				break;
			case 3:
				flagTelephone = utn_getString(auxCliente.telefono, "Telefono ", "El telefono debe tener entre 2-20 caracteres", 2, 20, 3);
				break;
			case 4:
				flagSex = utn_getSex(&auxCliente.sexo, "Sexo f/m/n ", "Sexo debe ser f, m, n", 'f', 'm', 'n', 3);
				break;
			case 9:
				if(cList[index].isEmpty == 0 && cList[index].id == idCliente){
					if(flagName) strcpy(cList[index].nombre, auxCliente.nombre);
					if(flagLastName) strcpy(cList[index].apellido, auxCliente.apellido);
					if(flagTelephone) strcpy(cList[index].telefono, auxCliente.telefono);
					if(flagSex) cList[index].sexo = auxCliente.sexo;
					printf("\n\t-----------------------------------------------------");
					printf("\n\t      NUEVAS CONDICIONES DEL CLIENTE ID %3d", idCliente);
					printf("\n\t-----------------------------------------------------");
					printf("\n\tID       NOMBRE             SEXO         TELEFONO");
					printf("\n\t-----------------------------------------------------");
					printCliente(cList[index]);
					printf("\n\t-----------------------------------------------------\n\n");
					toReturn = 1;
					response = 'y';
				} else {
					printf("\n\tEl cliente ID %d no pudo ser modificado\n\n", idCliente);
				}
				break;
			case 0:
				response = 'y';
				break;
			default:
				printf("\n\tOpcion invalida. Intente de vuelta\n\n");
				fflush(stdin);
				break;
			}
		}  while (response != 'y');
	}

	return toReturn;

}


int clienteConditionsMenu(){
	int option;

	printf("\n\tNuevas condiciones del cliente");
	printf("\n\t1. Nombre");
	printf("\n\t2. Apellido");
	printf("\n\t3. Telefono");
	printf("\n\t4. Sexo");
	printf("\n\t9. Guardar Condiciones");
	printf("\n\t0. Volver al menu");
	printf("\n\t---------");
	printf("\n\tOption: ");
	scanf("%d", &option);

	return option;
}

int exitMenu(){
	char option;
	int toReturn = 0;
	printf("\n\t\tEsta seguro de que desea salir? s/n ");
	fflush(stdin);
	scanf("%c", &option);
	if(tolower(option) == 's') toReturn = 1;
	return toReturn;
}

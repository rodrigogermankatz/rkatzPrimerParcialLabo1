#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"

#include "informes.h"


int menu() {
	int option = 0;
	printf("\n\t-------------------------------");
	printf("\n\t   ADMINISTRADOR DE CLIENTES");
	printf("\n\t-------------------------------");
	printf("\n\t1. ALTA CLIENTE");
	printf("\n\t2. MODIFICAR CLIENTE");
	printf("\n\t3. BAJA CLIENTE");
	printf("\n\t4. LISTAR CLIENTES");
	printf("\n\t5. AGREGAR ALQUILER");
	printf("\n\t6. LISTAR ALQUILERES");
	printf("\n\t7. INFORMES");
	printf("\n\t0. SALIR");
	printf("\n\t-------------------------------");
	printf("\n\tOpción: ");
	fflush(stdin);
	scanf("%i", &option);
	return option;
}


int showClienteCondicionesMenu(Cliente cList[], int eLen, int index,  int idCliente, Localidad lList[], int lLen){
	int toReturn = 0;
	char response = 'n';
	Cliente auxCliente;

	int flagName = 0;
	int flagLastName = 0;
	int flagTelephone = 0;
	int flagSex = 0;
	int flagLocalidad = 0;

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
			case 5:
				printLocalidades(lList, lLen);
				flagLocalidad = utn_getInt(&auxCliente.idLocalidad, "ID Localidad ", "El ID de la Localidad debe ser entre 200 & 204", 200, 204, 3);
				break;
			case 9:
				if(cList[index].isEmpty == 0 && cList[index].id == idCliente){
					if(flagName) strcpy(cList[index].nombre, auxCliente.nombre);
					if(flagLastName) strcpy(cList[index].apellido, auxCliente.apellido);
					if(flagTelephone) strcpy(cList[index].telefono, auxCliente.telefono);
					if(flagSex) cList[index].sexo = auxCliente.sexo;
					if(flagLocalidad) cList[index].idLocalidad = auxCliente.idLocalidad;
					printf("\n\t-----------------------------------------------------");
					printf("\n\t      NUEVAS CONDICIONES DEL CLIENTE ID %3d", idCliente);
					printf("\n\t-----------------------------------------------------");
					printf("\n\tID       NOMBRE             SEXO         TELEFONO");
					printf("\n\t-----------------------------------------------------");
					printCliente(cList[index], lList, lLen);
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

int showInformesMenu(Alquiler aList[], int aLen, Cliente cList[], int cLen, Categoria catList[], int catLen, Juego jList[], int jLen, Localidad lList[], int lLen){
	int toReturn = 0;
	char response = 'n';

	if(aList != NULL && aLen > 0 && cList != NULL && cLen > 0 && catList != NULL && catLen > 0 && jList != NULL && jLen > 0){
		do {
			switch(informesMenu()){
			case 1:
				if(informarCategoriaDelJuegoMasAlquilado(aList, aLen, catList, catLen, jList, jLen)){
					printf("\n\tInforme hecho\n\n");
				} else {
					printf("\n\tEl informe no pudo ser hecho\n\n");
				}
				break;
			case 2:
				if(informarTodosLosAlquileresHechosPorUnCLiente(aList, aLen, cList, cLen, catList, catLen, jList, jLen, lList, lLen)){
					printf("\n\tInforme hecho\n\n");
				} else {
					printf("\n\tEl informe no pudo ser hecho\n\n");
				}
				break;
			case 3:
				if(informarSumatoriaDeAlquileresPorCliente(aList, aLen, cList, cLen, jList, jLen, lList, lLen)){
					printf("\n\tInforme hecho\n\n");
				} else {
					printf("\n\tEl informe no pudo ser hecho\n\n");
				}
				break;
			case 4:
				if(informarAlquileresPorLocalidad(aList, aLen, cList, cLen, lList, lLen)){
					printf("\n\tInforme hecho\n\n");
				} else {
					printf("\n\tEl informe no pudo ser hecho\n\n");
				}
				break;
			case 5:
				if(informarClientesPorLocalidad(cList, cLen, lList, lLen)){
					printf("\n\tInforme hecho\n\n");
				} else {
					printf("\n\tEl informe no pudo ser hecho\n\n");
				}
				break;
			/*case 7:
				if(informarSumatoriaTotalDeAlquileres(aList, aLen, jList, jLen)){
					printf("\n\tInforme hecho\n\n");
				} else {
					printf("\n\tEl informe no pudo ser hecho\n\n");
				}
				break;
			case 8:
				if(informarSumatoriaDeAlquileresPorCategoria(aList, aLen, catList, catLen, jList, jLen)){
					printf("\n\tInforme hecho\n\n");
				} else {
					printf("\n\tEl informe no pudo ser hecho\n\n");
				}
				break;*/
			case 0:
				response = 'y';
				break;
			default:
				printf("\n\tOpcion invalida. Intente de vuelta\n\n");
				fflush(stdin);
				break;
			}
		} while (response != 'y');
	}
	return toReturn;
}


int clienteConditionsMenu(){
	int option;
	printf("\n\t-------------------------------");
	printf("\n\t      MODIFICAR CLIENTE");
	printf("\n\t-------------------------------");
	printf("\n\t1. NOMBRE");
	printf("\n\t2. APELLIDO");
	printf("\n\t3. TELEFONO");
	printf("\n\t4. SEXO");
	printf("\n\t5. LOCALIDAD");
	printf("\n\t9. GUARDAR");
	printf("\n\t0. CANCELAR");
	printf("\n\t-------------------------------");
	printf("\n\tOption: ");
	scanf("%d", &option);

	return option;
}

int informesMenu(){
	int option;

	printf("\n\t-----------------------------------------");
	printf("\n\t             INFORMES VARIOS");
	printf("\n\t-----------------------------------------");
	printf("\n\t1. CATEGORIA DEL JUEGO MAS ALQUILADO");
	printf("\n\t2. INFORMAR ALQUILERES HECHOS POR CLIENTE");
	printf("\n\t3. SUMATORIA DE ALQUILERES POR CLIENTE");
	printf("\n\t4. CANTIDAD DE ALQUILERES POR LOCALIDAD");
	printf("\n\t5. CANTIDAD DE CLIENTES POR LOCALIDAD");
	/*printf("\n\t5. SUMATORIA DE ALQUILERES POR CATEGORIA");
	printf("\n\t6. ORDENAR ALQUILERES POR ALGUN CRITERIO");*/
	printf("\n\t0. SALIR");
	printf("\n\t-----------------------------------------");
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

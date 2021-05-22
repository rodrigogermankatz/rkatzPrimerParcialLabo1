
#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct {
    int id;
    char descripcion[50];
} Localidad;


/** \brief funcion que se usa para buscar una Localidad
 * \param lista de Localidad
 * \param tamaño de la lista de Localidad
 * \param int id de la Localidad a buscar
 *
 * \return -1 error/ > -1 el indice de categoria en la lista
 */
int searchLocalidad(Localidad lList[], int lLen, int id);

/** \brief funcion que se usa para imprimir todos las Localidads
 * \param lista de Localidad
 * \param tamaño de la lista de Localidad
 * \return 1 ok / 0 error
 */
int printLocalidades(Localidad lList[], int lLen);

/** \brief funcion que imprime una Localidad
 * \param categoria de tipo Localidad
 * \return void
 */
void printLocalidad(Localidad localidad);

/** \brief funcion para buscar el nombre el Localidad
 * \param int id de Localidad
 * \param lista de Localidad
 * \param tamanio de la lista
 * \param donde se va a guardar la descripcion
 *
 * \return 1 ok/ 0 error
 * */
int loadLocalidadDescripcion(int id, Localidad lList[], int lLen, char description[]);

#endif /* LOCALIDAD_H_ */

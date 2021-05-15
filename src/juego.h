
#ifndef JUEGO_H_
#define JUEGO_H_


typedef struct {
	int id;
	char descripcion[100];
	float importe;
	int idCategoria;
} Juego;

/**funcion que se usa para buscar un juego
 * param lista de juegos
 * param tamaño de la lista de jeugos
 * param int id del juego a buscar
 *  return -1 error/ > -1 el indice del juego en la lista
 */
int searchJuego(Juego jList[], int jLen, int id);

/**funcion que se usa para imprimir todos los juegos
 * param lista de juegos
 * param tamaño de la lista de jeugos
 * return 1 ok / 0 error
 */
int printJuegos(Juego jList[], int jLen);

/** funcion que imprime un juego
 * param juego de tipo Juego
 * return void
 */
void printJuego(Juego juego);

/**brief funcion para buscar el nombre el juego
 * param int id del juego
 * param lista de juegos
 * param tamanio de la lista
 * param donde se va a guardar el nombre
 * return 1 ok/ 0 error
 * */
int loadJuegoNombre(int id, Juego jList[], int jLen, char name[]);

#endif /* JUEGO_H_ */



#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/** \brief funcion que obtiene un entero
 *
 * \param pResultado int*
 * \param mensaje char* mensaje para pedir numero entero
 * \param mensajeError char* mensaje de error
 * \param minimo int limite minimo del numero entero
 * \param maximo int limite maximo del numero entero
 * \param reintentos int reintentos para ingresar el numero entero
 * \return int 1 ok / 0 error
 *
 */
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief funcion que obtiene un flotante
 *
 * \param pResultado float*
 * \param mensaje char* mensaje para pedir numero flotante
 * \param mensajeError char* mensaje de error
 * \param minimo int limite minimo del numero flotante
 * \param maximo int limite maximo del numero flotante
 * \param reintentos int reintentos para ingresar el numero flotante
 * \return int 1 ok / 0 error
 *
 */
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/** \brief funcion que obtiene un caracter
 *
 * \param pResultado char*
 * \param mensaje char* mensaje para pedir el caracter
 * \param mensajeError char* mensaje de error
 * \param minimo int limite minimo del caracter
 * \param maximo int limite maximo del caracter
 * \param reintentos int reintentos para ingresar el caracter
 * \return int 1 ok / 0 error
 *
 */
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/** \brief funcion que obtiene un string
 *
 * \param pStringResult char*
 * \param mensaje char* mensaje para pedir el string
 * \param mensajeError char* mensaje de error
 * \param minimo int limite minimo del string
 * \param maximo int limite maximo del string
 * \param reintentos int reintentos para ingresar el string
 * \return int 1 ok / 0 error
 *
 */
int utn_getString(char *pStringResult, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief funcion que solicita un numero entero y devuelve el resultado
 *
 * \param mensaje[] char mensaje a ser mostrado
 * \return int el numero ingresado por el usuario
 *
 */

#endif /* BIBLIOTECA_H_ */

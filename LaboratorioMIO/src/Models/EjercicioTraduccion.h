/*
 * EjercicioTraduccion.h
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#ifndef MODELS_EJERCICIOTRADUCCION_H_
#define MODELS_EJERCICIOTRADUCCION_H_
#include "../ICollections/interfaces/IDictionary.h"
#include "Ejercicio.h"


class EjercicioTraduccion: public Ejercicio{
private:
	string traduccion;
public:
	EjercicioTraduccion();
	EjercicioTraduccion(string nombre, string descripcion, string frase, string traduccion);
	virtual ~EjercicioTraduccion();
};

#endif /* MODELS_EJERCICIOTRADUCCION_H_ */

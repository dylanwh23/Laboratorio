/*
 * EjercicioCompletar.h
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#ifndef MODELS_EJERCICIOCOMPLETAR_H_
#define MODELS_EJERCICIOCOMPLETAR_H_
#include "../ICollections/interfaces/IDictionary.h"
#include "Ejercicio.h"
#include <set>

class EjercicioCompletar: public Ejercicio {
private:
	set<string> palabrasFaltantes;
public:
	EjercicioCompletar();
	virtual ~EjercicioCompletar();
};

#endif /* MODELS_EJERCICIOCOMPLETAR_H_ */

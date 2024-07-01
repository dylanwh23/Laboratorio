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


class EjercicioCompletar: public Ejercicio {
private:
	string palabrasFaltantes;
public:
	EjercicioCompletar();
	EjercicioCompletar(string nombre, string descripcion, string frase, string palabrasFaltantes);
	virtual ~EjercicioCompletar();
	list<string> getInfo();
	string getSolucion();
	string getNom();
};

#endif /* MODELS_EJERCICIOCOMPLETAR_H_ */

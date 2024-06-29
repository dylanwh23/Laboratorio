/*
 * Incripcion.h
 *
 *  Created on: Jun 28, 2024
 *      Author: dylan
 */

#ifndef MODELS_INCRIPCION_H_
#define MODELS_INCRIPCION_H_
#include "Curso.h";
#include "../ICollections/interfaces/IDictionary.h"

class Incripcion : public ICollectible{
private:
	Curso* curso;
	IDictionary* ejerciciosAprobados;
public:
	Incripcion();
	Incripcion(Curso* curso, IDictionary* ejerciciosAprobados);
	virtual ~Incripcion();
};

#endif /* MODELS_INCRIPCION_H_ */

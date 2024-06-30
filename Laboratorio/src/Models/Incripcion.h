/*
 * Incripcion.h
 *
 *  Created on: Jun 28, 2024
 *      Author: dylan
 */

#ifndef MODELS_INCRIPCION_H_
#define MODELS_INCRIPCION_H_
#include "Curso.h"
#include <string>
#include "../ICollections/interfaces/IDictionary.h"
#include "../ICollections/String.h"

class Incripcion : public ICollectible{
private:
	string fecha;
	Curso* curso;
	IDictionary* ejerciciosAprobados;
	bool aprobado;
public:
	Incripcion();
	Incripcion(Curso* curso, IDictionary* ejerciciosAprobados);
	virtual ~Incripcion();
	bool compararCursos(Curso *curso);
	IDictionary* getEjerciciosAprobados();
	bool getAprobado();
	string getNomCurso();
	void ingresarEjercicio(Ejercicio* eje);
	set<string> getEjercicios();
};

#endif /* MODELS_INCRIPCION_H_ */

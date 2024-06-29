/*
 * Curso.h
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */

#ifndef MODELS_CURSO_H_
#define MODELS_CURSO_H_
#include "../ICollections/interfaces/ICollectible.h"
#include <iostream>
#include <set>
#include "../ICollections/interfaces/IDictionary.h"
#include "Leccion.h"
using namespace std;

class Curso : public ICollectible{
private:
	bool habilitado;
	string nombre;
	string dificultad;
	IDictionary* previaturas;
	IDictionary* lecciones;
public:
	Curso(string nombre, string dificultad, bool habilitado, IDictionary* previaturas, IDictionary* lecciones);
	Curso(string nombre, string dificultad, bool habilitado);

	virtual ~Curso();
	string getNomCurso();
	bool esHabilitado();
	void agregarLeccion(Leccion *lec);
	set<string> listarLecciones();
	IDictionary* getLecciones();
};

#endif /* MODELS_CURSO_H_ */

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
#include <list>
#include "../ICollections/interfaces/IDictionary.h"
#include "Leccion.h"
#include "Profesor.h"
#include "Leccion.h"
using namespace std;

class Curso : public ICollectible{
private:
	bool habilitado;
	string nombre;
	string dificultad;
	Usuario* profesor;
	Idioma* idioma;
	IDictionary* previaturas;
	IDictionary* lecciones;
public:
	Curso(string nombre, string dificultad, bool habilitado);
	Curso(string nombre, string dificultad, bool habilitado,Usuario* profesor,Idioma* idioma, IDictionary* previaturas, IDictionary* lecciones);
	list<string> mostrarInfo();
	virtual ~Curso();
	string getNomCurso();
	bool esHabilitado();
	void agregarLeccion(Leccion *lec);
	set<string> listarLecciones();
};

#endif /* MODELS_CURSO_H_ */

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
using namespace std;

class Curso : public ICollectible{
private:
	bool habilitado;
	string nombre;
	string dificultad;
	set <string> previaturas;
public:
	Curso(string nombre, string dificultad, bool habilitado, set<string> previaturas);
	virtual ~Curso();
	string getNomCurso();
	bool esHabilitado();
};

#endif /* MODELS_CURSO_H_ */

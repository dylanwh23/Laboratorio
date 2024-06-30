/*
 * Lecciones.h
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#ifndef MODELS_LECCION_H_
#define MODELS_LECCION_H_
#include "../ICollections/interfaces/IDictionary.h"
#include <iostream>
#include "EjercicioTraduccion.h"
#include "EjercicioCompletar.h"
using namespace std;

class Leccion : public ICollectible{
private:
	string tema;
	string objetivo;
	IDictionary* ejercicios;
public:
	Leccion(string tema, string objetivo, IDictionary *ejercicios);
	virtual ~Leccion();
	string getTemaLec();
	void agregarEjercicio(Ejercicio* eje);
	int contarEjercicios();
	void borrarLecciones();
	set<string> listarEjercicios();
	IDictionary* getEjercicios();
};

#endif /* MODELS_LECCION_H_ */

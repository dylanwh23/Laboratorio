/*
 * Ejercicio.h
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#ifndef MODELS_EJERCICIO_H_
#define MODELS_EJERCICIO_H_
#include "../ICollections/interfaces/ICollectible.h"
#include "../ICollections/interfaces/IDictionary.h"
#include <iostream>
#include <set>
using namespace std;

class Ejercicio : public ICollectible{
protected:
	string nombre;
	string descripcion;
	string frase;
public:
	Ejercicio();
	Ejercicio(string nombre);
	virtual ~Ejercicio();
	string getNom();
	string getDesc();
};

#endif /* MODELS_EJERCICIO_H_ */

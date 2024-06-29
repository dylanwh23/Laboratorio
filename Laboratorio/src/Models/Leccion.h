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
using namespace std;

class Leccion : public ICollectible{
private:
string tema;
string objetivo;
IDictionary* ejercicios;
public:
Leccion(string tema, string objetivo, IDictionary* ejercicios);
virtual ~Leccion();
string getTemaLec();
};

#endif /* MODELS_LECCION_H_ */

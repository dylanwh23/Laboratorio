/*
 * Lecciones.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "Leccion.h"

Leccion::Leccion(string tema, string objetivo, IDictionary* ejercicios) {
// TODO Auto-generated constructor stub
this->tema = tema;
this->objetivo = objetivo;
this->ejercicios = ejercicios;
}

Leccion::~Leccion() {
// TODO Auto-generated destructor stub
}

string Leccion::getTemaLec(){
return this->tema;
}


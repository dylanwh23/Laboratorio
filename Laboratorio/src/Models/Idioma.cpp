/*
 * Idioma.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */


#include "Idioma.h"


Idioma::Idioma(string nomIdioma) {
	this->nomIdioma = nomIdioma;
}

Idioma::~Idioma() {
	// TODO Auto-generated destructor stub
}

string Idioma::getNomIdioma() {
	return this->nomIdioma;
}


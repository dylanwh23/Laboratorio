/*
 * ConsultaIdioma.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "ConsultaIdioma.h"
#include "../Controllers/IdiomaController.h"
#include <iostream>

ConsultaIdioma::ConsultaIdioma() {
	// TODO Auto-generated constructor stub
	this->iidioma = new IdiomaController();
}

ConsultaIdioma::~ConsultaIdioma() {
	// TODO Auto-generated destructor stub

}

void ConsultaIdioma::consultaIdioma(){


	set<string> idiomasExistentes = this->iidioma->listarIdiomas();

	set<string>::iterator it;
	for (it = idiomasExistentes.begin(); it != idiomasExistentes.end();
			it++) {
		cout << "Idioma: " << *it << endl;
	}
}

void ConsultaIdioma::inicializarDatos(){
	this->iidioma->inicializarDatos();
}

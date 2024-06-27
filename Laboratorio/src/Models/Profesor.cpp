/*
 * Profesor.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "Profesor.h"

Profesor::Profesor() {
	// TODO Auto-generated constructor stub

}

Profesor::~Profesor() {
	// TODO Auto-generated destructor stub
}

Profesor::Profesor(string nickname, string contraseña, string nombre, string descripcion, string instituto) {
	// TODO Auto-generated constructor stub
	this->nickname = nickname;
	this->contraseña = contraseña;
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->instituto = instituto;
}

set<string> Profesor::mostrarInfo(){
	set<string> aux;
	aux.insert(this->nickname);
	aux.insert(this->contraseña);
	aux.insert(this->nombre);
	aux.insert(this->descripcion);
	aux.insert(this->instituto);
	return aux;
}

string Profesor::getNick(){

	return this->nickname;
}



void Profesor::listaridiomas(){

	set<string> aux;

		IDictionary *auxit = this->idiomas;
		for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

				Idioma *auxnom = dynamic_cast<Idioma*>(it->getCurrent());
				cout << "Idioma: " << auxnom->getNomIdioma() << endl;
			}
}


















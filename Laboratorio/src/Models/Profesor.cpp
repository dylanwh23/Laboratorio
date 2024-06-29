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

list<string> Profesor::mostrarInfo(){
	list<string> aux;
	aux.push_back(this->nickname);

	aux.push_back(this->contraseña);

	aux.push_back(this->nombre);

	aux.push_back(this->descripcion);

	aux.push_back(this->instituto);

	return aux;
}

string Profesor::getNick(){

	return this->nickname;
}



list<string> Profesor::listaridiomas() {

	list<string> aux;

	IDictionary *auxit = this->idiomas;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

		Idioma *auxnom = dynamic_cast<Idioma*>(it->getCurrent());
		aux.push_back(auxnom->getNomIdioma());
	}
	return aux;
}


















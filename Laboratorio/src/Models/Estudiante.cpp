/*
 * Estudiante.cpp
 *
 *  Created on: Jun 26, 2024
 *      Author: dylan
 */

#include "Estudiante.h"

Estudiante::Estudiante(string nick, string pass, string nom, string descrip, string pais) {
	//los DTO son un pasamano para no acoplar la capa de presentación con la capa de negocio
	this->nickname = nick;
	this->contraseña = pass;
	this->nombre = nom;
	this->descripcion = descrip;
	this->paisResidencia = pais;

}

Estudiante::~Estudiante() {
	// TODO Auto-generated destructor stub
}

set<string> Estudiante::mostrarInfo(){
	set<string> aux;
	aux.insert(this->nickname);
	aux.insert(this->contraseña);
	aux.insert(this->nombre);
	aux.insert(this->descripcion);
	aux.insert(this->paisResidencia);
	return aux;
}

string Estudiante::getNick(){

	return this->nickname;
}

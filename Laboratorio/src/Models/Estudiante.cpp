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

list<string> Estudiante::mostrarInfo(){
	list<string> aux;
	aux.push_back(this->nickname);
	aux.push_back(this->contraseña);
	aux.push_back(this->nombre);
	aux.push_back(this->descripcion);
	aux.push_back(this->paisResidencia);
	return aux;
}

string Estudiante::getNick(){

	return this->nickname;
}

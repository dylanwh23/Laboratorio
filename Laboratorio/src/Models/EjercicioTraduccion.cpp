/*
 * EjercicioTraduccion.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "EjercicioTraduccion.h"


EjercicioTraduccion::EjercicioTraduccion() {
	// TODO Auto-generated constructor stub

}

EjercicioTraduccion::EjercicioTraduccion(string nombre, string descripcion, string frase, string traduccion){
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->frase = frase;
	this->traduccion = traduccion;
}

EjercicioTraduccion::~EjercicioTraduccion() {
	// TODO Auto-generated destructor stub
}

list<string> EjercicioTraduccion::getInfo(){

	list<string> aux;

	aux.push_back(this->nombre);

	aux.push_back(this->descripcion);

	aux.push_back(this->frase);

	return aux;

}


string EjercicioTraduccion::getSolucion(){

	return this->traduccion;

}


string EjercicioTraduccion::getNom(){

	return this->nombre;
}


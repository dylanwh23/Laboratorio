/*
 * Ejercicio.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "Ejercicio.h"

Ejercicio::Ejercicio() {
	// TODO Auto-generated constructor stub

}
Ejercicio::Ejercicio(string nombre){
	this->nombre = nombre;
}

Ejercicio::~Ejercicio() {
	// TODO Auto-generated destructor stub
}

string Ejercicio::getNom(){

	return this->nombre;
}
string Ejercicio::getDesc(){

	return this->descripcion;
}

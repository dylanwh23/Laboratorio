/*
 * EjercicioCompletar.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "EjercicioCompletar.h"

EjercicioCompletar::EjercicioCompletar() {
	// TODO Auto-generated constructor stub

}
EjercicioCompletar::EjercicioCompletar(string nombre, string descripcion, string frase, string palabrasFaltantes){
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->frase = frase;
	this->palabrasFaltantes = palabrasFaltantes;
}

EjercicioCompletar::~EjercicioCompletar() {
	// TODO Auto-generated destructor stub
}
list<string> EjercicioCompletar::getInfo(){

	 list<string> aux;

		aux.push_back(this->nombre);

		aux.push_back(this->descripcion);

		aux.push_back(this->frase);

		return aux;

}

string EjercicioCompletar::getSolucion(){

	return this->palabrasFaltantes;

}

string EjercicioCompletar::getNom(){
	return this->nombre;
}

/*
 * Curso.cpp
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */

#include "Curso.h"
#include "Leccion.h"
#include "../ICollections/String.h"
Curso::Curso(string nombre, string dificultad, bool habilitado, IDictionary* previaturas, IDictionary* lecciones) {
	this->nombre = nombre;
	this->dificultad = dificultad;
	this->habilitado = habilitado; //como no hay habilitarCurso aun
	this->previaturas= previaturas;
	this->lecciones = lecciones;
}
Curso::Curso(string nombre, string dificultad, bool habilitado) {
	this->nombre = nombre;
	this->dificultad = dificultad;
	this->habilitado = habilitado; //como no hay habilitarCurso aun
}
Curso::~Curso() {
	// TODO Auto-generated destructor stub
}

string Curso::getNomCurso(){
	return this->nombre;
}
bool Curso::esHabilitado(){
	if(this->habilitado == true){
		return true;
	}
	return false;
}

void Curso::agregarLeccion(Leccion *lec){

	this->lecciones->add(new String(lec->getTemaLec()), lec);

}

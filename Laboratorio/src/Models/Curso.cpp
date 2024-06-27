/*
 * Curso.cpp
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */

#include "Curso.h"

Curso::Curso(string nombre, string dificultad, bool habilitado, set<string> previaturas) {
	this->nombre = nombre;
	this->dificultad = dificultad;
	this->habilitado = habilitado;
	this->previaturas= previaturas;

}

Curso::~Curso() {
	// TODO Auto-generated destructor stub
}

string Curso::getNomCurso(){
	return this->nombre;
}

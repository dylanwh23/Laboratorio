/*
 * Incripcion.cpp
 *
 *  Created on: Jun 28, 2024
 *      Author: dylan
 */

#include "Incripcion.h"

Incripcion::Incripcion() {
	// TODO Auto-generated constructor stub

}

Incripcion::Incripcion(Curso* curso, IDictionary* ejerciciosAprobados) {
	// TODO Auto-generated constructor stub
	this->curso = curso;
	this->ejerciciosAprobados = ejerciciosAprobados;
}

Incripcion::~Incripcion() {
	// TODO Auto-generated destructor stub
}
bool Incripcion::compararCursos(Curso *curso){
	if(curso == this->curso){
		return true;
	}else
		return false;
}
IDictionary* Incripcion::getEjerciciosAprobados(){
	return this->ejerciciosAprobados;
}

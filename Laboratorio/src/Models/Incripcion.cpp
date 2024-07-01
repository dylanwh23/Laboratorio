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
bool Incripcion::getAprobado(){

	return this->aprobado;

}

string Incripcion::getNomCurso(){

	return this->curso->getNomCurso();

}

void Incripcion::ingresarEjercicio(Ejercicio* eje){

	this->ejerciciosAprobados->add(new String(eje->getNom()), eje);

}


set<string> Incripcion::getEjercicios(){

	set<string> auxlecciones;
				IDictionary *auxit = this->ejerciciosAprobados;

				for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

					Ejercicio* auxnom = dynamic_cast<Ejercicio*>(it->getCurrent());

						auxlecciones.insert(auxnom->getNom());

				}
			return auxlecciones;
}


bool Incripcion::esAprobado(){
	if(this->aprobado == true){
		return true;
	}
	return false;
}
Curso* Incripcion::getCurso(){
	return this->curso;
}

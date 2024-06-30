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
bool Estudiante::revisarInscripcionesCurso(Curso *curso){
	if (!this->inscripciones.empty()){
		for (list<Incripcion>::iterator it = this->inscripciones.begin(); it!=this->inscripciones.end(); it++){
				if(it->compararCursos(curso)==true){
						return true;
				}
		}
		return false;
	}else{
		return false;
	}
}
int Estudiante::ejerciciosHechosInscripciones(Curso *curso){
	if (!this->inscripciones.empty()){
		for (list<Incripcion>::iterator it = this->inscripciones.begin(); it!=this->inscripciones.end(); it++){
				if(it->compararCursos(curso)==true){
					IDictionary* ejerciciosAprobados = it->getEjerciciosAprobados();
					return	ejerciciosAprobados->getSize();

				}
		}
		return 0;
	}else{
		return 0;
	}
}

void Estudiante::insertarInscripciones(list<Incripcion> inscripciones){
	this->inscripciones =inscripciones;
};
void Estudiante::borrarInscripcionesCurso(Curso *curso){
	if (!this->inscripciones.empty()) {
	        for (auto it = this->inscripciones.begin(); it != this->inscripciones.end(); ) {
	            if (it->compararCursos(curso) == true) {
	                it = this->inscripciones.erase(it);  // Actualizar el iterador después de borrar
	            } else {
	                ++it;  // Avanzar el iterador sólo si no se borra
	            }
	        }
	   }
}
set<string> Estudiante::getCursosNoAprobados(){
	set<string> aux;

	        list<Incripcion> auxit = this->inscripciones;

	        list<Incripcion>::iterator it;
	        	for (it = auxit.begin(); it != auxit.end(); it++) {

	        		if(it->getAprobado()== false){
	        			aux.insert(it->getNomCurso());
	        		}

	        	}

	        return aux;

}

void Estudiante::insertarEjercicio(string curso, Ejercicio* eje){

	list<Incripcion> inscripciones = this->inscripciones;

	 list<Incripcion>::iterator it;
	for (it = inscripciones.begin(); it != inscripciones.end(); it++) {

		if (it->getNomCurso() == curso) {
			it->ingresarEjercicio(eje);
		}
	}
}

set<string> Estudiante::listarEjerciciosAprobados(){

	list<Incripcion> inscripciones = this->inscripciones;
	list<Incripcion>::iterator it;
	set<string>::iterator it2;
	set<string> ejercicios;
	set<string> aux;

	for (it = inscripciones.begin(); it != inscripciones.end(); it++) {

			aux = (it->getEjercicios());


		for (it2 = aux.begin(); it2 != aux.end(); it2++) {

					ejercicios.insert(*it2);
				}

		}
	return ejercicios;
}

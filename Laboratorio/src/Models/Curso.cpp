/*
 * Curso.cpp
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */
#include <set>
#include "Curso.h"
#include "Leccion.h"
#include "Profesor.h"
#include "../ICollections/String.h"
#include "../ICollections/collections/OrderedDictionary.h"
Curso::Curso(string nombre, string dificultad, bool habilitado,Profesor* profesor,Idioma* idioma, IDictionary* previaturas, IDictionary* lecciones) {
	this->nombre = nombre;
	this->dificultad = dificultad;
	this->habilitado = habilitado; //como no hay habilitarCurso aun
	this->profesor =profesor;
	this->idioma =idioma;
	this->previaturas= previaturas;
	this->lecciones = lecciones;

}
Curso::Curso(string nombre, string dificultad, bool habilitado) {
	this->nombre = nombre;
	this->dificultad = dificultad;
	this->habilitado = habilitado;
}
Curso::~Curso() {
	// TODO Auto-generated destructor stub
}

Curso::Curso(string nombre, string dificultad, string descripcion, Profesor* profesor, Idioma* idioma, bool habilitado){
    this->nombre = nombre;
    this->dificultad = dificultad;
    this->habilitado = habilitado;
    this->profesor =profesor;
    this->idioma =idioma;
    this->descripcion = descripcion;
    this->previaturas = new OrderedDictionary();
    this->lecciones = new OrderedDictionary();
}

list<string> Curso::mostrarInfo(){
	list<string> aux;
	aux.push_back(this->nombre);
	aux.push_back(this->dificultad);
	aux.push_back(this->profesor->getNomUsuario());
	aux.push_back(this->idioma->getNomIdioma());
	string habil;
	if(this->habilitado==true){
		habil ="habilitado";
	}else{
		habil ="no habilitado";
	}
	aux.push_back(habil);
	return aux;
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


set<string> Curso::listarLecciones(){

    set<string> auxlecciones;
    IDictionary* auxit = this->lecciones;

    for (IIterator* it = auxit->getIterator(); it->hasCurrent(); it->next()) {

        Leccion* auxnom = dynamic_cast<Leccion*>(it->getCurrent());

            auxlecciones.insert(auxnom->getTemaLec());

    }

    return auxlecciones;

}
list<string> Curso::listarLeccionesEjercicio(){
	list<string> auxlecciones;
	IDictionary *auxit = this->lecciones;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
		Leccion *auxnom = dynamic_cast<Leccion*>(it->getCurrent());
		auxlecciones.push_back("-----"+auxnom->getTemaLec());
		set<string> auxejercicios = auxnom->listarEjerciciosDescr();
		set<string>::iterator it1;
		for (it1 = auxejercicios.begin(); it1 != auxejercicios.end(); it1++) {
			auxlecciones.push_back("--"+*it1);
		}
	}

	return auxlecciones;

}


IDictionary* Curso::getLecciones(){

	IDictionary* auxit = this->lecciones;
	return auxit;

}
int Curso::cantidadEjercicios() {
	int Aux=0;
	IDictionary *auxit = this->lecciones;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
		Leccion *auxnom = dynamic_cast<Leccion*>(it->getCurrent());
		Aux= Aux + auxnom->contarEjercicios();
	}

	return Aux;

}
Profesor* Curso::getProfesor(){
	return this->profesor;

}

set<string> Curso::listarEjercicios(){

	set<string> auxlecciones;

	IDictionary *auxit = this->lecciones;

		for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

			Leccion* auxnom = dynamic_cast<Leccion*>(it->getCurrent());

			set<string> auxit2 = auxnom->listarEjercicios();

	        set<string>::iterator it2;

	        for (it2 = auxit2.begin(); it2 != auxit2.end(); it2++) {

	        			auxlecciones.insert(*it2);

	        	}

		}

		return auxlecciones;

}

void Curso::HabilitarCurso(){
	this->habilitado=true;

}

void Curso::AgregarPreviaturas(IDictionary *previaturas){

	for (IIterator *it = previaturas->getIterator(); it->hasCurrent(); it->next()) {

				Curso *cur = dynamic_cast<Curso*>(it->getCurrent());
				this->previaturas->add(new String(cur->getNomCurso()), cur);
			}



}

list<Curso*> Curso::getPrevias(){
	list<Curso*> previas;
	for(IIterator *it = this->previaturas->getIterator() ; it->hasCurrent() ; it->next()){
		previas.push_back(dynamic_cast<Curso*>(it));
	}
	return previas;
}

int Curso::getTotalLecciones(){
	set<string> ::iterator it;
	set<string> lecciones = this->listarLecciones();
	int total = 0;
	for(it = lecciones.begin(); it != lecciones.end(); it++){
		total++;
	}
	cout<<total;
	return total;
}

int Curso::getTotalEjercicios(){
	int total=0 ;
	IDictionary *aux = this->getLecciones();
	for(IIterator *it = aux->getIterator(); it->hasCurrent(); it->next()){
		IDictionary *auxEjercicios;
		auxEjercicios = dynamic_cast<Leccion*>(it->getCurrent())->getEjercicios();
		for(IIterator *it = auxEjercicios->getIterator() ; it->hasCurrent() ; it->next()){
			total++;
		}

	}
	return total;
}

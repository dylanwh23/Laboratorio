/*
 * Sistema.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "Sistema.h"

#include <iostream>
#include <string>

#include "../ICollections/collections/OrderedDictionary.h"
#include "../ICollections/interfaces/IIterator.h"
#include "../ICollections/String.h"
#include "../Models/Profesor.h"
#include "../Models/Leccion.h"


Sistema *Sistema::miSistema = nullptr;
using namespace std;

Sistema::Sistema() {
	// TODO Auto-generated constructor stub

}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

Sistema* Sistema::getInstance() {
	if (Sistema::miSistema == nullptr) {
		Sistema::miSistema = new Sistema();
		Sistema::miSistema->inicializarDatos();
	}
	return Sistema::miSistema;

}

void Sistema::inicializarDatos() {
	//inicializo los idiomas del sistema

	this->idiomas = new OrderedDictionary();
	this->usuarios = new OrderedDictionary();
	this->cursos = new OrderedDictionary();

	cout << "Comienza inicializacion Sistema " << endl;

	Idioma *idioma1 = new Idioma("Ingles");
	Idioma *idioma2 = new Idioma("Espaniol");
	Idioma *idioma3 = new Idioma("Aleman");

	this->idiomas->add(new String("Ingles"), idioma1);
	this->idiomas->add(new String("Espaniol"), idioma2);
	this->idiomas->add(new String("Aleman"), idioma3);

	Usuario *usr1 = new Profesor("gualberto666", "asd", "berto", "profesor","cure");
	Usuario *usr2 = new Profesor("gualberto777", "asd", "berto", "profesor","cure");
	Usuario *usr3 = new Profesor("gualberto888", "asd", "berto", "profesor","cure");

	this->usuarios->add(new String("gualberto666"), usr1);
	this->usuarios->add(new String("gualberto777"), usr2);
	this->usuarios->add(new String("gualberto888"), usr3);

	IDictionary* lecciones = new OrderedDictionary();
	Leccion *leccion1 = new Leccion("historia", "Facil",this->idiomas);
	lecciones->add(new String("historia"), leccion1);

	IDictionary* lecciones2 = new OrderedDictionary();
	Leccion *leccion2 = new Leccion("historia", "Facil",this->idiomas);
	lecciones2->add(new String("historia"), leccion2);

	IDictionary* previaturas = new OrderedDictionary();
	Curso *curso4 = new Curso("indu", "Facil",true);
	previaturas->add(new String("indu"), curso4);

	Curso *curso1 = new Curso("Ingles", "Facil",true,usr1,idioma1,previaturas,lecciones);
	Curso *curso2 = new Curso("Aleman", "Facil",false,usr2,idioma1,previaturas,lecciones2);
	Curso *curso3 = new Curso("Espaniol", "Facil",false,usr3,idioma1,previaturas,lecciones);


	this->cursos->add(new String("Ingles"), curso1);
	this->cursos->add(new String("Aleman"), curso2);
	this->cursos->add(new String("Espaniol"), curso3);



	cout << "Fin inicializacion Sistema " << endl;
}
set<string> Sistema::listarUsuarios() {
	set<string> aux;
	IDictionary *auxit = this->usuarios;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

		Usuario *auxnom = static_cast<Usuario*>(it->getCurrent());		aux.insert(auxnom->getNomUsuario());
	}
	return aux;
}

set<string> Sistema::listarCursosHabilitados() {
	set<string> aux;
	IDictionary *auxit = this->cursos;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
		if (static_cast<Curso*>(it->getCurrent())->esHabilitado() == true) {
			Curso *auxcur = dynamic_cast<Curso*>(it->getCurrent());
			aux.insert(auxcur->getNomCurso());
		}
	}
	return aux;
}
set<string> Sistema::listarCursos() {
	set<string> aux;
	IDictionary *auxit = this->cursos;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
			Curso *auxcur = dynamic_cast<Curso*>(it->getCurrent());
			aux.insert(auxcur->getNomCurso());
	}
	return aux;
}

set<string> Sistema::listarIdiomas() {
	set<string> aux;
	IDictionary *auxit = this->idiomas;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

		Idioma *auxnom = dynamic_cast<Idioma*>(it->getCurrent());
		aux.insert(auxnom->getNomIdioma());
	}
	return aux;
}
bool Sistema::verificarNickname(string nickname){
	if(this->usuarios->member(new String(nickname))==true){
		return false;
	}
	return true;

}

bool Sistema::verificarIdioma(string nombreIdioma){
	if(this->idiomas->member(new String(nombreIdioma))==true){
			return false;
		}
		return true;

}

set<string> Sistema::listarIdiomasProfesor(string profesor) {
	string nick;
	set<string> aux;
	//casteo la instancia de profesor para luego obtener sus idiomas, recorrerlos y devolverlos

	Usuario* usuarioSeleccionado = dynamic_cast<Usuario*>(this->usuarios->find(new String(profesor)));

	Profesor *profesorSeleccionado = static_cast<Profesor*>(usuarioSeleccionado);
	IDictionary *auxit = profesorSeleccionado->idiomas;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

	aux.insert(static_cast<Idioma*>(it->getCurrent())->getNomIdioma());

	}
	return aux;

}

set<string> Sistema::listarProfesores() {

	set<string> aux;
	IDictionary *auxit = this->usuarios;

	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

		Profesor* auxnom = dynamic_cast<Profesor*>(it->getCurrent());
		if(auxnom){
			aux.insert(auxnom->getNick());
		}
	}

	return aux;

}

set<string> Sistema::listarCursosInhabilitados() {

    	set<string> aux;
        IDictionary* auxit = this->cursos;

        for (IIterator* it = auxit->getIterator(); it->hasCurrent(); it->next()) {
            if (dynamic_cast<Curso*>(it->getCurrent())->esHabilitado() == false) {
                Curso* auxcur = dynamic_cast<Curso*>(it->getCurrent());
                aux.insert(auxcur->getNomCurso());
            }
        }
        return aux;
}



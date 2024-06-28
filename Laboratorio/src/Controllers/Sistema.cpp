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
Sistema *Sistema::miSistema = nullptr;

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


	cout << "Fin inicializacion Sistema " << endl;
}
set<string> Sistema::listarUsuarios() {
	set<string> aux;
	IDictionary *auxit = this->usuarios;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

		Usuario *auxnom = static_cast<Usuario*>(it->getCurrent());

		aux.insert(auxnom->getNomUsuario());
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


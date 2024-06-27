/*
 * UsuarioController.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "UsuarioController.h"
#include <set>
#include "../ICollections/interfaces/IIterator.h"
#include "../ICollections/collections/OrderedDictionary.h"
#include <iterator>
using namespace std;

UsuarioController::UsuarioController() {
	// TODO Auto-generated constructor stub
	this->sistema = Sistema::getInstance();

}

UsuarioController::~UsuarioController() {
	// TODO Auto-generated destructor stub
}

set<string> UsuarioController::listarIdiomas() {

	return this->sistema->listarIdiomas();
}
bool UsuarioController::verificarNickname(string nickname) {

	return this->sistema->verificarNickname(nickname);
}

bool UsuarioController::verificarIdioma(string nombreIdioma){

	return this->sistema->verificarIdioma(nombreIdioma);
}

void UsuarioController::altaProfesor(DTOProfesor* dto){

	Profesor* usr = new Profesor(dto->nick,dto->pass,dto->nom,dto->descrip, dto->instituto);


	set<string> idiomasRecibido = dto->idiomas;

	set<string>::iterator it;

	IDictionary* aux = new OrderedDictionary();
	//recorro los idiomas del sistema obteniendo las intancias de los idiomas seleccionados, para cargarlos a la lista de idiomas del profesor
	for (it = idiomasRecibido.begin(); it != idiomasRecibido.end(); it++) {
		Idioma* idiomaObtenido = dynamic_cast<Idioma*>(this->sistema->idiomas->find(new String(*it)));
		aux->add(new String(*it),idiomaObtenido);

	}

	this->sistema->usuarios->add(new String(dto->nick), usr);
}
void UsuarioController::altaEstudiante(DTOEstudiante* dto){
	Estudiante* usr = new Estudiante(dto->nick,dto->pass,dto->nom,dto->descrip, dto->paisResidencia);
	this->sistema->usuarios->add(new String(dto->nick), usr);
}

void UsuarioController::altaIdioma(string nombreIdioma){

	Idioma* Idm = new Idioma(nombreIdioma);

	this->sistema->idiomas->add(new String(nombreIdioma), Idm);

}



/*
 * UsuarioController.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "UsuarioController.h"
#include <set>
#include "../ICollections/interfaces/IIterator.h"
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
DTOProfesor UsuarioController::altaProfesor(DTOProfesor* dto){
	Profesor* usr = new Profesor(dto->nick,dto->pass,dto->nom,dto->descrip, dto->instituto);


	set<string> idiomaRecibido = dto->idiomas;

	set<string>::iterator it;
	//recorro los idiomas del sistema obteniendo las intancias de los idiomas seleccionados, para cargarlos a la lista de idiomas del profesor
	for (it = idiomaRecibido.begin(); it != idiomaRecibido.end(); it++) {
		Idioma* idiomaObtenido = dynamic_cast<Idioma*>(this->sistema->idiomas->find(new String(*it)));
		usr->idiomas->add(new String(*it),idiomaObtenido);
	}

	this->sistema->usuarios->add(new String(dto->nick), usr);
}
DTOEstudiante UsuarioController::altaEstudiante(DTOEstudiante* dto){

}

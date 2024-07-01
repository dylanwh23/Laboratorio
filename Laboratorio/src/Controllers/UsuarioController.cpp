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
set<string> UsuarioController::listarUsuarios(){
	return this->sistema->listarUsuarios();

}
bool UsuarioController::verificarNickname(string nickname) {

	return this->sistema->verificarNickname(nickname);
}



void UsuarioController::altaProfesor(DTOProfesor* dto){

	Profesor* usr = new Profesor(dto->nick,dto->pass,dto->nom,dto->descrip, dto->instituto, dto->idiomas);


	//set<string> idiomasRecibido = dto->idiomas;
	IDictionary* idiomasRecibido = dto->idiomas;

	IDictionary* aux = new OrderedDictionary();
	//recorro los idiomas del sistema obteniendo las intancias de los idiomas seleccionados, para cargarlos a la lista de idiomas del profesor
	if(usr->idiomas->isEmpty()==false){
		for (IIterator *it = idiomasRecibido->getIterator(); it->hasCurrent(); it->next()) {
				Idioma* idiomaObtenido = dynamic_cast<Idioma*>(it->getCurrent());
				idiomaObtenido->getNomIdioma();
				aux->add(new String(idiomaObtenido->getNomIdioma()),idiomaObtenido);

			}
	}

	usr->idiomas = aux;
	this->sistema->usuarios->add(new String(dto->nick), usr);
}
void UsuarioController::altaEstudiante(DTOEstudiante* dto){
	Estudiante* usr = new Estudiante(dto->nick,dto->pass,dto->nom,dto->descrip, dto->paisResidencia);
	this->sistema->usuarios->add(new String(dto->nick), usr);
}
Usuario* UsuarioController::getUsuarioSistema(string nickname) {

	return dynamic_cast<Usuario*>(this->sistema->usuarios->find(new String(nickname)));
}

Idioma* UsuarioController::getIdiomaSistema(string idioma){

	return dynamic_cast<Idioma*>(this->sistema->idiomas->find(new String(idioma)));
}


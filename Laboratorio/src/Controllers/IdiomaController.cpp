/*
 * IdiomaController.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#include "IdiomaController.h"

IdiomaController::IdiomaController() {
	// TODO Auto-generated constructor stub
	this->sistema = Sistema::getInstance();
}

IdiomaController::~IdiomaController() {
	// TODO Auto-generated destructor stub
}
void IdiomaController::altaIdioma(string nombreIdioma){

	Idioma* Idm = new Idioma(nombreIdioma);

	this->sistema->idiomas->add(new String(nombreIdioma), Idm);

}
set<string> IdiomaController::listarIdiomas(){
	return this->sistema->listarIdiomas();
}
bool IdiomaController::verificarIdioma(string nombreIdioma){
	return this->sistema->verificarIdioma(nombreIdioma);
}

void IdiomaController::inicializarDatos(){
	this->sistema->inicializarDatos();
}

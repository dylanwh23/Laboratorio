/*
 * UsuarioController.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "UsuarioController.h"
#include <set>

using namespace std;

UsuarioController::UsuarioController() {
	// TODO Auto-generated constructor stub
	this->sistema = Sistema::getInstance();
}

UsuarioController::~UsuarioController() {
	// TODO Auto-generated destructor stub
}

bool UsuarioController::verificarNick(string nick) {

}
set<string> UsuarioController::listarIdiomas() {

	return this->sistema->listarIdiomas();
}
void UsuarioController::altaProfesor() {

}
void UsuarioController::altaEstudiante() {
	;//
}

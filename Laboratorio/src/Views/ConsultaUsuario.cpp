/*
 * ConsultaUsuario.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#include "ConsultaUsuario.h"
#include "../Controllers/UsuarioController.h"

ConsultaUsuario::ConsultaUsuario() {
	// TODO Auto-generated constructor stub
	this->iusuario = new UsuarioController();

}

ConsultaUsuario::~ConsultaUsuario() {
	// TODO Auto-generated destructor stub
}

void ConsultaUsuario::consultaUsuario() {
	set<string> usuariosExistentes = this->iusuario->listarUsuarios();
	set<string> usuariosSeleccionados;

	set<string>::iterator it;
	for (it = usuariosExistentes.begin(); it != usuariosExistentes.end();
			it++) {
		cout << "Usuario: " << *it << endl;
	}
}

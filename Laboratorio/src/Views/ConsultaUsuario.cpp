/*
 * ConsultaUsuario.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#include "ConsultaUsuario.h"
#include "../Controllers/UsuarioController.h"
#include <iostream>
ConsultaUsuario::ConsultaUsuario() {
	// TODO Auto-generated constructor stub
	this->iusuario = new UsuarioController();

}

ConsultaUsuario::~ConsultaUsuario() {
	// TODO Auto-generated destructor stub
	delete this->iusuario;
}

void ConsultaUsuario::consultaUsuario() {

	set<string> usuariosExistentes = this->iusuario->listarUsuarios();

	set<string>::iterator it;
	for (it = usuariosExistentes.begin(); it != usuariosExistentes.end();
			it++) {
		cout << "Usuario: " << *it << endl;
	}

	cout << "Escriba el usuario seleccionado " << endl;
	string usuarioSeleccionado;
	cout << "Ingrese nick:"<< endl;
	cin >> usuarioSeleccionado;
	Usuario* usuarioSeleccionadoIntancia = this->iusuario->getUsuarioSistema(usuarioSeleccionado);


	list<string> usuarioInfo = usuarioSeleccionadoIntancia->mostrarInfo();

	list<string>::iterator itUsuarioInfo;
		for (itUsuarioInfo = usuarioInfo.begin(); itUsuarioInfo != usuarioInfo.end();
				itUsuarioInfo++) {
			cout << *itUsuarioInfo << endl;
		}


}

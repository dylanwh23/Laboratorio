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
	int quiere = 0;
	int coincideUsr = 0;
	set<string> usuariosExistentes = this->iusuario->listarUsuarios();
	set<string>::iterator it;
	cout << "Lista: " << endl;
	cout << "(Si la lista esta vacia, es porque no existen usuarios)" << endl;
	for (it = usuariosExistentes.begin(); it != usuariosExistentes.end();
			it++) {
		cout << "Usuario: " << *it << endl;
	}

	cout << "Escriba el usuario seleccionado " << endl;
	string usuarioSeleccionado;
	do {
		cout << "Ingrese nick:           (S/s para salir)" << endl;
		cin >> usuarioSeleccionado;

		if ((usuarioSeleccionado != "S" && usuarioSeleccionado != "s") && coincideUsr != 1) {
			for (it = usuariosExistentes.begin();
					it != usuariosExistentes.end(); it++) {
				if (usuarioSeleccionado == *it) {
					Usuario *usuarioSeleccionadoIntancia =
							this->iusuario->getUsuarioSistema(
									usuarioSeleccionado);

					list<string> usuarioInfo =
							usuarioSeleccionadoIntancia->mostrarInfo();
					list<string>::iterator itUsuarioInfo;

					itUsuarioInfo = usuarioInfo.begin(); //principio de la lsita de string, nickname, no me interesa
					advance(itUsuarioInfo, 2); //nombre
					cout << "Nombre:" << *itUsuarioInfo << endl;
					advance(itUsuarioInfo, 1); //desripcion
					cout << "Descripcion:" << *itUsuarioInfo << endl;
					advance(itUsuarioInfo, 1); //pais residencia si es estudiante, instituto si es profesor
					if (dynamic_cast<Profesor*>(usuarioSeleccionadoIntancia)) {
						cout << "Instituto:" << *itUsuarioInfo << endl;
						list<string> idiomasProfesor =
								dynamic_cast<Profesor*>(usuarioSeleccionadoIntancia)->listaridiomas();
						list<string>::iterator it2;
						for (it2 = idiomasProfesor.begin();
								it2 != idiomasProfesor.end(); it2++) {
							cout << *it2 << endl;
						}
					} else {
						cout << "Pais:" << *itUsuarioInfo << endl;
					}
				}
				coincideUsr =1;
			}
		} else {
			if (usuarioSeleccionado == "s" || usuarioSeleccionado == "S") {
				quiere = 1;
			}

		}
	} while (quiere == 0);
}

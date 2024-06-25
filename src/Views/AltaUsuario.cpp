/*
 * AltaUsuario.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "AltaUsuario.h"
#include "../Controllers/UsuarioController.h"
#include <iostream>
using namespace std;
AltaUsuario::AltaUsuario() {
	// TODO Auto-generated constructor stub
	this->iusuario = new UsuarioController();
}

AltaUsuario::~AltaUsuario() {
	// TODO Auto-generated destructor stub
	delete this->iusuario;
}
void AltaUsuario::altaUsuario() {

	string nick;
	cout << "Ingrese nick:"<< endl;
	cin >> nick;

	set<string> idiomas = this->iusuario->listarIdiomas();
	set<string>::iterator it;

	for (it= idiomas.begin(); it != idiomas.end(); it++) {
		cout << "Idioma " << (*it) << endl;
	}

	bool existe = this->iusuario->verificarNick(nick);
	if (!existe) {
		cout << "Es estudiante o profesor? (1 estudiante 2 profesor" << endl;
		int tipoUsuario;
		DTOUsuario *nuevoUsuario;

		cin >> tipoUsuario;
		if (tipoUsuario == 1) {
			nuevoUsuario = ingresarEstudiante(nick);

		} else {
			nuevoUsuario = ingresarProfesor(nick);
		}

		this->iusuario->agregarUsuario(nuevoUsuario);

		cout << "Fin ingreso de usuario " << endl;

	} else  {
		cout << "Ya existe el usuario. Imposible continuar..." << endl;
	}
	*/
}

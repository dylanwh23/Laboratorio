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
	//delete this->iusuario;
}
DTOEstudiante* AltaUsuario::ingresarEstudiante(string nick){
	string pass;
	string nom;
	string descrip;
	string pais;

	cout << "Ingresar pass:" << endl;
	cin >> pass;
	cout << "Ingresar nombre:" << endl;
	cin >> nom;
	cout << "Ingresar descripcion:" << endl;
	cin >> descrip;

	cout << "Ingresar pais:" << endl;
	cin >> pais;

	DTOEstudiante *nuevoEstudiante = new DTOEstudiante(nick, pass, nom, descrip, pais);

	return nuevoEstudiante;
}

DTOProfesor* AltaUsuario::ingresarProfesor(string nick){
	string pass;
	string nom;
	string descrip;
	string instituto;
	set<string> idiomas;

	cout << "Ingresar pass:" << endl;
	cin >> pass;
	cout << "Ingresar nombre:" << endl;
	cin >> nom;
	cout << "Ingresar descripcion:" << endl;
	cin >> descrip;
	cout << "Ingresar instituto:" << endl;
	cin >> instituto;

	int agregarIdioma;
	cout << " ¿Desea agregar idiomas? (1=si 2 =no)? " << endl;
	cin >> agregarIdioma;
	if (agregarIdioma == 1) {
		idiomas = seleccionarIdiomas();
	} else {
		cout << "No se seleccionan idiomas " << endl;
	}

	DTOProfesor *nuevoProfesor = new DTOProfesor(nick, pass, nom, descrip,
			instituto, idiomas);
	return nuevoProfesor;
}
set<string> AltaUsuario::seleccionarIdiomas() {
	set<string> idiomasExistentes = this->iusuario->listarIdiomas();
	set<string> idiomasSeleccionados;

	set<string>::iterator it;
	for (it = idiomasExistentes.begin(); it != idiomasExistentes.end(); it++) {
		cout << "Idioma: " << *it << endl;
	}
	string idioma;
	bool quiereIngresarIdiomas = true;
	do {
		cout << "Ingrese un idioma de la lista: (S/s para salir)" << endl;
		cin >> idioma;
		if (idioma != "S" && idioma != "s") {
			it = idiomasExistentes.find(idioma);
			if (it != idiomasExistentes.end()) {
				//solo selecciono los idiomas que existen
				idiomasSeleccionados.insert(idioma);
				cout << "Idioma ingresado: " << idioma  << endl;
			} else {
				cout << "El idioma ingresado no existe" << endl;
			}
		} else {
			quiereIngresarIdiomas = false;
		}

	} while (quiereIngresarIdiomas);
	return idiomasSeleccionados;
}
void AltaUsuario::altaUsuario() {

	string nick;
	cout << "Ingrese nick:"<< endl;
	cin >> nick;

	set<string> idiomas = this->iusuario->listarIdiomas();
	set<string>::iterator it;


	if (this->iusuario->verificarNickname(nick)) {
		cout << "Es estudiante o profesor? (1 estudiante 2 profesor" << endl;
		int tipoUsuario;

		cin >> tipoUsuario;
		if (tipoUsuario == 1) {
			DTOEstudiante* nuevoUsuario;
			nuevoUsuario = ingresarEstudiante(nick);
			this->iusuario->altaEstudiante(nuevoUsuario);
		} else {

			DTOProfesor* nuevoUsuario;
			nuevoUsuario = ingresarProfesor(nick);
			this->iusuario->altaProfesor(nuevoUsuario);


		}

		cout << "Fin ingreso de usuario " << endl;

	} else  {
		cout << "Ya existe el usuario. Imposible continuar..." << endl;
	}

}

/*
 * MenuPrincipal.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "MenuPrincipal.h"
#include <iostream>
#include "AltaUsuario.h"
#include "AltaIdioma.h"
#include "AltaCurso.h"
#include "ConsultaUsuario.h"
#include "ConsultaIdioma.h"
using namespace std;
MenuPrincipal::MenuPrincipal() {
	// TODO Auto-generated constructor stub

}

MenuPrincipal::~MenuPrincipal() {
	// TODO Auto-generated destructor stub
}
void MenuPrincipal::mostrarMenu() {
	int op = 0;
	do {
		cout << endl << "*** Menu principal ***" << endl;
		cout << "1) Alta Usuario" << endl;
		cout << "2) Alta Idioma" << endl;
		cout << "3) Alta Curso" << endl;
		cout << "4) Consultar Usuario" << endl;
		cout << "5) Consultar Idiomas" << endl;
		cout << "6) Salir " << endl;
		cout << "Ingrese una opcion: " << endl;

		cin >> op;
		switch (op) {
		case 1: {
			AltaUsuario altaUsuario;
			altaUsuario.altaUsuario();
		}
			break;
		case 2: {
			AltaIdioma altaIdioma;
			altaIdioma.ingresarIdioma();
		}
			break;
		case 3: {
			AltaCurso altaCurso;
			altaCurso.altaCurso();
		}
			break;
		case 4: {
			ConsultaUsuario consultarusuario;
			consultarusuario.consultaUsuario();
		}
			break;
		case 5:{
			ConsultaIdioma consultaidioma;
			consultaidioma.consultaIdioma();
		}
			break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 6);

	cout << "Fin del programa" << endl;
}

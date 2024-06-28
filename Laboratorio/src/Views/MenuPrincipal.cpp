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
#include "ConsultaUsuario.h"
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
		cout << "3) Consultar Usuario" << endl;
		cout << "4) Salir " << endl;
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
				ConsultaUsuario consultarusuario;
				consultarusuario.consultaUsuario();
			}
				break;
		case 4:
			break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 4);

	cout << "Fin del programa" << endl;
}

/*
 * MenuPrincipal.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "MenuPrincipal.h"
#include <iostream>
#include "AltaUsuario.h"
using namespace std;
MenuPrincipal::MenuPrincipal() {
	// TODO Auto-generated constructor stub

}

MenuPrincipal::~MenuPrincipal() {
	// TODO Auto-generated destructor stub
}
void MenuPrincipal::mostrarMenu(){
	int op = 0;
		do {
			cout << "*** Menu principal ***" << endl;
			cout <<"1) Alta Usuario" << endl;
			cout <<"2) Realizar Ejercicio " << endl;
			cout <<"3) Salir " << endl;
			cout <<"Ingrese una opcion: " << endl;

			cin >> op;
			switch (op) {
				case 1: {
					AltaUsuario altaUsuario;
					altaUsuario.altaUsuario();
				}
				break;
			case 2:
				{
				}
				break;
			case 3:
				break;
			default:
				cout << "Opcion desconocida" << endl;
			}

		} while (op != 3);

	cout << "Fin del programa" << endl;
}

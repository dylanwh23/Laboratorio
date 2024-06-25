//============================================================================
// Name        : Laboratorio.cpp
// Author      : Grupo 3
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include "Views/MenuPrincipal.h"
using namespace std;

int main() {
	//desde el main se llama al menu principal, desde este se accede a todas las otras vistas, mirar MenuPrincipal.cpp
	MenuPrincipal mp;
	mp.mostrarMenu();
	return 0;
}

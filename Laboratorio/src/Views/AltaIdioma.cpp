#include "AltaIdioma.h"
#include "../Controllers/IdiomaController.h"
#include <iostream>

AltaIdioma::AltaIdioma() {
    // TODO Auto-generated constructor stub
    this->iidioma = new IdiomaController();
}

AltaIdioma::~AltaIdioma() {
    // TODO Auto-generated destructor stub
}

void AltaIdioma::ingresarIdioma() {

	set<string> idiomasExistentes = this->iidioma->listarIdiomas();
	set<string>::iterator it;



	string idioma;

	cout << "Ingrese un idioma:      (S/s para salir)" << endl;
	cin >> idioma;
	if (idioma != "S" && idioma != "s") {
		it = idiomasExistentes.find(idioma);
		if (it == idiomasExistentes.end()) {
			//solo selecciono los idiomas que existen
			this->iidioma->altaIdioma(idioma);
			cout << "Idioma ingresado: " << idioma << endl;

		} else {
			cout << "--El idioma ingresado ya existe--" << endl;
		}

	}
}

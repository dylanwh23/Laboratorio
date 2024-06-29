/*
 * AltaCurso.cpp
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */
#include "../Controllers/IUsuario.h"
#include "AltaCurso.h"
#include "../Controllers/CursoController.h"
AltaCurso::AltaCurso() {
	// TODO Auto-generated constructor stub
	this->Icurso = new CursoController();
}

AltaCurso::~AltaCurso() {
	// TODO Auto-generated destructor stub
}

string AltaCurso::seleccionarProfesor(){

	set<string> profesoresExistentes = this->Icurso->listarProfesores();

	set<string>::iterator it;
	for (it = profesoresExistentes.begin(); it != profesoresExistentes.end();
			it++) {
		cout << "Profesor: " << *it << endl;
	}

	string profesor;


	cout << "Ingrese un profesor de la lista: (S/s para salir)" << endl;
	cin >> profesor;
	if (profesor != "S" && profesor != "s") {
		it = profesoresExistentes.find(profesor);
		if (it != profesoresExistentes.end()) {
			//solo selecciono los idiomas que existen
			cout << "Profesor seleccionado: " << profesor << endl;
			return profesor;
		}else{
			return 0;
		}
		return profesor;
	}

	return profesor;
}

string AltaCurso::seleccionarIdioma(string profesor) {

	set<string> idiomasExistentes = this->Icurso->listarIdiomasProfesor(
			profesor);
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
				return idioma;
				cout << "Idioma ingresado: " << idioma << endl;
			} else {
				cout
						<< "El idioma ingresado no existe, ingrese un idioma de la lista"
						<< endl;
			}
		} else {
			quiereIngresarIdiomas = false;
		}

	} while (quiereIngresarIdiomas);

}




set<string> AltaCurso::seleccionarPreviaturas() {

	set<string> previas;
	string previa;
	bool quiereIngresarPrevias = true;

	set<string> cursosHabilitados = this->Icurso->listarCursosHabilitados();
	set<string>::iterator it;
	for (it = cursosHabilitados.begin(); it != cursosHabilitados.end(); it++) {
		cout << "Curso: " << *it << endl;
	}

	do {
		cout << "Ingrese un curso como previatura: (S/s para salir)" << endl;
		cin >> previa;
		if (previa != "S" && previa != "s") {

			previas.insert(previa);
			cout << "Curso agregado como previa: " << previa << endl;
		} else {
			quiereIngresarPrevias = false;
		}

	} while (quiereIngresarPrevias);

	return previas;
}






void AltaCurso::altaCurso(){

	string profesor;
	string idioma;
	string nombre;
	string dificultad;
	bool habilitado = false;
	set <string> previaturas;

	profesor = this->seleccionarProfesor();
	idioma = this->seleccionarIdioma(profesor);

	cout << "Ingrese nombre del curso: " << endl;
	cin >> nombre;
	cout << "Ingrese dificultad del curso: " << endl;
	cin >> dificultad;

	int agregarIdioma;
	cout << " ¿Desea agregar previaturas? (1=si 2 =no)? " << endl;
	cin >> agregarIdioma;
	if (agregarIdioma == 1) {
		previaturas = this->seleccionarPreviaturas();
	} else {
		cout << "El curso no tendra cursos previos " << endl;
	}


	cout << "Curso Agregado Corectamente";
	this->Icurso->altaCurso(nombre, dificultad, habilitado, previaturas);

}

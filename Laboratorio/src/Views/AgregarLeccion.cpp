/*
 * AgregarLeccion.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "AgregarLeccion.h"
#include "../Controllers/ILeccion.h"
#include "../Controllers/LeccionController.h"
AgregarLeccion::AgregarLeccion() {
// TODO Auto-generated constructor stub
    this->Ileccion = new LeccionController();

}

AgregarLeccion::~AgregarLeccion() {
// TODO Auto-generated destructor stub
}

IDictionary* AgregarLeccion::agregarEjercicio() {
	IDictionary *coso;

	return coso;
}

void AgregarLeccion::listarCursosInhabilitados() {

	set<string> cursosInhabilitados = this->Ileccion->listarCursosInhabilitados();
	set<string>::iterator it;

	for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();
			it++) {
		cout << "Curso Inhabilitado: " << *it << endl;
	}

}

void AgregarLeccion::llamarAgregarLeccion() {
	string curso;

	this->listarCursosInhabilitados();

	cout << "Ingrese un curso de la lista: " << endl;
	cin >> curso;

	this->agregarLeccion(curso);

}

void AgregarLeccion::agregarLeccion(string curso) {
	string objetivo;
	string nombreCurso = curso;
	string tema;
	IDictionary *ejercicios;

	cout << "Ingrese el objetivo de la leccion : " << endl;
	cin >> objetivo;
	cout << "Ingrese el tema de la leccion : " << endl;
	cin >> tema;

	int agregarEjercicio;
	cout << " Â¿Desea agregar ejercicios? (1=si 2 =no)? " << endl;
	cin >> agregarEjercicio;
	if (agregarEjercicio == 1) {
		ejercicios = this->agregarEjercicio();
	} else {
		cout << "No se agregan ejercicios a la leccion " << endl;
	}

	this->Ileccion->agregarLeccion(tema, objetivo, ejercicios, nombreCurso);

}

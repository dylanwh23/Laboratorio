/*
 * AgregarLeccion.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "AgregarLeccion.h"
#include "../Controllers/ILeccion.h"
#include "../Controllers/LeccionController.h"
#include "../ICollections/collections/OrderedDictionary.h"
#include "AgregarEjercicio.h"
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

set<string> AgregarLeccion::listarCursosInhabilitados() {
	set<string> aux;
	set<string> cursosInhabilitados = this->Ileccion->listarCursosInhabilitados();
	set<string>::iterator it;
	cout << "Lista: " << endl;
	cout << "(Si la lista esta vacia, es porque no existen cursos)" << endl;
	for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();
			it++) {
			aux.insert(*it);
	}
	return aux;
}

void AgregarLeccion::llamarAgregarLeccion() {
	string curso;
	set<string> cursosInhabilitados = this->listarCursosInhabilitados();
	set<string>::iterator it;

	for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();
			it++) {
		cout << "Curso Inhabilitado: " << *it << endl;
	}
	cout << "Ingrese un curso de la lista(S/s salir): "<< endl;
	cin.ignore();
	getline(cin,curso);
	for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();	it++) {
		if (curso == *it) {
			this->agregarLeccion(curso);
		}
	}

}

void AgregarLeccion::agregarLeccion(string curso) {
	string objetivo;
	string nombreCurso = curso;
	string tema;
	IDictionary *ejercicios = new OrderedDictionary;

	cout << "Ingrese el objetivo de la leccion : " << endl;
	getline(cin,objetivo);
	cout << "Ingrese el tema de la leccion : " << endl;
	getline(cin,tema);

	int agregarEjercicio;
	cout << " ¿Desea agregar ejercicios? (1=si 2 =no)(cualquier otro para salir)? " << endl;
	cin >> agregarEjercicio;
	if (agregarEjercicio == 1) {

		this->Ileccion->agregarLeccion(tema, objetivo, ejercicios, nombreCurso);
		AgregarEjercicio agregareje;
		agregareje.agregarEjercicio(curso, tema);
	} else if (agregarEjercicio == 2){

		cout << "No se agregan ejercicios a la leccion " << endl;
		this->Ileccion->agregarLeccion(tema, objetivo, new OrderedDictionary, nombreCurso);
	}else{
		cout << "salir " << endl;
	}
	//this->Ileccion->agregarLeccion(tema, objetivo, ejercicios, nombreCurso);
}


void AgregarLeccion::agregarLeccionObligatorio(string curso){
	string objetivo;
	string nombreCurso = curso;
	string tema;
	IDictionary *ejercicios = new OrderedDictionary;

	cout << "Ingrese el objetivo de la leccion : " << endl;
	getline(cin,objetivo);
	cout << "Ingrese el tema de la leccion : " << endl;
	getline(cin,tema);


	this->Ileccion->agregarLeccion(tema, objetivo, ejercicios, nombreCurso);

	AgregarEjercicio agregareje;
	agregareje.agregarEjercicio(curso, tema);
	cout << "salir " << endl;

}

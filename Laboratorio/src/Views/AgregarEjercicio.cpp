/*
 * AgregarEjercicio.cpp
 *
 *  Created on: 29 jun. 2024
 *      Author: machichu
 */
#include "../Controllers/IEjercicio.h"
#include "../Controllers/EjercicioController.h"
#include "AgregarEjercicio.h"

AgregarEjercicio::AgregarEjercicio() {
	// TODO Auto-generated constructor stub
	this->Iejercicio = new EjercicioController();
}

AgregarEjercicio::~AgregarEjercicio() {
	// TODO Auto-generated destructor stub
}


void AgregarEjercicio::agregarEjercicio(string curso, string leccion) {

	int tipoEjercicio;
	string nombreEjercicio;
	string frase;
	string desc;
	string palabrasFaltantes;
	cout << "Ingrese tipo de ejercicio:" << endl << "(1-Completar 2-Traduccion"<< endl;

	cin >> tipoEjercicio;

	if (tipoEjercicio == 1) {
		cout << "Ingrese el nombre del ejercicio: " << endl;
		cin >> nombreEjercicio;
		cout << "Ingrese descripcion del ejercicio: " << endl;
		cin >> desc;
		cout << "Ingrese la frase del ejercicio completa: " << endl;
		cin >> frase;
		cout << "Ingrese la frase incompleta: " << endl;
		cin >> palabrasFaltantes;
		this->Iejercicio->ingresarEjercicioCompletar(curso, leccion, nombreEjercicio, desc, frase, palabrasFaltantes);
	} else {

		cout << "Ingrese el nombre del ejercicio: " << endl;
		cin >> nombreEjercicio;
		cout << "Ingrese descripcion del ejercicio: " << endl;
		cin >> desc;
		cout << "Ingrese la frase del ejercicio: " << endl;
		cin >> frase;
		this->Iejercicio->ingresarEjercicioTraducir(curso, leccion, nombreEjercicio, desc, frase);
	}

	cout << "Ejercicio ingresado " << endl;

}



void AgregarEjercicio::listarCursosInhabilitados() {
	set<string> cursosInhabilitados =this->Iejercicio->listarCursosInhabilitados();
	set<string>::iterator it;

	for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();
			it++) {
		cout << "Curso Inhabilitado: " << *it << endl;
	}
}

void AgregarEjercicio::listarLeccionesCurso(string curso) {
	set<string> lecciones = this->Iejercicio->listarLeccionesCurso(curso);
	set<string>::iterator it;

	for (it = lecciones.begin(); it != lecciones.end(); it++) {
		cout << "Leccion: " << *it << endl;
	}
}



void AgregarEjercicio::llamarAgregarEjercicio(){

	string curso;
	string leccion;
	this->listarCursosInhabilitados();
	cout << "Ingrese un curso de la lista: " << endl;
		cin >> curso;

	this->listarLeccionesCurso(curso);
	cout << "Ingrese una Leccion de la lista: " << endl;
		cin >> leccion;


	this->agregarEjercicio(curso, leccion);


}

void AgregarEjercicio::ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase){
	this->Iejercicio->ingresarEjercicioTraducir(curso, leccion, nombreEjercicio, desc, frase);
}


void AgregarEjercicio::ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes){
	this->Iejercicio->ingresarEjercicioCompletar(curso, leccion, nombreEjercicio, desc, frase, palabrasFaltantes);
}

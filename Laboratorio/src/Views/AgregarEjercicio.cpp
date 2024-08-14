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
	string traduccion;
	cout << "Ingrese tipo de ejercicio:" << endl << "(1-Completar 2-Traduccion)(cualquier numero para salir)"<< endl;
	cin >> tipoEjercicio;

	if (tipoEjercicio == 1) {
		cin.ignore();
		cout << "Ingrese el nombre del ejercicio: " << endl;
		getline(cin,nombreEjercicio);
		cout << "Ingrese descripcion del ejercicio: " << endl;
		getline(cin,desc);
		cout << "Ingrese la frase del ejercicio completa: " << endl;
		getline(cin,frase);
		cout << "Ingrese la frase incompleta: " << endl;
		getline(cin,palabrasFaltantes);
		this->Iejercicio->ingresarEjercicioCompletar(curso, leccion, nombreEjercicio, desc, frase, palabrasFaltantes);
		cout << "Ejercicio ingresado " << endl;
	} else if(tipoEjercicio == 2)  {
		cin.ignore();
		cout << "Ingrese el nombre del ejercicio: " << endl;
		getline(cin,nombreEjercicio);
		cout << "Ingrese descripcion del ejercicio: " << endl;
		getline(cin,desc);
		cout << "Ingrese la frase del ejercicio: " << endl;
		getline(cin,frase);
		cout << "Ingrese la traduccion del ejercicio: " << endl;
		getline(cin,traduccion);
		this->Iejercicio->ingresarEjercicioTraducir(curso, leccion, nombreEjercicio, desc, frase, traduccion);
		cout << "Ejercicio ingresado " << endl;
	}else{

	}
}

set<string> AgregarEjercicio::listarCursosInhabilitados() {
	set<string> aux;
		set<string> cursosInhabilitados = this->Iejercicio->listarCursosInhabilitados();
		set<string>::iterator it;

		for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();
				it++) {
				aux.insert(*it);
		}
		return aux;
}

set<string> AgregarEjercicio::listarLeccionesCurso(string curso) {
	set<string> aux;
	set<string> lecciones = this->Iejercicio->listarLeccionesCurso(curso);
		set<string>::iterator it;

		for (it = lecciones.begin(); it != lecciones.end(); it++) {
			aux.insert(*it);
		}

	return aux;
}



void AgregarEjercicio::llamarAgregarEjercicio() {
	string leccion;
	string curso;
	set<string> cursosInhabilitados = this->listarCursosInhabilitados();
	set<string> lecciones;
	set<string>::iterator it;
	cout << "Lista: " << endl;
	cout << "(Si la lista esta vacia, es porque no existen cursos)" << endl;
	for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();
			it++) {
		cout << "Curso Inhabilitado: " << *it << endl;
	}
	cout << "Ingrese un curso de la lista: (uno que no esta en la lista para salir)" << endl;
	cin.ignore();
	getline(cin,curso);
	for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();
			it++) {
		if (curso == *it) {
			lecciones = this->listarLeccionesCurso(curso);
			set<string>::iterator it2;
			for (it2 = lecciones.begin();
					it2 != lecciones.end(); it2++) {
				cout << "lecciones: " << *it2 << endl;
			}
			cout << "Ingrese una Leccion de la lista: (uno que no esta en la lista para salir)" << endl;

			getline(cin,leccion);
			for (it2 = lecciones.begin();it2 != lecciones.end(); it2++) {

				if (leccion == *it2) {
					this->agregarEjercicio(curso, leccion);
				}
			}

		}
	}
}

void AgregarEjercicio::ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase, string traduccion){
	this->Iejercicio->ingresarEjercicioTraducir(curso, leccion, nombreEjercicio, desc, frase, traduccion);
}


void AgregarEjercicio::ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes){
	this->Iejercicio->ingresarEjercicioCompletar(curso, leccion, nombreEjercicio, desc, frase, palabrasFaltantes);
}

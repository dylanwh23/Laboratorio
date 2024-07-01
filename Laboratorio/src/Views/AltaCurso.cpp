/*
 * AltaCurso.cpp
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */
#include "../Controllers/IUsuario.h"
#include "AltaCurso.h"
#include "../Controllers/CursoController.h"
#include "AgregarLeccion.h"
AltaCurso::AltaCurso() {
	// TODO Auto-generated constructor stub
	this->Icurso = new CursoController();
}

AltaCurso::~AltaCurso() {
	// TODO Auto-generated destructor stub
}

string AltaCurso::seleccionarProfesor(){

	set<string> profesoresExistentes = this->Icurso->listarProfesores();
	int quiere=0;
	set<string>::iterator it;
	for (it = profesoresExistentes.begin(); it != profesoresExistentes.end();
			it++) {
		cout << "Profesor: " << *it << endl;
	}

	string profesor;

	do{
	cout << "Ingrese un profesor de la lista: (S/s para salir)" << endl;
	cin >> profesor;
	if (profesor != "S" && profesor != "s") {
		it = profesoresExistentes.find(profesor);
		if (it != profesoresExistentes.end()) {
			//solo selecciono los idiomas que existen
			cout << "Profesor seleccionado: " << profesor << endl;
			return profesor;
		}

		}else{
			if(profesor == "s" || profesor == "S"){
				return "s";
				quiere=1;
			}

	}
	}while(quiere==0);
	return profesor;
}

string AltaCurso::seleccionarIdioma(string profesor) {

	set<string> idiomasExistentes = this->Icurso->listarIdiomasProfesor(profesor);
	set<string> idiomasSeleccionados;
	string vacio = "vacio";

	set<string>::iterator it;

	if(idiomasExistentes.empty()== true){
		return vacio;
	}else{
		for (it = idiomasExistentes.begin(); it != idiomasExistentes.end(); it++) {
				cout << "Idioma: " << *it << endl;
	}

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
	bool bandera=true;
	bool quiereIngresarPrevias = true;

	set<string> cursosHabilitados = this->Icurso->listarCursosHabilitados();
	set<string>::iterator it;
	for (it = cursosHabilitados.begin(); it != cursosHabilitados.end(); it++) {
		cout << "Curso: " << *it << endl;
	}

	do {
		cout << "Ingrese un curso como previatura: (S/s para salir)" << endl;
		cin >> previa;
		if (previa != "S" && previa != "s" ) {

			for (it = cursosHabilitados.begin(); it != cursosHabilitados.end(); it++) {

				if(*it == previa){
					previas.insert(previa);
					cout << "Curso agregado como previa: " << previa << endl;
					bandera = false;
				}
			}

			if(bandera==true){
				cout << "El curso ingresado no existe, ingrese un curso existente: " << endl;
			}

		} else {
			quiereIngresarPrevias = false;
		}

	} while (quiereIngresarPrevias);

	return previas;
}



void AltaCurso::altaCurso() {

	string profesor;
	string idioma;
	string nombre;
	string dificultad;
	int agregarIdioma;
	int agregarLeccion;
	bool habilitado = false;
	set<string> previaturas;

	profesor = this->seleccionarProfesor();

	if(profesor != "s" && profesor != "S"){

	idioma = this->seleccionarIdioma(profesor);

			if(idioma == "vacio"){
				cout << "El profesor no tiene idiomas ingresados, seleccione otro profesor" << endl;
				this->seleccionarProfesor();
			}else{

				cout << "Ingrese nombre del curso: " << endl;
					cin.ignore();
					getline(cin,nombre);
					cout << "Ingrese dificultad del curso: " << endl;
					getline(cin, dificultad);
					cout << " ¿Desea agregar previaturas? (1=si 2 =no)? " << endl;
					cin >> agregarIdioma;
					if (agregarIdioma == 1) {
						previaturas = this->seleccionarPreviaturas();
					} else {
						cout << "El curso no tendra cursos previos " << endl;
					}

					cout << " ¿Desea agregar lecciones? (1=si 2 =no)? " << endl;
					cin >> agregarLeccion;
					cin.ignore();
					if (agregarLeccion == 1) {
						this->Icurso->altaCurso(nombre, dificultad, habilitado, previaturas);
						AgregarLeccion agregarleccion;
						agregarleccion.agregarLeccion(nombre);

					} else {
						cout << "El curso no tendra lecciones" << endl;
						this->Icurso->altaCurso(nombre, dificultad, habilitado, previaturas);
					}

					cout << "Curso Agregado Correctamente";
					//this->Icurso->altaCurso(nombre, dificultad, habilitado, previaturas);
			}
	}



//	idioma = this->seleccionarIdioma(profesor);
//
//	if(idioma == "vacio"){
//		cout << "El profesor no tiene idiomas ingresados, seleccione otro profesor" << endl;
//		this->seleccionarProfesor();
//	}else{
//
//		cout << "Ingrese nombre del curso(sin espacios): " << endl;
//			cin >> nombre;
//			cout << "Ingrese dificultad del curso: " << endl;
//			cin >> dificultad;
//			cout << " ¿Desea agregar previaturas? (1=si 2 =no)? " << endl;
//			cin >> agregarIdioma;
//			if (agregarIdioma == 1) {
//				previaturas = this->seleccionarPreviaturas();
//			} else {
//				cout << "El curso no tendra cursos previos " << endl;
//			}
//
//			cout << " ¿Desea agregar lecciones? (1=si 2 =no)? " << endl;
//			cin >> agregarLeccion;
//			if (agregarLeccion == 1) {
//				AgregarLeccion agregarleccion;
//				agregarleccion.agregarLeccion(nombre);
//			} else {
//				cout << "El curso no tendra cursos previos " << endl;
//			}
//
//			cout << "Curso Agregado Correctamente";
//			this->Icurso->altaCurso(nombre, dificultad, habilitado, previaturas);
//	}



}

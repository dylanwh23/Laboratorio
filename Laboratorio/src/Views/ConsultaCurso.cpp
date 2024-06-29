/*
 * ConsultaUsuario.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#include "ConsultaCurso.h"
#include "../Controllers/CursoController.h"
#include <iostream>
ConsultaCurso::ConsultaCurso() {
	// TODO Auto-generated constructor stub
	this->icurso = new CursoController();

}

ConsultaCurso::~ConsultaCurso() {
	// TODO Auto-generated destructor stub
	delete this->icurso;
}

void ConsultaCurso::consultaCurso() {
	set<string> cursosExistentes = this->icurso->listarCursos();
	set<string>::iterator it;
	for (it = cursosExistentes.begin(); it != cursosExistentes.end(); it++) {
		cout << "Curso: " << *it << endl;
	}

	cout << "Escriba el curso seleccionado " << endl;
	string cursoSeleccionado;
	cout << "Ingrese curso:" << endl;
	cin >> cursoSeleccionado;
	Curso *cursoSeleccionadoIntancia = this->icurso->getCursoSistema(
			cursoSeleccionado);
	if (cursoSeleccionadoIntancia != NULL) {
		list<string> cursoInfo = cursoSeleccionadoIntancia->mostrarInfo();
		list<string>::iterator itCursoInfo;
		itCursoInfo = cursoInfo.begin();
		cout << "Nombre:" << *itCursoInfo << endl;
		advance(itCursoInfo, 1);
		cout << "Dificultad:" << *itCursoInfo << endl;
		advance(itCursoInfo, 1);
		cout << "Profesor:" << *itCursoInfo << endl;
		advance(itCursoInfo, 1);
		cout << "Idioma:" << *itCursoInfo << endl;
		set<string> lecciones = cursoSeleccionadoIntancia->listarLecciones();
		set<string>::iterator it;
		for (it = lecciones.begin(); it != lecciones.end(); it++) {
		             cout << "Leccion: " << *it << endl;
		         }
	}


}

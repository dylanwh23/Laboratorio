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
	cout << "Lista: " << endl;
	cout << "(Si la lista esta vacia, es porque no existen cursos)" << endl;
	for (it = cursosExistentes.begin(); it != cursosExistentes.end(); it++) {
		cout << "Curso: " << *it << endl;
	}

	string cursoSeleccionado;
	cout << "Ingrese curso (uno que no esta en la lista para salir):" << endl;
	cin.ignore();
	getline(cin,cursoSeleccionado);
	Curso *cursoSeleccionadoIntancia = this->icurso->getCursoSistema(cursoSeleccionado);

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
		list<string> lecciones = cursoSeleccionadoIntancia->listarLeccionesEjercicio();
		list<string>::iterator itL;
		set<string> estudiantesInscriptos = this->icurso->listarEstudiantes(cursoSeleccionadoIntancia);
		cout << "lecciones: " << endl;
		for (itL = lecciones.begin();itL != lecciones.end(); itL++) {
			cout << *itL << endl;
		}
		set<string>::iterator it;
		cout << "estudiantes inscriptos: " << endl;
		for (it = estudiantesInscriptos.begin();
				it != estudiantesInscriptos.end(); it++) {
			cout << "e:" << *it << endl;
			}

	}else{
		cout << "El curso ingresado no existe" << endl;
	}

}

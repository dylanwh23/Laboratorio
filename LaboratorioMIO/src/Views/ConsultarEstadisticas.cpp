/*
 * ConsultaUsuario.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#include "ConsultarEstadisticas.h"
#include "../Controllers/CursoController.h"
#include <iostream>
ConsultarEstadisticas::ConsultarEstadisticas() {
	// TODO Auto-generated constructor stub
	this->icurso = new CursoController();

}

ConsultarEstadisticas::~ConsultarEstadisticas() {
	// TODO Auto-generated destructor stub
	delete this->icurso;
}

void ConsultarEstadisticas::consultarEstadisticas(){
	int op = 0;
	cout << "1-ESTADISTICAS CURSOS" << endl;
	cout << "2-ESTADISTICAS ESTUDIANTES" << endl;
	cout << "3-ESTADISTICAS PROFESORES" << endl;
	cin >> op;
	switch (op) {
	case 1: {
		set<string> cursosExistentes = this->icurso->listarCursos();
		set<string>::iterator it;
		for (it = cursosExistentes.begin(); it != cursosExistentes.end();it++) {
			cout << "Curso: " << *it << endl;
		}
		cout << "Escriba el curso seleccionado " << endl;
		string cursoSeleccionado;
		cout << "Ingrese curso:" << endl;
		cin >> cursoSeleccionado;
		Curso *cursoSeleccionadoIntancia = this->icurso->getCursoSistema(cursoSeleccionado);
		set<string> cursoInfo = this->icurso->listarCursosStats(cursoSeleccionadoIntancia);
		set<string>::iterator it2;
				for (it2 = cursoInfo.begin();it2 != cursoInfo.end(); it2++) {
					cout << "Curso: " << *it2<< endl;
				}
		}

		break;
	case 2: {
		set<string> estudiantesExistentes = this->icurso->listarEstudiantes();
		set<string>::iterator it;
		for (it = estudiantesExistentes.begin();
				it != estudiantesExistentes.end(); it++) {
			cout << "Estudiantes: " << *it << endl;

		}
		string estSeleccionado;
		cout << "Ingrese estudiante:" << endl;
		cin >> estSeleccionado;
		cout << "CURSOS A LOS QUE ESTA INCRIPTO EL ESTUDIANTE:" << endl;
		Estudiante *estSeleccionadoIntancia =this->icurso->getEstudianteSistema(estSeleccionado);
		set<string> cursosExistentes = this->icurso->listarCursos(estSeleccionadoIntancia);
		set<string>::iterator it2;
		for (it2 = cursosExistentes.begin();
				it2 != cursosExistentes.end(); it2++) {
			cout << "Cursos: " << *it2<< endl;
		}
	}
		break;

	case 3: {
		set<string> profesoresExistentes = this->icurso->listarProfesores();
		set<string>::iterator it;
		for (it = profesoresExistentes.begin(); it != profesoresExistentes.end();
				it++) {
			cout << "Profesores: " << *it << endl;

		}
		string profSeleccionado;
		cout << "Ingrese profesor:" << endl;
		cin >> profSeleccionado;
		Profesor *profSeleccionadoIntancia =this->icurso->getProfesorSistema(profSeleccionado);
		set<string> cursosExistentes = this->icurso->listarCursos(profSeleccionadoIntancia);
		set<string>::iterator it2;
				for (it2 = cursosExistentes.begin();
						it2 != cursosExistentes.end(); it2++) {
					cout << "Cursos: " << *it2<< endl;
				}

		break;
	}
//
//	cout << "Escriba el curso seleccionado " << endl;
//	string cursoSeleccionado;
//	cout << "Ingrese curso:" << endl;
//	cin >> cursoSeleccionado;
//	Curso *cursoSeleccionadoIntancia = this->icurso->getCursoSistema(
//			cursoSeleccionado);
//	if (cursoSeleccionadoIntancia != NULL) {
//		list<string> cursoInfo = cursoSeleccionadoIntancia->mostrarInfo();
//		list<string>::iterator itCursoInfo;
//		itCursoInfo = cursoInfo.begin();
//		cout << "Nombre:" << *itCursoInfo << endl;
//		advance(itCursoInfo, 1);
//		cout << "Dificultad:" << *itCursoInfo << endl;
//		advance(itCursoInfo, 1);
//		cout << "Profesor:" << *itCursoInfo << endl;
//		advance(itCursoInfo, 1);
//		cout << "Idioma:" << *itCursoInfo << endl;
//		set<string> lecciones = cursoSeleccionadoIntancia->listarLecciones();
//		set<string> estudiantesInscriptos = this->icurso->listarEstudiantes(cursoSeleccionadoIntancia);
//
//		set<string>::iterator it;
//		cout << "estudiantes inscriptos: "<<endl;
//			for (it = estudiantesInscriptos.begin(); it != estudiantesInscriptos.end(); it++) {
//				cout << "e:" << *it << endl;
//			}
//
//	}
	}
}

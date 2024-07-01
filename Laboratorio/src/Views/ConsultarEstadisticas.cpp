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
	string opcion;
	int op = 0;
	cout << "1-ESTADISTICAS CURSOS" << endl;
	cout << "2-ESTADISTICAS ESTUDIANTES" << endl;
	cout << "3-ESTADISTICAS PROFESORES" << endl;
	if(opcion == "1"){
		op = 1;
	}else if(opcion == "2"){
		op = 2;
	}else if(opcion == "3"){
		op = 3;
	}else{
		op = 4;
	}
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
		cin.ignore();
		getline(cin, cursoSeleccionado);
		Curso *cursoSeleccionadoIntancia = this->icurso->getCursoSistema(cursoSeleccionado);
		if (cursoSeleccionadoIntancia != NULL){

			set<string> cursoInfo = this->icurso->listarCursosStats(cursoSeleccionadoIntancia);
					set<string>::iterator it2;
							for (it2 = cursoInfo.begin();it2 != cursoInfo.end(); it2++) {
								cout << "Curso: " << *it2<< endl;
							}
		}else{
			cout << "El curso ingresado no existe" << endl;
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
		cin.ignore();
		getline(cin, estSeleccionado);
		cout << "CURSOS A LOS QUE ESTA INCRIPTO EL ESTUDIANTE:" << endl;
		Estudiante *estSeleccionadoIntancia =this->icurso->getEstudianteSistema(estSeleccionado);
		if(estSeleccionadoIntancia != NULL){
			set<string> cursosExistentes = this->icurso->listarCursos(estSeleccionadoIntancia);
					set<string>::iterator it2;
					for (it2 = cursosExistentes.begin();
							it2 != cursosExistentes.end(); it2++) {
						cout << "Cursos: " << *it2<< endl;
		}

		}else{
			cout << "El estudiante ingresado no existe" << endl;
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
		cin.ignore();
		getline(cin, profSeleccionado);
		Profesor *profSeleccionadoIntancia =this->icurso->getProfesorSistema(profSeleccionado);
		if(profSeleccionadoIntancia != NULL){
			set<string> cursosExistentes = this->icurso->listarCursos(profSeleccionadoIntancia);
					set<string>::iterator it2;
							for (it2 = cursosExistentes.begin();
									it2 != cursosExistentes.end(); it2++) {
								cout << "Cursos: " << *it2<< endl;
							}
		}else{
			cout << "El profesor ingresado no existe" << endl;
		}


		break;
	}
	default:
				cout << "Opcion desconocida" << endl;
			}

	}


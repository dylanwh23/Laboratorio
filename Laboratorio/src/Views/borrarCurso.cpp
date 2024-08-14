/*
 * ConsultaUsuario.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#include "borrarCurso.h"
#include "../Controllers/CursoController.h"
#include <iostream>
BorrarCurso::BorrarCurso() {
	// TODO Auto-generated constructor stub
	this->icurso = new CursoController();

}

BorrarCurso::~BorrarCurso(){
	// TODO Auto-generated destructor stub
	delete this->icurso;
}

 void BorrarCurso::borrarCurso() {
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
		IDictionary* cursoInfo = cursoSeleccionadoIntancia->getLecciones();
		for (IIterator *itL = cursoInfo->getIterator(); itL->hasCurrent(); itL->next()) {
				Leccion *auxnom = static_cast<Leccion*>(itL->getCurrent());
				auxnom->borrarLecciones();
				cursoInfo->remove(new String(auxnom->getTemaLec()));
				auxnom->~Leccion();
				}

		this->icurso->BorrarIncripciones(cursoSeleccionadoIntancia);
		this->icurso->BorrarCurso(cursoSeleccionadoIntancia);
		//cursoInfo->~IDictionary();
	}



 }



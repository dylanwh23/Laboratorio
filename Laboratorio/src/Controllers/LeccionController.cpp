/*
 * LeccionController.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "LeccionController.h"
using namespace std;

LeccionController::LeccionController() {
	// TODO Auto-generated constructor stub
	this->sistema = Sistema::getInstance();
}

LeccionController::~LeccionController() {
	// TODO Auto-generated destructor stub
}


set<string> LeccionController::listarCursosInhabilitados(){
	return this->sistema->listarCursosInhabilitados();
}


void LeccionController::agregarLeccion(string tema, string objetivo, IDictionary* ejercicios, string nombreCurso){

	Leccion* lec = new Leccion(tema, objetivo, ejercicios);
	Curso *cursofinal;
	IDictionary *auxit = this->sistema->cursos;

	cout << nombreCurso;

	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

			Curso *auxnom = dynamic_cast<Curso*>(it->getCurrent());
			if (auxnom->getNomCurso() == nombreCurso) {
				cursofinal = auxnom;
				cursofinal->agregarLeccion(lec);
				break;
			}

		}

	cursofinal->agregarLeccion(lec);

}

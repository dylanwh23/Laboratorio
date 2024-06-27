/*
 * CursoController.cpp
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */

#include "CursoController.h"
#include <set>
#include "../ICollections/interfaces/IIterator.h"
#include "../ICollections/collections/OrderedDictionary.h"
#include <iterator>
using namespace std;


CursoController::CursoController() {
	// TODO Auto-generated constructor stub

}

CursoController::~CursoController() {
	// TODO Auto-generated destructor stub
}

set<string> CursoController::listarIdiomasProfesor(string profesor) {

	return this->sistema->listarIdiomasProfesor(profesor);

}


void CursoController::altaCurso(string nombreCurso, string dificultad, bool habilitado, set<string> previaturas){


	Curso* curso = new Curso(nombreCurso, dificultad, habilitado, previaturas);

	this->sistema->cursos->add(new String(nombreCurso), curso);


}

set<string> CursoController::listarProfesores(){

	return this->sistema->listarProfesores();

}




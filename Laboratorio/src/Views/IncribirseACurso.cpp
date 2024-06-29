/*
 * IncribirseACurso.cpp
 *
 *  Created on: Jun 28, 2024
 *      Author: dylan
 */

#include "IncribirseACurso.h"
#include "../Controllers/CursoController.h"

IncribirseACurso::IncribirseACurso() {
	// TODO Auto-generated constructor stub
	this->icurso = new CursoController();

}

IncribirseACurso::~IncribirseACurso() {
	// TODO Auto-generated destructor stub
}

list<string> IncribirseACurso::seleccionarCursos(string nickname){
	this->icurso->listarCursosHabilitadosParaElEstudiante(nickname);
}

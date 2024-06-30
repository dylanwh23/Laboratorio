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
#include "../ICollections/String.h"

CursoController::CursoController() {
	// TODO Auto-generated constructor stub
	this->sistema = Sistema::getInstance();
}

CursoController::~CursoController() {
	// TODO Auto-generated destructor stub
}

set<string> CursoController::listarIdiomasProfesor(string profesor) {

	return this->sistema->listarIdiomasProfesor(profesor);

}


void CursoController::altaCurso(string nombreCurso, string dificultad, bool habilitado, set<string> previaturas){

	IDictionary* previas = new OrderedDictionary();

		set<string>::iterator it;
		for (it = previaturas.begin(); it != previaturas.end(); it++) {
			Curso *aux = dynamic_cast<Curso*>(this->sistema->cursos->find(new String(*it)));
			previas->add(new String(*it), aux);
		}


		Curso* curso = new Curso(nombreCurso, dificultad, habilitado);

	this->sistema->cursos->add(new String(nombreCurso), curso);


}

set<string> CursoController::listarProfesores(){

	return this->sistema->listarProfesores();

}

set<string> CursoController::listarCursosHabilitados(){

	return this->sistema->listarCursosHabilitados();

}
set<string> CursoController::listarCursos(){

	return this->sistema->listarCursos();
}
set<string> CursoController::listarCursos(Estudiante *estudiante){

	return this->sistema->listarCursos(estudiante);
}
Curso* CursoController::getCursoSistema(string curso) {
	return dynamic_cast<Curso*>(this->sistema->cursos->find(new String(curso)));
}

list<string> CursoController::listarCursosHabilitadosParaElEstudiante(string nickname){
	this->sistema->listarCursosHabilitados();

	Estudiante* estudiante;
	estudiante = dynamic_cast<Estudiante*>(this->sistema->usuarios->find(new String(nickname)));
	if(estudiante){
		//accedo a las incripciones del estudiante

		//recorro estas creando una lista de cursos a los que ya esta inscripto
		//creo una nueva lista de cursos habilitados a los que no esta inscripto
		//accedo a la lista de inscripciones aprobadas del estudiante y recupero los cursos
		//recorro la lista de cursos en los que no se ha inscripto y estan habilitados, comparando con la lista de arriba
		//y agrego a la lista definitiva solo los cursos en los que el estudiante ya aprobo sus previaturas
	}else{
		cout<<"Ingrese un estudiante"<<endl;
	}
}
set<string> CursoController::listarEstudiantes(Curso *curso){
	return this->sistema->listarEstudiantes(curso);
}
void CursoController::BorrarIncripciones(Curso *curso){
	this->sistema->BorrarIncripciones(curso);
}
void CursoController::BorrarCurso(Curso *curso){
	this->sistema->BorrarCurso(curso);
}
set<string> CursoController::listarEstudiantes(){
	return this->sistema->listarEstudiantes();
}
Estudiante* CursoController::getEstudianteSistema(string usuario) {
	return dynamic_cast<Estudiante*>(this->sistema->usuarios->find(new String(usuario)));
}
Profesor* CursoController::getProfesorSistema(string usuario) {
	return dynamic_cast<Profesor*>(this->sistema->usuarios->find(new String(usuario)));
}
set<string> CursoController::listarCursos(Profesor *profesor){
	return this->sistema->listarCursos(profesor);
}
set<string> CursoController::listarCursosStats(Curso *curso){
	return this->sistema->listarCursosStats(curso);
}

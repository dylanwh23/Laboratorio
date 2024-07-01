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
#include "UsuarioController.h"
#include "algorithm"
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


void CursoController::altaCurso(string nombre,string dificultad,string descripcion,Profesor* profe,Idioma*  idi,bool habilitado,set<string> previaturas){

	IDictionary* previas = new OrderedDictionary();

		set<string>::iterator it;
		for (it = previaturas.begin(); it != previaturas.end(); it++) {
			Curso *aux = dynamic_cast<Curso*>(this->sistema->cursos->find(new String(*it)));
			previas->add(new String(*it), aux);
		}


		Curso* curso = new Curso(nombre,dificultad,descripcion, profe, idi, habilitado, previas);

	this->sistema->cursos->add(new String(nombre), curso);


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
Idioma* CursoController::getIdioma(string idioma){
	return dynamic_cast<Idioma*>(this->sistema->idiomas->find(new String(idioma)));
}
set<string> CursoController::listarCursos(Profesor *profesor){
	return this->sistema->listarCursos(profesor);
}
set<string> CursoController::listarCursosStats(Curso *curso){
	return this->sistema->listarCursosStats(curso);
}

set <string> CursoController::listarCursosInhabilitados(){
return this->sistema->listarCursosInhabilitados();
}

void CursoController::ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes){

	IDictionary *auxit = this->sistema->cursos;
		Curso *cursofinal;
		set<string> lecciones;

		for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

			Curso *auxnom = dynamic_cast<Curso*>(it->getCurrent());
			if (auxnom->getNomCurso() == curso) {
				cursofinal = auxnom;
				break;
			}
		}

		lecciones = cursofinal->listarLecciones();


		IDictionary *auxit2 = cursofinal->getLecciones();
			Leccion *leccionfinal;

			for (IIterator *it = auxit2->getIterator(); it->hasCurrent(); it->next()) {

				Leccion *auxlec = dynamic_cast<Leccion*>(it->getCurrent());
				if (auxlec->getTemaLec() == leccion) {
					leccionfinal = auxlec;
					break;
				}
			}

			Ejercicio* eje = new EjercicioCompletar(nombreEjercicio, desc, frase, palabrasFaltantes);
			leccionfinal->agregarEjercicio(eje);

}

void CursoController::ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase, string traduccion){

	IDictionary *auxit = this->sistema->cursos;
		Curso *cursofinal;
		set<string> lecciones;

		for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

			Curso *auxnom = dynamic_cast<Curso*>(it->getCurrent());
			if (auxnom->getNomCurso() == curso) {
				cursofinal = auxnom;
				break;
			}
		}

		lecciones = cursofinal->listarLecciones();


		IDictionary *auxit2 = cursofinal->getLecciones();
			Leccion *leccionfinal;

			for (IIterator *it = auxit2->getIterator(); it->hasCurrent(); it->next()) {

				Leccion *auxlec = dynamic_cast<Leccion*>(it->getCurrent());
				if (auxlec->getTemaLec() == leccion) {
					leccionfinal = auxlec;
					break;
				}
			}

			Ejercicio* eje = new EjercicioTraduccion(nombreEjercicio, desc, frase, traduccion);
						leccionfinal->agregarEjercicio(eje);

}
void CursoController::habilitarCurso(string curso){
	IDictionary *auxit = this->sistema->cursos;
			Curso *cursofinal;
			set<string> lecciones;

			for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

				Curso *auxnom = dynamic_cast<Curso*>(it->getCurrent());
				if (auxnom->getNomCurso() == curso) {
					cursofinal = auxnom;
					break;
				}
			}
cursofinal->HabilitarCurso();

}
 void CursoController::agregarLeccion(string tema, string objetivo, IDictionary* ejercicios,string nombreCurso){
	 Leccion* lec = new Leccion(tema, objetivo, ejercicios);
	 	Curso *cursofinal;
	 	IDictionary *auxit = this->sistema->cursos;



	 	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

	 			Curso *auxnom = dynamic_cast<Curso*>(it->getCurrent());
	 			if (auxnom->getNomCurso() == nombreCurso) {
	 				cursofinal = auxnom;
	 				break;
	 			}

	 		}

	 	cursofinal->agregarLeccion(lec);


 }

 //incripcion curso
  list<string> CursoController::listarCursosHabilitadosParaElEstudiante(
  		string nickname) {

  	Estudiante *estudiante =
  			static_cast<Estudiante*>(this->sistema->usuarios->find(
  					new String(nickname)));
  	list<Curso*> cursos;


  	if (estudiante) {

  		//accedo a las incripciones del estudiante

  		list<Incripcion> auxInscripciones = estudiante->getInscripciones();
  		list<Incripcion> Inscripciones = auxInscripciones;
  		//recorro estas creando una lista de cursos a los que ya esta inscripto
  		list<Incripcion>::iterator it;
  		list<Curso*> cursosYaInscripto;
  		for (it = auxInscripciones.begin() ; it != auxInscripciones.end() ; it++) {

  			Incripcion auxinc = *(it);
  			cursosYaInscripto.push_back(auxinc.getCurso());
  		}
  		//creo una nueva lista de cursos habilitados a los que no esta inscripto

  		list<Curso*> cursosSistema;
  		for (IIterator *it = this->sistema->cursos->getIterator();
  				it->hasCurrent(); it->next()) {
  			cursosSistema.push_back(dynamic_cast<Curso*>(it->getCurrent()));
  		}

  		cursosYaInscripto.sort();
  		cursosSistema.sort();

  		list<Curso*> CursosNoInscripto;
  		set_difference(cursosSistema.begin(), cursosSistema.end(),
  				cursosYaInscripto.begin(), cursosYaInscripto.end(),
  				back_inserter(CursosNoInscripto));
  		list<Curso*> CursosNoInscriptoHabilitados;

  		list<Curso*>::iterator it2;
  		for (it2 = CursosNoInscripto.begin(); it2 != CursosNoInscripto.end();
  				it2++) {
  			if (dynamic_cast<Curso*>(*it2)->esHabilitado() == true) {
  				CursosNoInscriptoHabilitados.push_back(
  						dynamic_cast<Curso*>(*it2));
  			}
  		}

  		//accedo a la lista de inscripciones aprobadas del estudiante y recupero los cursos
  		list<Curso*> cursosAprobados = estudiante->getCursosAprobados();
  		//recorro la lista de cursos en los que no se ha inscripto y estan habilitados, comparando con la lista de arriba
  		list<Curso*>::iterator it3;

  		for (it3 = CursosNoInscriptoHabilitados.begin();
  				it3 != CursosNoInscriptoHabilitados.end(); it3++) {

  			list<Curso*> previas = dynamic_cast<Curso*>(*it3)->getPrevias();
  			previas.sort();
  			cursosAprobados.sort();
  			bool todasAprovadas = includes(cursosAprobados.begin(), cursosAprobados.end(),
  					previas.begin(), previas.end());
  			if (todasAprovadas == true) {
  				cursos.push_back(dynamic_cast<Curso*>(*it3));
  			}

  		}


  	} else {
  		cout << "Ingrese un estudiante" << endl;
  	}

  	list<string> cursosADevolver;
  	list<Curso*>::iterator it4;

  	for(it4 = cursos.begin() ; it4 != cursos.end() ; it4++){
  		cursosADevolver.push_back(dynamic_cast<Curso*>(*it4)->getNomCurso());
  	}
  	return cursosADevolver;
  }

  bool CursoController::exixteEstudiante(string nick){

  	if(this->sistema->usuarios->find(new String(nick))){
  		Estudiante* estudiante= dynamic_cast<Estudiante*>(this->sistema->usuarios->find(new String(nick)));
  		if(estudiante){
  			return true;
  		}
  		return false;
  	}
  	return false;
  }

  list<string> CursoController::mostrarInfoCurso(string cur){
  	Curso* curso = this->getCursoSistema(cur);
  	list<string> info;
  	int cantidadLecciones;
  	int cantidadEjercicios;
  	cantidadLecciones = curso->getTotalLecciones();
  	cantidadEjercicios = curso->getTotalEjercicios();
  	info.push_back(to_string(cantidadLecciones));
  	info.push_back(to_string(cantidadEjercicios));
  	return info;
  }


  void CursoController::nuevaInscripcion(Curso* curso, string nick){
  	UsuarioController* aux = new UsuarioController();
  	Usuario *usr = aux->getUsuarioSistema(nick);
  	Estudiante* est = dynamic_cast<Estudiante*>(usr);
  	Incripcion *in = new Incripcion(curso, nullptr);
  	est->inscripciones.push_back(*in);

  }

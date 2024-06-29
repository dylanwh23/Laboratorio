/*
 * EjercicioController.cpp
 *
 *  Created on: 29 jun. 2024
 *      Author: machichu
 */

#include "EjercicioController.h"
#include <set>
#include "../ICollections/interfaces/IIterator.h"
#include "../ICollections/collections/OrderedDictionary.h"
#include <iterator>
using namespace std;

EjercicioController::EjercicioController() {
	// TODO Auto-generated constructor stub
	this->sistema = Sistema::getInstance();
}

EjercicioController::~EjercicioController() {
	// TODO Auto-generated destructor stub
}

set<string> EjercicioController::listarCursosInhabilitados(){

	return this->sistema->listarCursosInhabilitados();
}


set<string> EjercicioController::listarLeccionesCurso(string curso){

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

	return lecciones;
}


void EjercicioController::ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes){

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

void EjercicioController::ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase, string traduccion){

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

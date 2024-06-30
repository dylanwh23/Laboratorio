/*
 * Estudiante.h
 *
 *  Created on: Jun 26, 2024
 *      Author: dylan
 */

#ifndef MODELS_ESTUDIANTE_H_
#define MODELS_ESTUDIANTE_H_
#include "Curso.h"
#include "Usuario.h"
#include "Incripcion.h"
#include <list>
using namespace std;
class Estudiante: public Usuario {
private:
	string paisResidencia;
	list<Incripcion> inscripciones;
public:
	Estudiante(string nick, string pass, string nom,string descrip, string pais);
	void insertarInscripciones(list<Incripcion> inscripciones);
	virtual ~Estudiante();
	list<string> mostrarInfo();
	string getNick();
	bool revisarInscripcionesCurso(Curso *curso);
	int ejerciciosHechosInscripciones(Curso *curso);
	void borrarInscripcionesCurso(Curso *curso);
};
#endif /* MODELS_ESTUDIANTE_H_ */

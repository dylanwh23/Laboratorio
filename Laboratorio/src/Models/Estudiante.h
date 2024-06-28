/*
 * Estudiante.h
 *
 *  Created on: Jun 26, 2024
 *      Author: dylan
 */

#ifndef MODELS_ESTUDIANTE_H_
#define MODELS_ESTUDIANTE_H_

#include "Usuario.h"
#include <list>
using namespace std;
class Estudiante: public Usuario {
private:
	string paisResidencia;
public:
	Estudiante(string nick, string pass, string nom,	string descrip, string pais);
	virtual ~Estudiante();
	list<string> mostrarInfo();
	string getNick();
};
#endif /* MODELS_ESTUDIANTE_H_ */

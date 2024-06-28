/*
 * Profesor.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef MODELS_PROFESOR_H_
#define MODELS_PROFESOR_H_
#include "../ICollections/interfaces/IDictionary.h"
#include "Usuario.h"
#include <list>
class Profesor: public Usuario {
private:
	string instituto;
public:
	Profesor();
	Profesor(string nickname, string contraseña, string nombre, string descripcion, string instituto);
	IDictionary* idiomas;
	virtual ~Profesor();
	list<string> mostrarInfo();
};

#endif /* MODELS_PROFESOR_H_ */

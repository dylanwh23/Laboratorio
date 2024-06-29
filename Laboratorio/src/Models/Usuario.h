/*
 * Usuario.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef MODELS_USUARIO_H_
#define MODELS_USUARIO_H_
#include "../ICollections/interfaces/ICollectible.h"
#include "Idioma.h"
#include <iostream>
#include "../ICollections/interfaces/IDictionary.h"
#include <set>
#include <list>
using namespace std;

class Usuario : public ICollectible{
protected:
	string nickname;
	string contraseña;
	string nombre;
	string descripcion;
public:

	Usuario();
	Usuario(string nickname);
	virtual ~Usuario();
	virtual list<string> mostrarInfo() = 0;
	string getNomUsuario();
	string getNick();
};














#endif /* MODELS_USUARIO_H_ */

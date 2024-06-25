/*
 * AltaUsuario.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef VIEWS_ALTAUSUARIO_H_
#define VIEWS_ALTAUSUARIO_H_
#include "../Controllers/IUsuario.h"
class AltaUsuario {
private:
	IUsuario* iusuario;
public:
	AltaUsuario();
	virtual ~AltaUsuario();
	void altaUsuario();
};

#endif /* VIEWS_ALTAUSUARIO_H_ */

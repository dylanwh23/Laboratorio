/*
 * ConsultaUsuario.h
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#ifndef VIEWS_CONSULTAUSUARIO_H_
#define VIEWS_CONSULTAUSUARIO_H_
#include "../Controllers/IUsuario.h"
class ConsultaUsuario {
private:
	IUsuario* iusuario;
public:
	ConsultaUsuario();
	virtual ~ConsultaUsuario();
	void consultaUsuario();
};

#endif /* VIEWS_CONSULTAUSUARIO_H_ */

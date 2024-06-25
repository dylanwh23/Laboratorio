/*
 * UsuarioController.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef CONTROLLERS_USUARIOCONTROLLER_H_
#define CONTROLLERS_USUARIOCONTROLLER_H_
#include "Sistema.h"
#include "IUsuario.h"
class UsuarioController : public IUsuario{
private:
	Sistema* sistema;
public:

	UsuarioController();
	virtual ~UsuarioController();

	virtual bool verificarNick(string nick);
	virtual set<string> listarIdiomas();
	virtual void altaProfesor();
	virtual void altaEstudiante();//
};

#endif /* CONTROLLERS_USUARIOCONTROLLER_H_ */

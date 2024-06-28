/*
 * IUsuario.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef CONTROLLERS_IUSUARIO_H_
#define CONTROLLERS_IUSUARIO_H_
#include "Sistema.h"
#include "../dto/DTOProfesor.h"
#include "../dto/DTOEstudiante.h"
class IUsuario {
public:
	virtual bool verificarNickname(string nick)=0;
	virtual set<string> listarIdiomas()=0;
	virtual void altaProfesor(DTOProfesor* dto)=0;
	virtual void altaEstudiante(DTOEstudiante* dto)=0;
	virtual set<string> listarUsuarios()=0;
	virtual Usuario* getUsuarioSistema(string nick)= 0;

};

#endif /* CONTROLLERS_IUSUARIO_H_ */

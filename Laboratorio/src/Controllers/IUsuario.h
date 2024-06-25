/*
 * IUsuario.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef CONTROLLERS_IUSUARIO_H_
#define CONTROLLERS_IUSUARIO_H_
#include "Sistema.h"
class IUsuario {
public:
	virtual bool verificarNick(string nick)=0;
	virtual set<string> listarIdiomas()=0;
	virtual void altaProfesor()=0;
	virtual void altaEstudiante()=0;// Quiero llamar un metodo de sistema, ya que es sistema el que conoce la lista de idiomas, de paso si necesito acceder a los idiomas nuevamente, lo hago desde sistema y no desde los controladores mas especificos.
};

#endif /* CONTROLLERS_IUSUARIO_H_ */

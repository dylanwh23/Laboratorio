/*
 * AltaUsuario.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef VIEWS_ALTAUSUARIO_H_
#define VIEWS_ALTAUSUARIO_H_
#include "../Controllers/IUsuario.h"
#include "../dto/DTOProfesor.h"
#include "../dto/DTOEstudiante.h"
class AltaUsuario {
private:
	IUsuario* iusuario;
public:
	AltaUsuario();
	virtual ~AltaUsuario();
	void altaUsuario();
	DTOEstudiante* ingresarEstudiante(string nick);
	DTOProfesor* ingresarProfesor(string nick);
	set<string> seleccionarIdiomas();

};

#endif /* VIEWS_ALTAUSUARIO_H_ */

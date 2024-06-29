/*
 * ICurso.h
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */

#ifndef CONTROLLERS_ICURSO_H_
#define CONTROLLERS_ICURSO_H_

#include "Sistema.h"
class ICurso {
public:
	virtual set<string> listarProfesores()=0;
	virtual void altaCurso(string nombreCurso, string dificultad, bool habilitado, set<string> previaturas)=0;
	virtual set<string> listarIdiomasProfesor(string profesor)=0;
	virtual set<string> listarCursosHabilitados()=0;
	virtual list<string> listarCursosHabilitadosParaElEstudiante(string nickname) = 0;
};



#endif /* CONTROLLERS_ICURSO_H_ */

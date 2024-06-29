/*
 * CursoController.h
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */

#ifndef CONTROLLERS_CURSOCONTROLLER_H_
#define CONTROLLERS_CURSOCONTROLLER_H_
#include "Sistema.h"
#include "../Models/Curso.h"
#include "ICurso.h"
#include "../ICollections/interfaces/IIterator.h"

class CursoController : public ICurso{
private:
	Sistema* sistema;
public:
	CursoController();
	virtual ~CursoController();
	 set<string> listarIdiomasProfesor(string profesor);
	 void altaCurso(string nombreCurso, string dificultad, bool habilitado, set<string> previaturas);
	 set<string> listarProfesores();
	 set<string> listarCursosHabilitados();
	 list<string> listarCursosHabilitadosParaElEstudiante(string nickname);

};

#endif /* CONTROLLERS_CURSOCONTROLLER_H_ */
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
	 set<string> listarCursos();
	 set<string> listarCursos(Estudiante *estudiante);
	 set<string> listarCursos(Profesor *profesor);
	 set<string> listarCursosStats(Curso *curso);
	 list<string> listarCursosHabilitadosParaElEstudiante(string nickname);
	 set<string> listarEstudiantes(Curso *curso);
	 Curso* getCursoSistema(string curso);
	 void BorrarIncripciones(Curso *curso);
	 void BorrarCurso(Curso *curso);
	 set<string> listarEstudiantes();
	 Estudiante* getEstudianteSistema(string usuario);
	 Profesor* getProfesorSistema(string usuario);
};

#endif /* CONTROLLERS_CURSOCONTROLLER_H_ */

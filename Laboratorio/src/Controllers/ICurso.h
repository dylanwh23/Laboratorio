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
	virtual set<string> listarCursos()=0;
	virtual set<string> listarCursos(Estudiante *estudiante)=0;
	virtual set<string> listarCursos(Profesor *profesor)=0;
	virtual Curso* getCursoSistema(string curso)= 0;
	virtual set<string> listarEstudiantes(Curso *curso)=0;
	virtual void BorrarIncripciones(Curso *curso)=0;
	virtual void BorrarCurso(Curso *curso)=0;
	virtual set<string> listarEstudiantes()=0;
	virtual set<string> listarCursosStats(Curso *curso)=0;
	virtual Estudiante* getEstudianteSistema(string usuario)= 0;
	virtual Profesor* getProfesorSistema(string usuario)= 0;
	virtual void habilitarCurso(string curso)=0;
	virtual set <string> listarCursosInhabilitados()=0;
	virtual void ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes)=0;
	virtual void ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase, string traduccion)=0;
	virtual void agregarLeccion(string tema, string objetivo, IDictionary* ejercicios,string nombreCurso)=0;


};



#endif /* CONTROLLERS_ICURSO_H_ */

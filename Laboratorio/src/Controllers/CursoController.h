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
	 void altaCurso(string nombre,string dificultad,string descripcion,Profesor* profe,Idioma*  idi,bool habilitado);
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
	 void habilitarCurso(string curso);
	 set <string> listarCursosInhabilitados();
	 void ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes);
	 void ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase, string traduccion);
	 void agregarLeccion(string tema, string objetivo, IDictionary* ejercicios,string nombreCurso);
	 bool exixteEstudiante(string nick);
	 void nuevaInscripcion(Curso* curso, string nick);
	 list<string> mostrarInfoCurso(string cur);
	 Idioma* getIdioma(string idioma);
};

#endif /* CONTROLLERS_CURSOCONTROLLER_H_ */

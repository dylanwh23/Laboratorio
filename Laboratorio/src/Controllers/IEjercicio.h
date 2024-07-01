/*
 * IEjercicio.h
 *
 *  Created on: 29 jun. 2024
 *      Author: machichu
 */

#ifndef CONTROLLERS_IEJERCICIO_H_
#define CONTROLLERS_IEJERCICIO_H_
#include "Sistema.h"
class IEjercicio {
public:
	virtual set<string> listarCursosInhabilitados()=0;
	virtual set<string> listarLeccionesCurso(string curso)=0;
	virtual void ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes)=0;
	virtual void ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase, string traduccion)=0;
	virtual bool verificarNickname(string nickname)=0;
	virtual set<string> listarCursosNoAprobados(string nick)=0;
	virtual set<string> listarEjerciciosEstudiante(string nick, string curso)=0;
	virtual void realizarEjercicio(string nick,string curso, string ejercicio)=0;
	virtual list<string> mostrarEjercicio(string nick, string curso, string ejercicio)=0;
	virtual string getSolucion(string curso, string ejercicio)=0;
};




#endif /* CONTROLLERS_IEJERCICIO_H_ */

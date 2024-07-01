/*
 * EjercicioController.h
 *
 *  Created on: 29 jun. 2024
 *      Author: machichu
 */

#ifndef CONTROLLERS_EJERCICIOCONTROLLER_H_
#define CONTROLLERS_EJERCICIOCONTROLLER_H_
#include "IEjercicio.h"

class EjercicioController : public IEjercicio {
private:
	Sistema* sistema;
public:
	EjercicioController();
	virtual ~EjercicioController();
	set <string> listarCursosInhabilitados();
	set <string> listarLeccionesCurso(string curso);
	void ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes);
	void ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase, string traduccion);
	bool verificarNickname(string nickname);
	set<string> listarCursosNoAprobados(string nick);
	set<string> listarEjerciciosEstudiante(string nick, string curso);
	void realizarEjercicio(string nick,string curso, string ejercicio);
	list<string> mostrarEjercicio(string nick, string curso, string ejercicio);
	string getSolucion(string curso, string ejercicio);

};

#endif /* CONTROLLERS_EJERCICIOCONTROLLER_H_ */

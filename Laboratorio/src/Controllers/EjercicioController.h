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
	void ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase);

};

#endif /* CONTROLLERS_EJERCICIOCONTROLLER_H_ */

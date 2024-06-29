/*
 * AgregarEjercicio.h
 *
 *  Created on: 29 jun. 2024
 *      Author: machichu
 */

#ifndef VIEWS_AGREGAREJERCICIO_H_
#define VIEWS_AGREGAREJERCICIO_H_
#include "../Controllers/IEjercicio.h"

class AgregarEjercicio{
private:
	IEjercicio* Iejercicio;
public:
	AgregarEjercicio();
	virtual ~AgregarEjercicio();
	void agregarEjercicio(string curso, string leccion);
	void listarCursosInhabilitados();
	void listarLeccionesCurso(string curso);
	void ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase);
	void ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase,string palabrasFaltantes);
	void llamarAgregarEjercicio();
};

#endif /* VIEWS_AGREGAREJERCICIO_H_ */

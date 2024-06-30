/*
 * HabilitarCurso.h
 *
 *  Created on: 30 jun. 2024
 *      Author: machichu
 */

#ifndef VIEWS_HABILITARCURSO_H_
#define VIEWS_HABILITARCURSO_H_
#include "../Controllers/ICurso.h"

class HabilitarCurso {
private:
	ICurso* Icurso;


public:
	HabilitarCurso();
	 void SeleccionarCurso();
	void listarCursosInhabilitados();
	void agregarLeccion(string curso);
	void agregarEjercicio(string curso);
	virtual ~HabilitarCurso();

};

#endif /* VIEWS_HABILITARCURSO_H_ */

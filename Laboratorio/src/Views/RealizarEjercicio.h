/*
 * RealizarEjercicio.h
 *
 *  Created on: 29 jun. 2024
 *      Author: machichu
 */

#ifndef VIEWS_REALIZAREJERCICIO_H_
#define VIEWS_REALIZAREJERCICIO_H_
#include "../Controllers/IEjercicio.h"

class RealizarEjercicio {
private:
	IEjercicio* Iejercicio;
public:
	RealizarEjercicio();
	virtual ~RealizarEjercicio();
	void buscarEstudiante();
	void realizarEjercicio(string nick, string curso);
	void hacerEjercicio(string nick, string curso, string ejercicio);
};

#endif /* VIEWS_REALIZAREJERCICIO_H_ */

/*
 * AltaCurso.h
 *
 *  Created on: 27 jun. 2024
 *      Author: machichu
 */
#ifndef VIEWS_ALTACURSO_H_
#define VIEWS_ALTACURSO_H_
#include "../Controllers/ICurso.h"

class AltaCurso {
private:
	ICurso* Icurso;
public:
	AltaCurso();
	virtual ~AltaCurso();
	string seleccionarProfesor();
	string seleccionarIdioma(string profesor);
	set<string> seleccionarPreviaturas();
	void altaCurso();
};

#endif /* VIEWS_ALTACURSO_H_ */

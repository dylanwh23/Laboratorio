/*
 * IncribirseACurso.h
 *
 *  Created on: Jun 28, 2024
 *      Author: dylan
 */

#ifndef VIEWS_INCRIBIRSEACURSO_H_
#define VIEWS_INCRIBIRSEACURSO_H_
#include <list>
#include <iostream>
#include "../Controllers/ICurso.h"

using namespace std;

class IncribirseACurso {
private:
	ICurso* icurso;
public:
	IncribirseACurso();
	virtual ~IncribirseACurso();
	list<string> seleccionarCursos(string nickname);
};

#endif /* VIEWS_INCRIBIRSEACURSO_H_ */

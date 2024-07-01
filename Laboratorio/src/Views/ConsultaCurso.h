/*
 * ConsultaUsuario.h
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#ifndef VIEWS_CONSULTACURSO_H_
#define VIEWS_CONSULTACURSO_H_
#include "../Controllers/ICurso.h"
class ConsultaCurso {
private:
	ICurso* icurso;
public:
	ConsultaCurso();
	virtual ~ConsultaCurso();
	void consultaCurso();
};

#endif /* VIEWS_CONSULTACURSO_H_ */

/*
 * ConsultaUsuario.h
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#ifndef VIEWS_BORRARCURSO_H_
#define VIEWS_BORRARCURSO_H_
#include "../Controllers/ICurso.h"
class BorrarCurso {
private:
	ICurso* icurso;
public:
	BorrarCurso();
	virtual ~BorrarCurso();
	void borrarCurso();
};

#endif /* VIEWS_BorrarCursoCURSO_H_ */

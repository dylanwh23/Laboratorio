/*
 * LeccionController.h
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#ifndef CONTROLLERS_LECCIONCONTROLLER_H_
#define CONTROLLERS_LECCIONCONTROLLER_H_
#include "ILeccion.h"
#include "Sistema.h"
#include <set>

class LeccionController : public ILeccion{
private:
	Sistema* sistema;
public:
	LeccionController();
	virtual ~LeccionController();
	set<string> listarCursosInhabilitados();
	void agregarLeccion(string tema, string objetivo, IDictionary* ejercicios,string nombreCurso);

};

#endif /* CONTROLLERS_LECCIONCONTROLLER_H_ */

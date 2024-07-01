/*
 * IdiomaController.h
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#ifndef CONTROLLERS_IDIOMACONTROLLER_H_
#define CONTROLLERS_IDIOMACONTROLLER_H_

#include "IIdioma.h"
#include <set>

class IdiomaController: public IIdioma {
private:
	Sistema* sistema;
public:
	IdiomaController();
	virtual ~IdiomaController();
	set<string> listarIdiomas();
	void altaIdioma(string nomreIdioma);
	bool verificarIdioma(string nombreIdioma);
	void inicializarDatos();

};

#endif /* CONTROLLERS_IDIOMACONTROLLER_H_ */

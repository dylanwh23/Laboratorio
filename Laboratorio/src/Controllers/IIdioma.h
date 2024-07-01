/*
 * IIdioma.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef CONTROLLERS_IIDIOMA_H_
#define CONTROLLERS_IIDIOMA_H_
#include "Sistema.h"
class IIdioma {
public:
	virtual void altaIdioma(string nombreIdioma)=0;
	virtual set<string> listarIdiomas()=0;
	virtual void inicializarDatos()=0;
};

#endif /* CONTROLLERS_IIDIOMA_H_ */

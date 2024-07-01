/*
 * ConsultaIdioma.h
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#ifndef VIEWS_CONSULTAIDIOMA_H_
#define VIEWS_CONSULTAIDIOMA_H_
#include "../Controllers/IIdioma.h"


class ConsultaIdioma {
private:
	IIdioma* iidioma;
public:
	void consultaIdioma();
	ConsultaIdioma();
	virtual ~ConsultaIdioma();
};

#endif /* VIEWS_CONSULTAIDIOMA_H_ */

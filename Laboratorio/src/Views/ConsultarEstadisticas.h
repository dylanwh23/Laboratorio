/*
 * ConsultaUsuario.h
 *
 *  Created on: Jun 27, 2024
 *      Author: dylan
 */

#ifndef VIEWS_CONSULTARESTADISTICAS_H_
#define VIEWS_CONSULTARESTADISTICAS_H_
#include "../Controllers/ICurso.h"
class ConsultarEstadisticas {
private:
	ICurso* icurso;
public:
	ConsultarEstadisticas();
	virtual ~ConsultarEstadisticas();
	void consultarEstadisticas();
};

#endif /* VIEWS_CONSULTARESTADISTICAS_H_ */

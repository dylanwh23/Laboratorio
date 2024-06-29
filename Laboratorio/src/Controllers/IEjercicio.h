/*
 * IEjercicio.h
 *
 *  Created on: 29 jun. 2024
 *      Author: machichu
 */

#ifndef CONTROLLERS_IEJERCICIO_H_
#define CONTROLLERS_IEJERCICIO_H_
#include "Sistema.h"
class IEjercicio {
public:
	virtual set<string> listarCursosInhabilitados()=0;
	virtual set<string> listarLeccionesCurso(string curso)=0;
	virtual void ingresarEjercicioCompletar(string curso, string leccion, string nombreEjercicio, string desc, string frase, string palabrasFaltantes)=0;
	virtual void ingresarEjercicioTraducir(string curso, string leccion, string nombreEjercicio, string desc, string frase)=0;
};




#endif /* CONTROLLERS_IEJERCICIO_H_ */

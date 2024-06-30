/*
 * ILeccion.h
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#ifndef CONTROLLERS_ILECCION_H_
#define CONTROLLERS_ILECCION_H_
#include "Sistema.h"

class ILeccion {
public:
virtual set<string> listarCursosInhabilitados()=0;
virtual void agregarLeccion(string tema, string objetivo, IDictionary* ejercicios,string nombreCurso)=0;
};



#endif /* CONTROLLERS_ILECCION_H_ */

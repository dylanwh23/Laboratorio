/*
 * AgregarLeccion.h
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#ifndef VIEWS_AGREGARLECCION_H_
#define VIEWS_AGREGARLECCION_H_
#include "../Controllers/ILeccion.h"
#include "../Models/Ejercicio.h"
class AgregarLeccion {
private:
ILeccion* Ileccion;
public:
AgregarLeccion();
virtual ~AgregarLeccion();
set<string> listarCursosInhabilitados();
void agregarLeccion(string curso);
IDictionary* agregarEjercicio();
void llamarAgregarLeccion();
void agregarLeccionObligatorio(string curso);
};

#endif /* VIEWS_AGREGARLECCION_H_ */

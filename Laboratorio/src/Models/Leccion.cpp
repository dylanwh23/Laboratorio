/*
 * Lecciones.cpp
 *
 *  Created on: 28 jun. 2024
 *      Author: machichu
 */

#include "Leccion.h"
#include "../ICollections/String.h"
#include "../ICollections/collections/OrderedDictionary.h"

Leccion::Leccion(string tema, string objetivo, IDictionary* ejercicios) {
// TODO Auto-generated constructor stub
this->tema = tema;
this->objetivo = objetivo;
this->ejercicios = ejercicios;
}

Leccion::~Leccion() {
// TODO Auto-generated destructor stub
}

string Leccion::getTemaLec(){
return this->tema;
}

void Leccion::agregarEjercicio(Ejercicio *eje){

	this->ejercicios = new OrderedDictionary();
	this->ejercicios->add(new String(eje->getNom()), eje);


}

int Leccion::contarEjercicios(){
	return this->ejercicios->getSize();
}
void Leccion::borrarLecciones(){
	for (IIterator *it = this->ejercicios->getIterator(); it->hasCurrent();it->next()) {
		Ejercicio *auxEje = dynamic_cast<Ejercicio*>(it->getCurrent());
		this->ejercicios->remove(new String(auxEje->getNom()));
		auxEje->~Ejercicio();
	}


}


set<string> Leccion::listarEjercicios(){
	set<string> auxlecciones;
				IDictionary *auxit = this->ejercicios;
				for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
					Ejercicio* auxnom = dynamic_cast<Ejercicio*>(it->getCurrent());
						auxlecciones.insert(auxnom->getNom());

				}

			return auxlecciones;
}


IDictionary* Leccion::getEjercicios(){
	return this->ejercicios;
}


/*
 * Idioma.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef MODELS_IDIOMA_H_
#define MODELS_IDIOMA_H_
#include "../ICollections/interfaces/ICollectible.h"
#include <iostream>
using namespace std;

class Idioma : public ICollectible{
private:
	string nomIdioma;
public:


	Idioma();
	Idioma(string idioma);
	virtual ~Idioma();
	string getNomIdioma();
};

#endif /* MODELS_IDIOMA_H_ */

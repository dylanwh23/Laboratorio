/*
 * Usuario.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "Usuario.h"

Usuario::Usuario() {
	// TODO Auto-generated constructor stub

}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}
Usuario::Usuario(string nick) {
	// TODO Auto-generated constructor stub
	this->nickname = nick;
}
string Usuario::getNomUsuario(){
	return this->nickname;
}

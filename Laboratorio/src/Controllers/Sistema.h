/*
 * Sistema.h
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#ifndef CONTROLLERS_SISTEMA_H_
#define CONTROLLERS_SISTEMA_H_
#include "../ICollections/interfaces/IDictionary.h"
#include "../ICollections/String.h"
#include "../Models/Idioma.h"
#include "../Models/Usuario.h"
#include "../Models/Profesor.h"
#include "../Models/Estudiante.h"
#include "../Models/Leccion.h"
#include "../Models/Curso.h"
#include <set>

using namespace std;

class Sistema{
private:
	Sistema(); //declaro el constructor como privado
	static Sistema* miSistema;	//puntero a la unica intancia de Sistema
	void inicializarDatos();
public:
	IDictionary* usuarios;
	IDictionary* idiomas;
	IDictionary* cursos;

	static Sistema* getInstance(); //metodo de clase que devuele siempre la misma instancia
	virtual ~Sistema();
	set<string> listarIdiomas();
	set<string> listarProfesores();
	set<string> listarUsuarios();
	set<string> listarCursosHabilitados();
	set<string> listarCursos();
	set<string> listarIdiomasProfesor(string profesor);
	bool verificarNickname(string nickname);
	bool verificarIdioma(string nombreIdioma);
	set<string> listarCursosInhabilitados();

};























#endif /* CONTROLLERS_SISTEMA_H_ */

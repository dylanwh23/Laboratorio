/*
 * IncribirseACurso.cpp
 *
 *  Created on: Jun 28, 2024
 *      Author: dylan
 */

#include "IncribirseACurso.h"
#include "../Controllers/CursoController.h"

IncribirseACurso::IncribirseACurso() {
	// TODO Auto-generated constructor stub
	this->icurso = new CursoController();

}

IncribirseACurso::~IncribirseACurso() {
	// TODO Auto-generated destructor stub
}

list<string> IncribirseACurso::seleccionarCursos(string nickname) {
	return this->icurso->listarCursosHabilitadosParaElEstudiante(nickname);
}

void IncribirseACurso::incribirseACurso() {
	string nomUsr;
	string cur;
	cout << "Ingrese nickname del estudiante: " << endl;
	cin >> nomUsr;


	if(this->icurso->exixteEstudiante(nomUsr)){
		list<string> cursosRecibidos = this->seleccionarCursos(nomUsr);

			list<string>::iterator it;
			for (it = cursosRecibidos.begin(); it != cursosRecibidos.end(); it++) {
				list<string> infoCurso = this->icurso->mostrarInfoCurso(*it);
				cout <<"Nombre: "<<*it <<endl;
				cout <<"Cantidad Ejercicios: "<<*infoCurso.begin()<<endl;
				auto it = infoCurso.begin();
				advance(it, 1);
				cout <<"Cantidad Lecciones: "<<*it<<endl;
			}
		cout<<"Ingrese el curso al que desea inscribirse:"<<endl;
		cin.ignore();
		getline(cin,cur);

		Curso* nuevoCurso = this->icurso->getCursoSistema(cur);
		if(nuevoCurso != NULL){
			this->icurso->nuevaInscripcion(nuevoCurso, nomUsr);
			cout<<"Usted se ha inscripto correctamete."<<endl;
		}else{
			cout << "Escribi bien mongolico :p" <<endl;
		}




	}else{
		cout<<"Ingrese el nickname de un estudiante valido."<<endl;
	}




}

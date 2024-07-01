/*
 * HabilitarCurso.cpp
 *
 *  Created on: 30 jun. 2024
 *      Author: machichu
 */

#include "HabilitarCurso.h"
#include <string>
#include "../Controllers/ICurso.h"
#include "../Controllers/CursoController.h"
#include "AgregarLeccion.h"
#include "AgregarEjercicio.h"

HabilitarCurso::HabilitarCurso() {
	// TODO Auto-generated constructor stub
	this->Icurso = new CursoController();
}

HabilitarCurso::~HabilitarCurso() {
	// TODO Auto-generated destructor stub
}

void HabilitarCurso::listarCursosInhabilitados(){

	set<string> cursosInhabilitados =this->Icurso->listarCursosInhabilitados();
		set<string>::iterator it;

		for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();
				it++) {
			cout << "Curso Inhabilitado: " << *it << endl;
		}
		this->SeleccionarCurso();
	}

void HabilitarCurso::SeleccionarCurso(){
	set<string> cursosInhabilitados = this->Icurso->listarCursosInhabilitados();
	set<string>::iterator it;
	int mientras = 0;

	do {
		cin.ignore();
		string curso;
		cout<<"ingrese un curso(S/s para salir): "<<endl;
		getline(cin,curso);
		if (curso != "s" && curso != "S"){

			if(cursosInhabilitados.find(curso)!=cursosInhabilitados.end()){

				for (it = cursosInhabilitados.begin(); it != cursosInhabilitados.end();it++) {

					if(curso==*it){
					cout<<"Curso seleccionado: "<< curso << endl;
					this->agregarLeccion(curso);
					mientras = 1;
					}

				}
			}else{
				cout << "El curso ingresado no esta en la lista, ingrese un curso de la lista: " << endl;

			}


		}else{
			break;
		}
	} while (mientras == 0);



}

void HabilitarCurso::agregarLeccion(string curso){

		string objetivo;
		string nombreCurso = curso;
		string tema;

		 this->agregarEjercicio(curso);


}


void HabilitarCurso::agregarEjercicio(string curso){
	int tipoEjercicio;
		string nombreEjercicio;
		string frase;
		string desc;
		string palabrasFaltantes;
		string traduccion;
		string leccion;
		string objetivo;
		IDictionary* ejercicios;

		AgregarLeccion coso2;
		coso2.agregarLeccionObligatorio(curso);

//			cout << "Ingrese el objetivo de la leccion : " << endl;
//			getline(cin,objetivo);
//			cout << "Ingrese el tema de la leccion : " << endl;
//			getline(cin,leccion);
//
//			this->Icurso->agregarLeccion(leccion, objetivo, ejercicios, curso);
//		cout << "Ingrese tipo de ejercicio:" << endl << "(1-Completar 2-Traduccion)"<< endl;
//		cin >> tipoEjercicio;
//		cin.ignore();
//		if (tipoEjercicio == 1) {
//
//			cout << "Ingrese el nombre del ejercicio: " << endl;
//			getline(cin,nombreEjercicio);
//			cout << "Ingrese descripcion del ejercicio: " << endl;
//			getline(cin,desc);
//			cout << "Ingrese la frase del ejercicio completa: " << endl;
//			getline(cin,frase);
//			cout << "Ingrese la frase incompleta: " << endl;
//			getline(cin,palabrasFaltantes);
//
//			this->Icurso->ingresarEjercicioCompletar(curso, leccion, nombreEjercicio, desc, frase, palabrasFaltantes);
//
//		} else {
//
//
//			cout << "Ingrese el nombre del ejercicio: " << endl;
//			getline(cin,nombreEjercicio);
//			cout << "Ingrese descripcion del ejercicio: " << endl;
//			getline(cin,desc);
//			cout << "Ingrese la frase del ejercicio: " << endl;
//			getline(cin,frase);
//			cout << "Ingrese la traduccion del ejercicio: " << endl;
//			getline(cin,traduccion);
//			this->Icurso->ingresarEjercicioTraducir(curso, leccion, nombreEjercicio, desc, frase, traduccion);
//
//		}

		cout << "Ejercicio ingresado " << endl;
      this->Icurso->habilitarCurso(curso);

}

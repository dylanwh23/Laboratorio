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
		string curso;
		cout<<"ingrese un curso(S/s para salir): "<<endl;
		cin>>curso;
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


			cout << "Ingrese el objetivo de la leccion : " << endl;
			cin >> objetivo;
			cout << "Ingrese el tema de la leccion : " << endl;
			cin >> leccion;

			this->Icurso->agregarLeccion(leccion, objetivo, ejercicios, curso);

		cout << "Ingrese tipo de ejercicio:" << endl << "(1-Completar 2-Traduccion"<< endl;

		cin >> tipoEjercicio;

		if (tipoEjercicio == 1) {

			cout << "Ingrese el nombre del ejercicio: " << endl;
			cin >> nombreEjercicio;
			cout << "Ingrese descripcion del ejercicio: " << endl;
			cin >> desc;
			cout << "Ingrese la frase del ejercicio completa: " << endl;
			cin >> frase;
			cout << "Ingrese la frase incompleta: " << endl;
			cin >> palabrasFaltantes;

			this->Icurso->ingresarEjercicioCompletar(curso, leccion, nombreEjercicio, desc, frase, palabrasFaltantes);

		} else {


			cout << "Ingrese el nombre del ejercicio: " << endl;
			cin >> nombreEjercicio;
			cout << "Ingrese descripcion del ejercicio: " << endl;
			cin >> desc;
			cout << "Ingrese la frase del ejercicio: " << endl;
			cin >> frase;
			cout << "Ingrese la traduccion del ejercicio: " << endl;
					cin >> traduccion;
			this->Icurso->ingresarEjercicioTraducir(curso, leccion, nombreEjercicio, desc, frase, traduccion);
		}

		cout << "Ejercicio ingresado " << endl;
      this->Icurso->habilitarCurso(curso);

}

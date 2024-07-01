/*
 * RealizarEjercicio.cpp
 *
 *  Created on: 29 jun. 2024
 *      Author: machichu
 */
#include "../Controllers/IEjercicio.h"
#include "../Controllers/EjercicioController.h"
#include "RealizarEjercicio.h"

RealizarEjercicio::RealizarEjercicio() {
	// TODO Auto-generated constructor stub
	this->Iejercicio = new EjercicioController();
}

RealizarEjercicio::~RealizarEjercicio() {
	// TODO Auto-generated destructor stub
}


void RealizarEjercicio::buscarEstudiante(){
	set <string> cursosNoAprobados;
	int mientras=0;
	string nick;
	string curso;
	int mientras2 =0;

	do {
		cout << "Ingrese nick (S/s para salir): "<< endl;
		cin >> nick;
		if (nick != "s" && nick != "S") {
			if (this->Iejercicio->verificarNickname(nick) == false) {

				cursosNoAprobados = this->Iejercicio->listarCursosNoAprobados(nick);
				set<string>::iterator it;

				for (it = cursosNoAprobados.begin();it != cursosNoAprobados.end(); it++) {
					cout << "Curso no aprobado: " << *it << endl;
					mientras = 1;

				}


				do{
					cout << "Ingrese un curso de la lista(s/S para salir): ";
					cin >> curso;
					if(curso != "s" && curso != "S"){
						if(cursosNoAprobados.find(curso)!=cursosNoAprobados.end()){
							this->realizarEjercicio(nick, curso);
							break;
						}else{
							cout << "El curso ingresado no esta en la lista " << endl;
					}
					}else{
						mientras2=1;
					}

				}while(mientras2 == 0);
			} else {

				cout<< "El nick ingresado no pertenece a un estudiante o no existe"<< endl;
			}
		} else{
			mientras = 1;
		}


	} while (mientras == 0);





}

void RealizarEjercicio::realizarEjercicio(string nick, string curso){

	set <string> ejerciciosCurso;
	string ejercicio;
	set<string>::iterator it;
	int listar=1;

	do{


		ejerciciosCurso = this->Iejercicio->listarEjerciciosEstudiante(nick, curso);
		for (it = ejerciciosCurso.begin(); it != ejerciciosCurso.end();it++) {
							cout << "Ejercicio: " << *it << endl;
						}
		cout << "Ingrese un ejercicio de la lista(s/S para salir): ";
		cin >> ejercicio;
		if(ejercicio != "s" && ejercicio != "S"){

			if (listar == 1) {
				set<string> auxejerciciosCurso =this->Iejercicio->listarEjerciciosEstudiante(nick, curso);

				if (auxejerciciosCurso.find(ejercicio)!= auxejerciciosCurso.end()) {
					this->hacerEjercicio(nick, curso, ejercicio);
					break;
				} else {
					cout << endl
							<< "El ejercicio ingresado no pertenece a la lista, ¿Desea ingresar un ejercicio otra vez?(1-Si 2-No): "
							<< endl;
					cin >> listar;
					break;

				}

			}
		}else{
			break;
		}


	}while(listar == 1);


}

void RealizarEjercicio::hacerEjercicio(string nick, string curso, string ejercicio){


	list<string> eje = this->Iejercicio->mostrarEjercicio(nick, curso, ejercicio);
	string solucion;
	string solucionEjercicio = this->Iejercicio->getSolucion(curso, ejercicio);
	list<string>::iterator itEjeInfo;
	int hacerEje = 1;

	itEjeInfo = eje.begin();//principio de la lista de string

		cout << "Nombre: " <<*itEjeInfo << endl;
		advance(itEjeInfo,1);//desripcion
		cout << "Descripcion: "<< *itEjeInfo << endl;
		advance(itEjeInfo,1);//frase
		cout << "Frase: " << *itEjeInfo << endl;

		do{

		cout << endl << "Ingrese la solucion del ejercicio: ";
		cin >> solucion;

		if(solucion == solucionEjercicio){

			cout << "Felicidades, ha aprobado el ejercicio!" << endl;
			cout << "La respuesta correcta era: " << solucionEjercicio <<endl;
			hacerEje=2;
			this->Iejercicio->realizarEjercicio(nick, curso, ejercicio);

		}else{

			cout << "La respuesta no es correcta :c " << endl;
			cout << "¿Desea intentarlo nuevamente? (1-Si 2-No)" << endl;
			cin >> hacerEje;
		}
		}while(hacerEje == 1);


		this->realizarEjercicio(nick, curso);


}


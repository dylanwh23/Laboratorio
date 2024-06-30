#include "Sistema.h"

#include <iostream>
#include <string>

#include "../ICollections/collections/OrderedDictionary.h"
#include "../ICollections/interfaces/IIterator.h"
#include "../ICollections/String.h"
#include "../Models/Profesor.h"
#include "../Models/Leccion.h"


Sistema *Sistema::miSistema = nullptr;
using namespace std;

Sistema::Sistema() {
	// TODO Auto-generated constructor stub

}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

Sistema* Sistema::getInstance() {
	if (Sistema::miSistema == nullptr) {
		Sistema::miSistema = new Sistema();
		Sistema::miSistema->inicializarDatos();
	}
	return Sistema::miSistema;

}

void Sistema::inicializarDatos() {
	//inicializo los idiomas del sistema

	this->idiomas = new OrderedDictionary();
	this->usuarios = new OrderedDictionary();
	this->cursos = new OrderedDictionary();

	cout << "Comienza inicializacion Sistema " << endl;

	Idioma *idioma1 = new Idioma("Ingles");
	Idioma *idioma2 = new Idioma("Espaniol");
	Idioma *idioma3 = new Idioma("Aleman");

	this->idiomas->add(new String("Ingles"), idioma1);
	this->idiomas->add(new String("Espaniol"), idioma2);
	this->idiomas->add(new String("Aleman"), idioma3);


	Usuario *usr1 = new Profesor("gualberto666", "asd", "berto", "profesor","cure");
	Usuario *usr2 = new Profesor("gualberto777", "asd", "berto", "profesor","cure");
	Usuario *usr3 = new Profesor("gualberto888", "asd", "berto", "profesor","cure");
	Usuario *usr4 = new Estudiante("est1", "asd", "berto", "profesor","cure");
	Usuario *usr5 = new Estudiante("est2", "asd", "berto", "profesor","cure");

	this->usuarios->add(new String("gualberto666"), usr1);
	this->usuarios->add(new String("gualberto777"), usr2);
	this->usuarios->add(new String("gualberto888"), usr3);
	this->usuarios->add(new String("est1"), usr4);
	this->usuarios->add(new String("est2"), usr5);

	IDictionary* ejercicios = new OrderedDictionary();
	Ejercicio *ej1 = new EjercicioCompletar("deber", "comprtaralgomijo","abnansd", "habansa");
	ejercicios->add(new String("deber"), ej1);

	IDictionary* ejercicios2 = new OrderedDictionary();
	Ejercicio *ej2 = new EjercicioCompletar("debermeta", "ghacxealgo","abnansd", "habansa");
	Ejercicio *ej3= new EjercicioTraduccion("debermeta2", "trduce","abnansd", "habansa");
	ejercicios2->add(new String("debermeta2"), ej3);
	ejercicios2->add(new String("debermeta"), ej2);

	IDictionary* lecciones = new OrderedDictionary();
	Leccion *leccion1 = new Leccion("historia", "Facil",ejercicios);
	lecciones->add(new String("historia"), leccion1);

	IDictionary* lecciones2 = new OrderedDictionary();
	Leccion *leccion2 = new Leccion("historia", "Facil",ejercicios);
	Leccion *leccion3 = new Leccion("metafisica", "Facil",ejercicios2);
	lecciones2->add(new String("metafisica"), leccion3);
	lecciones2->add(new String("historia"), leccion2);

	IDictionary* previaturas = new OrderedDictionary();
	Curso *curso4 = new Curso("indu", "Facil",true);
	previaturas->add(new String("indu"), curso4);
	Profesor* prof = dynamic_cast<Profesor*>(this->usuarios->find(new String("gualberto666")));
	Curso *curso1 = new Curso("Ingles", "Facil",true,prof,idioma1,previaturas,lecciones);
	Curso *curso2 = new Curso("Aleman", "Facil",false,prof,idioma1,previaturas,lecciones2);
	Curso *curso3 = new Curso("Espaniol", "Facil",false,prof,idioma1,previaturas,lecciones);


	this->cursos->add(new String("Ingles"), curso1);
	this->cursos->add(new String("Aleman"), curso2);
	this->cursos->add(new String("Espaniol"), curso3);

	list<Incripcion> inscripciones;
	Incripcion *inscripcion1 = new Incripcion(curso2,ejercicios2);
	inscripciones.push_back(*inscripcion1);
	list<Incripcion> inscripciones2;
	Incripcion *inscripcion2 = new Incripcion(curso1,ejercicios);
	Incripcion *inscripcion3 = new Incripcion(curso2,ejercicios);
	Incripcion *inscripcion4 = new Incripcion(curso3,ejercicios);
	inscripciones2.push_back(*inscripcion2);
	inscripciones2.push_back(*inscripcion3);
	inscripciones2.push_back(*inscripcion4);
	Estudiante* estudiante = dynamic_cast<Estudiante*>(this->usuarios->find(new String("est1")));
	Estudiante* estudiante2 = dynamic_cast<Estudiante*>(this->usuarios->find(new String("est2")));
	estudiante->insertarInscripciones(inscripciones);
	estudiante2->insertarInscripciones(inscripciones2);


	cout << "Fin inicializacion Sistema " << endl;
}
set<string> Sistema::listarUsuarios() {
	set<string> aux;
	IDictionary *auxit = this->usuarios;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

		Usuario *auxnom = static_cast<Usuario*>(it->getCurrent());
		aux.insert(auxnom->getNomUsuario());
	}
	return aux;
}

set<string> Sistema::listarCursosHabilitados() {
	set<string> aux;
	IDictionary *auxit = this->cursos;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
		if (static_cast<Curso*>(it->getCurrent())->esHabilitado() == true) {
			Curso *auxcur = dynamic_cast<Curso*>(it->getCurrent());
			aux.insert(auxcur->getNomCurso());
		}
	}
	return aux;
}
set<string> Sistema::listarCursos() {
	set<string> aux;
	IDictionary *auxit = this->cursos;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
			Curso *auxcur = dynamic_cast<Curso*>(it->getCurrent());
			aux.insert(auxcur->getNomCurso());
	}
	return aux;
}

set<string> Sistema::listarIdiomas() {
	set<string> aux;
	IDictionary *auxit = this->idiomas;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

		Idioma *auxnom = dynamic_cast<Idioma*>(it->getCurrent());
		aux.insert(auxnom->getNomIdioma());
	}
	return aux;
}
bool Sistema::verificarNickname(string nickname){
	if(this->usuarios->member(new String(nickname))==true){
		return false;
	}
	return true;

}

bool Sistema::verificarIdioma(string nombreIdioma){
	if(this->idiomas->member(new String(nombreIdioma))==true){
			return false;
		}
		return true;

}

set<string> Sistema::listarIdiomasProfesor(string profesor) {
	string nick;
	set<string> aux;
	//casteo la instancia de profesor para luego obtener sus idiomas, recorrerlos y devolverlos

	Usuario* usuarioSeleccionado = dynamic_cast<Usuario*>(this->usuarios->find(new String(profesor)));

	Profesor *profesorSeleccionado = static_cast<Profesor*>(usuarioSeleccionado);
	IDictionary *auxit = profesorSeleccionado->idiomas;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

	aux.insert(static_cast<Idioma*>(it->getCurrent())->getNomIdioma());

	}
	return aux;

}

set<string> Sistema::listarProfesores() {

	set<string> aux;
	IDictionary *auxit = this->usuarios;

	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

		Profesor* auxnom = dynamic_cast<Profesor*>(it->getCurrent());
		if(auxnom){
			aux.insert(auxnom->getNick());
		}
	}

	return aux;

}

set<string> Sistema::listarCursosInhabilitados() {

    	set<string> aux;
        IDictionary* auxit = this->cursos;

        for (IIterator* it = auxit->getIterator(); it->hasCurrent(); it->next()) {
            if (dynamic_cast<Curso*>(it->getCurrent())->esHabilitado() == false) {
                Curso* auxcur = dynamic_cast<Curso*>(it->getCurrent());
                aux.insert(auxcur->getNomCurso());
            }
        }
        return aux;
}
set<string> Sistema::listarEstudiantes(Curso *curso){
	set<string> aux;
	IDictionary *auxit = this->usuarios;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
		Estudiante* auxEst = dynamic_cast<Estudiante*>(it->getCurrent());
		if(auxEst){
			if(auxEst->revisarInscripcionesCurso(curso)==true){
			aux.insert(auxEst->getNomUsuario());
		}
	}
}
	return aux;

}
void Sistema::BorrarIncripciones(Curso *curso){
	IDictionary *auxit = this->usuarios;
		for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
			Estudiante* auxEst = dynamic_cast<Estudiante*>(it->getCurrent());
			if(auxEst){
				auxEst->borrarInscripcionesCurso(curso);
		}
	}
}
void Sistema::BorrarCurso(Curso *curso){
	this->cursos->remove(new String(curso->getNomCurso()));
	curso->~Curso();
}
set<string> Sistema::listarEstudiantes(){
	set<string> aux;
		IDictionary *auxit = this->usuarios;

		for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

			Estudiante* auxnom = dynamic_cast<Estudiante*>(it->getCurrent());
			if(auxnom){
				aux.insert(auxnom->getNick());
			}
		}

		return aux;

}
set<string> Sistema::listarCursos(Estudiante *estudiante){
	set<string> aux;
		IDictionary *auxit = this->cursos;
		for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
				Curso *auxcur = dynamic_cast<Curso*>(it->getCurrent());
				if(estudiante->revisarInscripcionesCurso(auxcur)==true){
				float tamanioEjercicios = auxcur->cantidadEjercicios();
				int tamanioEjerciciosHechos = estudiante->ejerciciosHechosInscripciones(auxcur);
				//cout<<tamanioEjercicios<<"/"<<tamanioEjerciciosHechos<<endl;
				float porcentajeCambio =(((tamanioEjerciciosHechos)/tamanioEjercicios)*100);
				aux.insert(auxcur->getNomCurso()+"   %"+ to_string(porcentajeCambio));

				}
		}
		return aux;
}
set<string> Sistema::listarCursos(Profesor *profesor) {
	set<string> aux;
	IDictionary *auxit = this->cursos;
	IDictionary *auxus = this->usuarios;
	int sumaNotas = 0;
	int promedio ;
	int cantidad ;
	for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {
		promedio = 0;
		cantidad = 0;
		Curso *auxcur = dynamic_cast<Curso*>(it->getCurrent());
		if (auxcur->getProfesor() == profesor) {
			for (IIterator *it = auxus->getIterator(); it->hasCurrent();it->next()) {

				Estudiante *auxEst = dynamic_cast<Estudiante*>(it->getCurrent());
				if (auxEst) {
					if (auxEst->revisarInscripcionesCurso(auxcur) == true) {
						cantidad++;
						float tamanioEjercicios = auxcur->cantidadEjercicios();
						int tamanioEjerciciosHechos = auxEst->ejerciciosHechosInscripciones(auxcur);
						float porcentajeCambio =(((tamanioEjerciciosHechos)/tamanioEjercicios)*100);
						promedio = promedio+porcentajeCambio;
						//aux.insert(auxcur->getNomCurso()+" " + auxEst->getNomUsuario()+" "+to_string(porcentajeCambio));
					}
				}

			}
			aux.insert(auxcur->getNomCurso()+"  promedio del grado de avance %"+to_string(promedio/cantidad));
		}
	}
	return aux;
}
set<string> Sistema::listarCursosStats(Curso *curso) {
	set<string> aux;
	IDictionary *auxit = this->cursos;
	IDictionary *auxus = this->usuarios;
	int sumaNotas = 0;
	int promedio = 0;
	int cantidad = 0;
	for (IIterator *it = auxus->getIterator(); it->hasCurrent(); it->next()) {

		Estudiante *auxEst = dynamic_cast<Estudiante*>(it->getCurrent());
		if (auxEst) {
			if (auxEst->revisarInscripcionesCurso(curso) == true) {
				cantidad++;
				float tamanioEjercicios = curso->cantidadEjercicios();
				int tamanioEjerciciosHechos =
						auxEst->ejerciciosHechosInscripciones(curso);
				float porcentajeCambio = (((tamanioEjerciciosHechos)
						/ tamanioEjercicios) * 100);
				promedio = promedio + porcentajeCambio;
				//aux.insert(auxcur->getNomCurso()+" " + auxEst->getNomUsuario()+" "+to_string(porcentajeCambio));
			}
		}
	}
		list<string> aux2 = curso->mostrarInfo();
		list<string>::iterator itCursoInfo;
		itCursoInfo = aux2.begin();
		advance(itCursoInfo, 1);
		string Dificultad = *itCursoInfo ;
		advance(itCursoInfo, 1);
		string Profesor =*itCursoInfo;
		advance(itCursoInfo, 1);
		string Idioma = *itCursoInfo;
		advance(itCursoInfo, 1);
		string habil = *itCursoInfo;
		aux.insert(curso->getNomCurso() + "/  promedio del grado de avance: %" + to_string(promedio / cantidad)+" / "+Dificultad+" / "+Profesor+" / "+Idioma+"/"+habil);

	return aux;
}
set<string> Sistema::listarCursosNoAprobados(string nick) {

	set<string> aux;
	Usuario *usuarioSeleccionado = dynamic_cast<Usuario*>(this->usuarios->find(new String(nick)));

	Estudiante* EstudianteSeleccionado = dynamic_cast<Estudiante*>(usuarioSeleccionado);

	aux = EstudianteSeleccionado->getCursosNoAprobados();

	return aux;
}

set<string> Sistema::listarEjerciciosEstudiante(string nick, string curso){

	set<string> aux;
	set<string> aux2;
		Usuario *usuarioSeleccionado = dynamic_cast<Usuario*>(this->usuarios->find(new String(nick)));
		Estudiante *EstudianteSeleccionado = static_cast<Estudiante*>(usuarioSeleccionado);
		Curso *cursoSeleccionado = dynamic_cast<Curso*>(this->cursos->find(new String(curso)));

		aux2 = EstudianteSeleccionado->listarEjerciciosAprobados();
		aux = cursoSeleccionado->listarEjercicios();

		set<string>::iterator it;
		set<string>::iterator it2;
		set<string> ejercicios;
		set<string> devolver;

			for (it = aux.begin(); it != aux.end(); it++) {

					string eje1 = *it;

				for (it2 = aux2.begin(); it2 != aux2.end(); it2++) {

						string eje2 = *it2;
						if(eje1 != eje2){
							devolver.insert(eje1);
						}
				}

			}


		return devolver;

}

list<string> Sistema::mostrarEjercicio(string nick, string curso,string ejercicio) {

	IDictionary *lecciones;
	list<string> aux;


	Curso *cursoSeleccionado = dynamic_cast<Curso*>(this->cursos->find(new String(curso)));
	lecciones = dynamic_cast<IDictionary*>(cursoSeleccionado->getLecciones());

	for (IIterator *it = lecciones->getIterator(); it->hasCurrent();it->next()) {


		if(dynamic_cast<Leccion*>(it->getCurrent())->getEjercicios()->find(new String(ejercicio))){

			Ejercicio* eje = dynamic_cast <Ejercicio*>(dynamic_cast<Leccion*>(it->getCurrent())->getEjercicios()->find(new String(ejercicio)));
			aux = eje->getInfo();
		}



	}

	return aux;

}




string Sistema::getSolucion(string curso, string ejercicio) {

	IDictionary *lecciones;
	string aux;


	Curso *cursoSeleccionado = dynamic_cast<Curso*>(this->cursos->find(new String(curso)));
	lecciones = dynamic_cast<IDictionary*>(cursoSeleccionado->getLecciones());

	for (IIterator *it = lecciones->getIterator(); it->hasCurrent();it->next()) {


		if(dynamic_cast<Leccion*>(it->getCurrent())->getEjercicios()->find(new String(ejercicio))){

			Ejercicio* eje = dynamic_cast <Ejercicio*>(dynamic_cast<Leccion*>(it->getCurrent())->getEjercicios()->find(new String(ejercicio)));
			aux = eje->getSolucion();
		}



	}

	return aux;

}

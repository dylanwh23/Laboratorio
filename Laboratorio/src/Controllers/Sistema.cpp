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
	}
	return Sistema::miSistema;

}

void Sistema::inicializarDatos() {
	//inicializo los idiomas del sistema

	cout << "Inicializando datos de prueba" << endl;
	this->cursos = new OrderedDictionary();
		this->idiomas = new OrderedDictionary();
		this->usuarios = new OrderedDictionary();


		Idioma *i1 = new Idioma("Ingles");
		Idioma *i2 = new Idioma("Aleman");
		Idioma *i3 = new Idioma("Portugues");
		this->idiomas->add(new String(i1->getNomIdioma()), i1);
		this->idiomas->add(new String(i2->getNomIdioma()), i2);
		this->idiomas->add(new String(i3->getNomIdioma()), i3);

		Usuario *u1 = new Estudiante("jpidiom", "asdfg123", "Juan Perez", "Soy un apasionado del aprendizaje de idiomas.", "Argentina");
		Usuario *u2 = new Estudiante("marsilva", "qwer456", "Maria Silva", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", "Ecuador");
		Usuario *u3 = new Estudiante("pero12", "789werty", "Pedro Rodriguez", "Soy un entusiasta del aprendizaje de idiomas.", "Peru");
		Usuario *u4 = new Estudiante("laugu", "c1v2b3m4", "Laura Gutierrez", "Estoy fascinada por la forma en que las palabras pueden unir a las personas.", "Chile");
		Usuario *u5 = new Estudiante("carlo22", "tyuipz147", "Carlos Lopez", "Emocionado por adquirir fluidez en diferentes lenguas.", "Uruguay");
		Usuario *u6 = new Estudiante("anator", "1qsxc36", "Ana Torres", "Disfruto de la belleza de las diferentes estructuras y sonidos.", "Argentina");
		Usuario *u7 = new Estudiante("luher24", "t7h8y5u6", "Lucia Hernandez", "Emocionada en la riqueza cultural que cada idioma ofrece.", "Colombia");
		Usuario *u8 = new Estudiante("dagon", "1w2e3r4t5", "David Gonzalez", "Aprender nuevas lenguas y sumergirme en diferentes culturas.", "Uruguay");
		Usuario *u9 = new Estudiante("carmor", "6yu7i8m9", "Carmen Morales", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", "Chile");
		Usuario *u10 = new Estudiante("jose24", "qwj789p", "Jose Fernandez", "Disfruto del proceso de descubrir nuevas formas de comunicarme.", "Bolivia");

		Usuario *u11 = new Profesor("langMaster", "P4s512", "Marta Grecia", "Soy una profesora apasionada por los idiomas.", "Instituto de Idiomas Moderno ");
		Usuario *u12 = new Profesor("linguaPro", "Pess23", "Carlos Petro", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas.", "Centro Global");
		Usuario *u13 = new Profesor("talkExpert", "Secret1", "Laura Perez", "Soy una profesora entusiasta del aprendizaje de idiomas.", "Instituto de Idiomas Vanguardia");
		Usuario *u14 = new Profesor("lingoSensei", "Secure2", "Franco Lopez", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomáticos.", "Centro de Idiomas ");
		Usuario *u15 = new Profesor("wordMaestro", "Passw0", "Ana Morales", "Soy una profesora comprometida en desarrollo de habilidades idiomáticas.", "Instituto de Idiomas Progreso");
		dynamic_cast<Profesor*>(u11)->idiomas->add(new String(i1->getNomIdioma()), i1);
		dynamic_cast<Profesor*>(u11)->idiomas->add(new String(i2->getNomIdioma()), i2);
		dynamic_cast<Profesor*>(u12)->idiomas->add(new String(i1->getNomIdioma()), i1);
		dynamic_cast<Profesor*>(u12)->idiomas->add(new String(i2->getNomIdioma()), i2);
		dynamic_cast<Profesor*>(u12)->idiomas->add(new String(i3->getNomIdioma()), i3);
		dynamic_cast<Profesor*>(u13)->idiomas->add(new String(i1->getNomIdioma()), i1);
		dynamic_cast<Profesor*>(u14)->idiomas->add(new String(i1->getNomIdioma()), i1);
		dynamic_cast<Profesor*>(u15)->idiomas->add(new String(i1->getNomIdioma()), i1);

		this->usuarios->add(new String("jpidiom"), u1);
		this->usuarios->add(new String("marsilva"), u2);
		this->usuarios->add(new String("pero12"), u3);
		this->usuarios->add(new String("laugu"), u4);
		this->usuarios->add(new String("carlo22"), u5);
		this->usuarios->add(new String("anator"), u6);
		this->usuarios->add(new String("luher24"), u7);
		this->usuarios->add(new String("dagon"), u8);
		this->usuarios->add(new String("carmor"), u9);
		this->usuarios->add(new String("jose24"), u10);
		this->usuarios->add(new String("langMaster"), u11);
		this->usuarios->add(new String("linguaPro"), u12);
		this->usuarios->add(new String("talkExpert"), u13);
		this->usuarios->add(new String("lingoSensei"), u14);
		this->usuarios->add(new String("wordMaestro"), u15);

		Curso *c1 = new Curso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", "Principiante", dynamic_cast<Profesor*>(u11), i1, true);
		Curso *c2 = new Curso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", "Principiante", dynamic_cast<Profesor*>(u11), i1, false);
		Curso *c3 = new Curso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", "Medio", dynamic_cast<Profesor*>(u12), i1, true);
		Curso *c4 = new Curso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", "Avanzado", dynamic_cast<Profesor*>(u12), i1, true);
		Curso *c5 = new Curso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", "Medio", dynamic_cast<Profesor*>(u12), i3, true);
		Curso *c6 = new Curso("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", "Avanzado", dynamic_cast<Profesor*>(u14), i3, false);

		this->cursos->add(new String(c1->getNomCurso()), c1);
		this->cursos->add(new String(c2->getNomCurso()), c2);
		this->cursos->add(new String(c3->getNomCurso()), c3);
		this->cursos->add(new String(c4->getNomCurso()), c4);
		this->cursos->add(new String(c5->getNomCurso()), c5);
		this->cursos->add(new String(c6->getNomCurso()), c6);



		IDictionary *previasc3 = new OrderedDictionary();
		previasc3->add(new String(c1->getNomCurso()), c1);
		c3->AgregarPreviaturas(previasc3);

		IDictionary *previasc4 = new OrderedDictionary();
		previasc4->add(new String(c1->getNomCurso()), c1);
		previasc4->add(new String(c3->getNomCurso()), c3);
		c3->AgregarPreviaturas(previasc4);

		IDictionary *previasc6 = new OrderedDictionary();
		previasc6->add(new String(c5->getNomCurso()), c5);
		c3->AgregarPreviaturas(previasc6);


		EjercicioTraduccion *e1 = new EjercicioTraduccion("Presentaciones", "Presentaciones", "Nice to meet you", "Mucho gusto en conocerte");
		EjercicioCompletar *e2 = new EjercicioCompletar("Presentaciones formales", "Presentaciones formales", "Please - me to introduce -", "Please let me to introduce myself");
		EjercicioTraduccion *e3 = new EjercicioTraduccion("Plurales regulares", "Plurales regulares", "I have two brothers and three sisters", "Tengo dos hermanos y tres hermanas");
		EjercicioCompletar *e4 = new EjercicioCompletar("Sustantivos contables en plural", "Sustantivos contables en plural", "Can I have — water, please?", "Can I have some water, please?");
		EjercicioCompletar *e5 = new EjercicioCompletar("Actividades diarias", "Actividades diarias", "Wake -", "Wake up");
		EjercicioCompletar *e6 = new EjercicioCompletar("Consultas de la hora", "Consultas de la hora", "Q: Do you — the time?, A: Yes, it is half — 4", "Do you have the time?, A: Yes, it is half past 4");
		EjercicioTraduccion *e7 = new EjercicioTraduccion("Dar consejos o expresar obligacion", "Dar consejos o expresar obligacion", "You should visit that museum", "Deberías visitar ese museo");
		EjercicioTraduccion *e8 = new EjercicioTraduccion("Imperativo", "Imperativo", "Fale comigo", "Habla conmigo");

		IDictionary *ejerciciosLec1 = new OrderedDictionary();
		ejerciciosLec1->add(new String(e1->getNom()), e1);
		ejerciciosLec1->add(new String(e2->getNom()), e2);

		IDictionary *ejerciciosLec2 = new OrderedDictionary();
		ejerciciosLec2->add(new String(e3->getNom()), e3);
		ejerciciosLec2->add(new String(e4->getNom()), e4);

		IDictionary *ejerciciosLec3 = new OrderedDictionary();
		ejerciciosLec3->add(new String(e5->getNom()), e5);

		IDictionary *ejerciciosLec4 = new OrderedDictionary();
		//vacio

		IDictionary *ejerciciosLec5 = new OrderedDictionary();
		ejerciciosLec5->add(new String(e6->getNom()), e6);

		IDictionary *ejerciciosLec6 = new OrderedDictionary();
		ejerciciosLec6->add(new String(e7->getNom()), e7);

		IDictionary *ejerciciosLec7 = new OrderedDictionary();
		ejerciciosLec7->add(new String(e8->getNom()), e8);


		Leccion *l1 = new Leccion("Saludos y Presentaciones", "Aprender a saludar y despedirse", ejerciciosLec1);
		Leccion *l2 = new Leccion("Artículos y Plurales", "Comprender y utilizar los artículos definidos e indefinidos, aprender a formar los plurales regulares e irregulares de sustantivos", ejerciciosLec2);
		Leccion *l3 = new Leccion("Actividades Cotidianas", "Comprender y utilizar los artículos definidos e indefinidos, aprender a formar los plurales regulares e irregulares de sustantivos", ejerciciosLec3);
		Leccion *l4 = new Leccion("Presente Simple", "Aprender el uso del presente simple", ejerciciosLec4);
		Leccion *l5 = new Leccion("Conversaciones cotidianas", "Aprender a hacer preguntas y respuestas en situaciones comunes", ejerciciosLec5);
		Leccion *l6 = new Leccion("Uso de modales avanzados", "Explorar el uso de los modales complejos", ejerciciosLec6);
		Leccion *l7 = new Leccion("Lectura y comprensión de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas", ejerciciosLec7);


		c1->agregarLeccion(l1);
		c1->agregarLeccion(l2);
		c2->agregarLeccion(l3);
		c2->agregarLeccion(l4);
		c3->agregarLeccion(l5);
		c4->agregarLeccion(l6);
		c5->agregarLeccion(l7);

		IDictionary *ejAprobIn1 = new OrderedDictionary();
		ejAprobIn1->add(new String(e1->getNom()), e1);
		ejAprobIn1->add(new String(e2->getNom()), e2);
		ejAprobIn1->add(new String(e3->getNom()), e3);
		ejAprobIn1->add(new String(e4->getNom()), e4);

		IDictionary *ejAprobIn2 = new OrderedDictionary();
		ejAprobIn2->add(new String(e6->getNom()), e6);


		IDictionary *ejAprobIn4 = new OrderedDictionary();
		ejAprobIn4->add(new String(e1->getNom()), e1);
		ejAprobIn4->add(new String(e2->getNom()), e2);


		IDictionary *ejAprobIn5 = new OrderedDictionary();
		ejAprobIn5->add(new String(e1->getNom()), e1);
		ejAprobIn5->add(new String(e2->getNom()), e2);
		ejAprobIn5->add(new String(e4->getNom()), e4);


		Incripcion *in1 = new Incripcion(c1, ejAprobIn1);
		Incripcion *in2 = new Incripcion(c3, ejAprobIn2);
		Incripcion *in3 = new Incripcion(c4, new OrderedDictionary);
		Incripcion *in4 = new Incripcion(c1, ejAprobIn4);
		Incripcion *in5 = new Incripcion(c1, ejAprobIn5);
		Incripcion *in6 = new Incripcion(c1, new OrderedDictionary);
		Incripcion *in7 = new Incripcion(c5, new OrderedDictionary);
		Incripcion *in8 = new Incripcion(c5, new OrderedDictionary);

		list<Incripcion> inU1;
		inU1.push_back(*in1);
		inU1.push_back(*in2);
		inU1.push_back(*in3);

		list<Incripcion> inU2;
		inU2.push_back(*in4);


		list<Incripcion> inU3;
		inU3.push_back(*in5);


		list<Incripcion> inU4;
		inU4.push_back(*in5);
		inU4.push_back(*in6);

		list<Incripcion> inU5;
		inU5.push_back(*in8);


		dynamic_cast<Estudiante*>(u1)->inscripciones=inU1;
		dynamic_cast<Estudiante*>(u2)->inscripciones=inU2;
		dynamic_cast<Estudiante*>(u3)->inscripciones=inU3;
		dynamic_cast<Estudiante*>(u4)->inscripciones=inU4;
		dynamic_cast<Estudiante*>(u5)->inscripciones=inU5;






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

	if(auxit->isEmpty() == false){

		for (IIterator *it = auxit->getIterator(); it->hasCurrent(); it->next()) {

			aux.insert(static_cast<Idioma*>(it->getCurrent())->getNomIdioma());

			}

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
						float tamanioEjerciciosHechos = auxEst->ejerciciosHechosInscripciones(auxcur);
						float porcentajeCambio =(((tamanioEjerciciosHechos)/tamanioEjercicios)*100);
						promedio = promedio+porcentajeCambio;
						//aux.insert(auxcur->getNomCurso()+" " + auxEst->getNomUsuario()+" "+to_string(porcentajeCambio));

					}
				}

			}
			if(promedio != 0 ){
				promedio = promedio/cantidad;
			}

			aux.insert(auxcur->getNomCurso()+"  promedio del grado de avance %"+to_string(promedio));

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

					if(aux2.find(eje1) == aux2.end()){
						devolver.insert(eje1);
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

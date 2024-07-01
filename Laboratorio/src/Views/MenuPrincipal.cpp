/*
 * MenuPrincipal.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: dylan
 */

#include "MenuPrincipal.h"
#include <iostream>
#include "AltaUsuario.h"
#include "AltaIdioma.h"
#include "AltaCurso.h"
#include "AgregarLeccion.h"
#include "ConsultaUsuario.h"
#include "AgregarEjercicio.h"
#include "HabilitarCurso.h"
#include "ConsultaCurso.h"
#include "ConsultarEstadisticas.h"
#include "IncribirseACurso.h"
#include "borrarCurso.h"
#include "RealizarEjercicio.h"
#include "ConsultaIdioma.h"
using namespace std;
MenuPrincipal::MenuPrincipal() {
	// TODO Auto-generated constructor stub

}

MenuPrincipal::~MenuPrincipal() {
	// TODO Auto-generated destructor stub
}
void MenuPrincipal::mostrarMenu() {
	int op = 0;
	do {
		cout << endl << "*** Menu principal ***" << endl;
				cout << "1) Alta Usuario" << endl;
				cout << "2) Alta Idioma" << endl;
				cout << "3) Alta Curso" << endl;
				cout << "4) Consulta de usuario" << endl;
				cout << "5) Consultar idiomas "<< endl;
				cout << "6) Agregar Lecciones" << endl;
				cout << "7) Agregar Ejercicio" << endl;
				cout << "8) Habilitar curso" << endl;
				cout << "9) Eliminar curso" << endl;
				cout << "10) Consultar curso" << endl;
				cout << "11) Inscribirse a curso" << endl;
				cout << "12) Realizar ejercicio" << endl;
				cout << "13) Consultar estadísticas" << endl;
				cout << "14) Cargar datos de prueba " << endl;
				cout << "15) Salir " << endl;
				cout << "Ingrese una opcion: " << endl;
		cin >> op;
		switch (op) {
		case 1: {
			AltaUsuario altaUsuario;
			altaUsuario.altaUsuario();
		}
			break;
		case 2: {
			AltaIdioma altaIdioma;
			altaIdioma.ingresarIdioma();
		}
			break;
		case 3: {
			AltaCurso altaCurso;
			altaCurso.altaCurso();
		}
			break;
		case 4: {
			ConsultaUsuario consultarusuario;
			consultarusuario.consultaUsuario();
		}
			break;
		case 5: {
			ConsultaIdioma consultaidioma;
			consultaidioma.consultaIdioma();
		}
			break;
		case 6: {
				AgregarLeccion agregarleccion;
			agregarleccion.llamarAgregarLeccion();
		}
			break;
		case 7: {
				AgregarEjercicio agregarejercicio;
				agregarejercicio.llamarAgregarEjercicio();
		}

			break;
		case 8: {
			HabilitarCurso habilitarcurso;
			habilitarcurso.listarCursosInhabilitados();
		}
			break;
		case 9: {
			BorrarCurso borrarcurso;
			borrarcurso.borrarCurso();
		}
			break;
		case 10: {
			ConsultaCurso consultarcurso;
			consultarcurso.consultaCurso();
		}
			break;
		case 11: {
			IncribirseACurso incirbirseacurso;
			incirbirseacurso.incribirseACurso();
		}
			break;
		case 12: {
			RealizarEjercicio realizarejercicio;
			realizarejercicio.buscarEstudiante();
		}
			break;
		case 13: {
			ConsultarEstadisticas consultarestadisticas;
			consultarestadisticas.consultarEstadisticas();
		}
			break;
		case 14:{
			ConsultaIdioma cargardatos;
			cargardatos.inicializarDatos();
		}
			break;
		case 15:
					break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 15);

	cout << "Fin del programa" << endl;
}

#ifndef CONTROLLERS_USUARIOCONTROLLER_H_
#define CONTROLLERS_USUARIOCONTROLLER_H_
#include "Sistema.h"
#include "IUsuario.h"
#include "../ICollections/interfaces/IIterator.h"

class UsuarioController : public IUsuario{
private:
	Sistema* sistema;
public:

	UsuarioController();
	virtual ~UsuarioController();

	set<string> listarIdiomas();
	set<string> listarUsuarios();
	bool verificarNickname(string nickname);
	void altaProfesor(DTOProfesor* dto);
	void altaEstudiante(DTOEstudiante* dto);
	bool verificarIdioma(string nombreIdioma);

};

#endif /* CONTROLLERS_USUARIOCONTROLLER_H_ */

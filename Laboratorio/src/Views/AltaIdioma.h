#ifndef VIEWSALTAIDIOMA_H
#define VIEWSALTAIDIOMA_H
#include "../Controllers/IIdioma.h"
class AltaIdioma {
private:
	IIdioma* iidioma;
public:
    AltaIdioma();
    virtual ~AltaIdioma();
    void ingresarIdioma();
};

#endif /* VIEWSALTAIDIOMA_H */

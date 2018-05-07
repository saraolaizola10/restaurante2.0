#ifndef _CAMARERO_H
#define _CAMARERO_H

#include "Persona.h"

class Camarero: public Persona
{

	public:
	Camarero(const char *nombre, const char *apellido, int tel, int dni);
	Camarero(const Camarero &c);
	virtual ~Camarero();
};

#endif

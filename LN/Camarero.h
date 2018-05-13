#ifndef _CAMARERO_H
#define _CAMARERO_H

#include "Persona.h"

#include <iostream>
using namespace std;

class Camarero: public Persona
{
private:
	char* nombre;
	char* apellido;
	int tel;
	int dni;

public:
	Camarero(const char* nombre, const char* apellido, int tel, int dni);
	Camarero(const Camarero &c);
	virtual ~Camarero();
};

#endif

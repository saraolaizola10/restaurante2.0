#ifndef _CAMARERO_H
#define _CAMARERO_H

#include "Persona.h"

#include <iostream>
using namespace std;

class Camarero: public Persona
{
	private:
		string nombre;
		string apellido;
		int tel;
		int dni;
		float salario;

	public:
		Camarero(const string nombre, const string apellido, int dni, int tel, float salario);
		virtual void diPuesto();
};

#endif
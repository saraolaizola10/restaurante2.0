#ifndef _ADMINISTRADOR_H
#define _ADMINISTRADOR_H

#include "Persona.h"
#include <iostream>
using namespace std;

class Administrador: public Persona
{
	private:
		string nombre;
		string apellido;
		int tel;
		int dni;
		string cargo;

	public:
		Administrador(const string nombre, const string apellido, int dni, int tel, const string cargo);
		string getCargo() const;
		virtual void diPuesto();
		virtual float getSalario();
};

ostream &operator<<(ostream &os, const Administrador &a);

#endif
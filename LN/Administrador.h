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
		float sueldo;

	public:
		Administrador(const string nombre, const string apellido, int dni, int tel, const string cargo, float sueldo);
		string getCargo() const;
		virtual float getSueldo() ;
		virtual void diPuesto();
		
};

ostream &operator<<(ostream &os, const Administrador &a);

#endif
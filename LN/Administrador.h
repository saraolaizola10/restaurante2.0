#ifndef _ADMINISTRADOR_H
#define _ADMINISTRADOR_H

#include "Persona.h"
#include <iostream>
using namespace std;

class Administrador: public Persona
{
	
		string cargo;

	public:
		Administrador(const string nombre, const string apellido, int dni, int tel, const string cargo, float sueldo);
		Administrador(){};
		string getCargo() const;
		void setCargo(string cargo);

		virtual void bienvenido(Persona *p);
		virtual void diPuesto();
		
		friend istream& operator>> (istream& in, const Administrador &a);
};

ostream &operator<<(ostream &os, const Administrador &a);

#endif
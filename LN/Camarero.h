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
		float sueldo;
		string turno;
		

	public:
		Camarero(const string nombre, const string apellido, int dni, int tel, const string turno,float sueldo);
		string getTurno() const;
		virtual float getSueldo();
		virtual void diPuesto();
};

ostream &operator<<(ostream &os, const Camarero &c);

#endif
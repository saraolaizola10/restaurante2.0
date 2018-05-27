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
		string turno;

	public:
		Camarero(const string nombre, const string apellido, int dni, int tel, const string turno);
		string getTurno() const;
		virtual void diPuesto();
		virtual float getSalario();
};

ostream &operator<<(ostream &os, const Camarero &c);

#endif
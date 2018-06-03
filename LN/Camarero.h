#ifndef _CAMARERO_H
#define _CAMARERO_H

#include "Persona.h"
#include <iostream>
using namespace std;

class Camarero: public Persona
{
		string turno;
		

	public:
		Camarero(){};
		Camarero(const string nombre, const string apellido, int dni, int tel, const string turno,float sueldo);
		
		string getTurno() const;
		void setTurno(string turno);

		virtual void bienvenido();
		virtual void diPuesto();
		virtual int tieneAcceso(string lugar);

		friend istream& operator>> (istream& in, Camarero &c);
};

ostream &operator<<(ostream &os, const Camarero &c);

#endif
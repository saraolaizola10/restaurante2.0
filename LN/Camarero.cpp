#include "Camarero.h"
#include <iostream>
#include <string.h>
using namespace std;

Camarero::Camarero(const string nombre, const string apellido, int dni, int tel, const string turno): Persona(nombre, apellido, dni, tel)
{
	this->turno = turno;
}

string Camarero::getTurno() const
{
	return this->turno;
}

ostream &operator<<(ostream &os, const Camarero &c) 
{ 
     os << c.getNombre() << " " << c.getApellido() << ", dni: " << c.getDni() << ", tel: "<< c.getTel() << ". Turno de "<< c.getTurno();
     return os;
}

void Camarero::diPuesto()
{
	cout << "CAMARERO";
}

float Camarero::getSalario()
{
	return 500;
}
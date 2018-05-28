#include "Camarero.h"
#include <iostream>
#include <string.h>
using namespace std;

Camarero::Camarero(const string nombre, const string apellido, int dni, int tel, const string turno, float sueldo): Persona(nombre, apellido, dni, tel,sueldo)
{
	this->sueldo=sueldo;
	this->turno = turno;
}

string Camarero::getTurno() const
{
	return this->turno;
}

float Camarero::getSueldo() 
{
	return this->sueldo;
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
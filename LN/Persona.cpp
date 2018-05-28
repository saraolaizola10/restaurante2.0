#include "Persona.h"
#include <string.h>

#include <iostream>
using namespace std;

Persona::Persona(const string nombre, const string apellido, int dni, int tel, float sueldo)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this-> dni = dni;
	this->tel = tel;
	this->sueldo = sueldo;	
}

string Persona::getNombre() const
{
	return this->nombre;
}

string Persona::getApellido() const
{
	return this->apellido;
}

int Persona::getTel() const
{
	return this->tel;
}

int Persona::getDni() const
{
	return this->dni;
}

float Persona::getSueldo() 
{
	return this->sueldo;
}

ostream &operator<<(ostream &os, const Persona &p) 
{ 
    os << p.getNombre() << " " << p.getApellido() << ", dni: " << p.getDni() << ". Tel: "<< p.getTel();
    return os;
}
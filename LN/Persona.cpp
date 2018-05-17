#include "Persona.h"
#include <string.h>

#include <iostream>
using namespace std;

Persona::Persona(const string nombre, const string apellido, int dni, int tel): nombre(nombre), apellido(apellido), dni(dni), tel(tel){}

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
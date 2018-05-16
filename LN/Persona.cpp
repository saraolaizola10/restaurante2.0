#include "Persona.h"
#include <string.h>

#include <iostream>
using namespace std;

Persona::Persona(const string nombre, const string apellido, int dni, int tel)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->tel = tel;
	this->dni = dni;
}

/*Persona::Persona(const Persona &p)
{
	this->nombre = p.nombre;
	this->apellido = p.apellido;
	this->tel = p.tel;
	this->dni = p.dni;
}*/

Persona::~Persona()
{

}

void Persona::diPuesto()
{
	cout << "Empleado" << endl;
}

const string Persona::getNombre()
{
	return this->nombre;
}

const string Persona::getApellido()
{
	return this->apellido;
}

int Persona::getTel()
{
	return this->tel;
}

int Persona::getDni()
{
	return this->dni;
}
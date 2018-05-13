#include "Persona.h"
#include <string.h>

#include <iostream>
using namespace std;

Persona::Persona(const string nombre, const string apellido, int tel, int dni)
{
//	this->nombre = new char[strlen(nombre) + 1];
//	strcpy(this->nombre, nombre);
//	this ->apellido = new char[strlen(apellido)+1];
//	strcpy(this->apellido, apellido);
	this->nombre = nombre;
	this->apellido = apellido;
	this->tel = tel;
	this->dni = dni;

}

Persona::Persona(const Persona& p)
{
//	this->nombre = new char[strlen(p.nombre) + 1];
//	strcpy(this->nombre, p.nombre);
	this->nombre = p.nombre;
}

Persona::~Persona()
{
//	delete[] this->nombre;
//	delete[] this->apellido;
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


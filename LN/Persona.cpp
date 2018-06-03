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

float Persona::getSueldo() const
{
	return this->sueldo;
}

void Persona::setNombre(string nombre)
{
	this->nombre=nombre;
}
void Persona::setApellido(string apellido)
{
	this->apellido=apellido;
}
void Persona::setTel(int tel)
{
	this->tel=tel;
}
void Persona::setDni(int dni)
{
	this->dni=dni;
}
void Persona::setSueldo(float sueldo)
{
	this->sueldo=sueldo;
}

ostream &operator<<(ostream &os, const Persona &p) 
{ 
    os << p.getNombre() << " " << p.getApellido() << ", dni: " << p.getDni() << ". Tel: "<< p.getTel();
    return os;
}


void Persona::bienvenido()
{
	cout<<"Bienvenido/a"<<endl;
}
#include "Administrador.h"
#include <iostream>
#include <string.h>

using namespace std;

Administrador::Administrador(const string nombre, const string apellido, int dni, int tel, const string cargo, float sueldo): Persona(nombre, apellido, dni, tel,sueldo)
{
	this->sueldo = sueldo;
	this-> cargo = cargo;
}

string Administrador::getCargo() const
{
	return this->cargo;
}

float Administrador::getSueldo() 
{
	return this->sueldo;
}

ostream &operator<<(ostream &os, const Administrador &a) 
{ 
     os << "Nombre:" << a.getNombre() << " " << a.getApellido() << ", dni: " << a.getDni() << ". Tel: "<< a.getTel();
     return os;
}

void Administrador::diPuesto()
{
	cout << "ADMINISTRADOR";
}
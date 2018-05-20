#include "Categoria.h"
#include <string.h>

#include <iostream>
using namespace std;

Categoria:: Categoria(int id, const string nombre, int orden): id(id), nombre(nombre), orden(orden)
{
	this->id = id;
	this->nombre = nombre;
	this->orden = orden;
}

int Categoria::getId()  const
{
	return this->id;
}
string Categoria::getNombre() const
{
	return this->nombre;
}
int Categoria::getOrden() const
{
	return this->orden;
}

ostream &operator<<(ostream &os, const Categoria &c) 
{ 
     os << c.getOrden() << " " << c.getNombre();
     return os;
}
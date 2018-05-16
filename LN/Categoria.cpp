#include "Categoria.h"
#include <string.h>

#include <iostream>
using namespace std;

Categoria:: Categoria(int id, const string nombre, int orden): id(id), nombre(nombre), orden(orden){}

Categoria::Categoria(const Categoria &c)
{
	this->id = c.id;
	this->nombre = c.nombre;
	this->orden = c.orden;
}
Categoria:: ~Categoria()
{
	
}

int Categoria::getId()
{
	return this->id;
}
string Categoria::getNombre()
{
	return this->nombre;
}
int Categoria::getOrden()
{
	return this->orden;
}

void Categoria::setId(const int id)
{
	this->id=id;
}
void Categoria::setNombre(const string nom)
{
	this->nombre=nom;
}
void Categoria::setOrden(const int orden)
{
	this->orden=orden;
}
#include "Producto.h"
#include <string.h>

#include <iostream>
using namespace std;

Producto:: Producto(int id, string nombre, float precio, string categoria): id(id), nombre(nombre), precio(precio), categoria(categoria) {}

Producto:: Producto(const Producto &p)
{
	this->id = p.id;
	this->nombre = p.nombre;
	this->precio = p.precio;
	this->categoria = p.categoria;
}
Producto:: ~Producto()
{
	
}

int Producto::getId()
{
	return this->id;
}
string Producto::getNombre()
{
	return this->nombre;
}
float Producto::getPrecio()
{
	return this->precio;
}
string Producto::getCategoria()
{
	return this->categoria;
}

void Producto::setId(const int id)
{
	this->id=id;
}
void Producto::setNombre(const string nom)
{
	this->nombre=nom;
}
void Producto::setPrecio(const float precio)
{
	this->precio=precio;
}
void Producto::setCategoria(const string cat)
{
	this->categoria=cat;
}
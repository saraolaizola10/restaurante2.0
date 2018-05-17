#include "Producto.h"
#include <string.h>

#include <iostream>
using namespace std;

Producto:: Producto(int id, string nombre, float precio, string categoria): id(id), nombre(nombre), precio(precio), categoria(categoria) {}

Producto:: ~Producto()
{
	
}

int Producto::getId() const
{
	return this->id;
}
string Producto::getNombre() const
{
	return this->nombre;
}
float Producto::getPrecio() const
{
	return this->precio;
}
string Producto::getCategoria() const
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
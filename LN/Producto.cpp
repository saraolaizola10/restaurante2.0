#include "Producto.h"
#include <string.h>

#include <iostream>
using namespace std;

Producto:: Producto(int id, string nombre, float precio, string categoria): id(id), nombre(nombre), precio(precio), categoria(categoria) 
{
	this->id=id;
	this->nombre=nombre;
	this->precio=precio;
	this->categoria=categoria;
}

ostream& operator<<(ostream &os, const Producto &p) 
{ 
    os << p.getNombre() << ", " << p.getPrecio() << char(156) << " de la categoria: "<< p.getCategoria();
    return os;
}
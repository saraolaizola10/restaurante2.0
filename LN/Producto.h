#ifndef _PRODUCTO_H
#define _PRODUCTO_H

#include <iostream>
using namespace std;

class Producto
{
private:
	int id;
	string nombre;
	float precio; 
	string categoria;

public:
	Producto(int id, string nombre, float precio, string categoria);

	int getId() const {return id;}
	string getNombre() const {return nombre;}
	float getPrecio() const {return precio;}
	string getCategoria() const {return categoria;}
};

ostream& operator<<(ostream &os, const Producto &p);

#endif
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
	Producto(const Producto &p);
	virtual ~Producto();

	int getId();
	string getNombre();
	float getPrecio();
	string getCategoria();

	void setId(const int id);
	void setNombre(const string nom);
	void setPrecio(const float precio);		
	void setCategoria(const string cat);
	


};

#endif
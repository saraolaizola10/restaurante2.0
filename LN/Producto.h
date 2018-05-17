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
	virtual ~Producto();

	int getId() const;
	string getNombre() const;
	float getPrecio() const;
	string getCategoria() const;

	void setId(const int id);
	void setNombre(const string nom);
	void setPrecio(const float precio);		
	void setCategoria(const string cat);
	
	friend ostream &operator<<(ostream &os, const Producto &p);

};

ostream &operator<<(ostream &os, const Producto &p) 
{ 
     os << "ID:" << p.id << ", " << p.nombre << " -> : " << p.precio << "€, de la categoria: "<< p.categoria << endl;
     return os;
}

#endif
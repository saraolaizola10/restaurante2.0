#ifndef _CATEGORIA_H
#define _CATEGORIA_H

#include <iostream>
using namespace std;

class Categoria
{
private:
	int id;
	string nombre;
	int orden;

public:
	Categoria(int id, const string nombre, int orden);
	virtual ~Categoria();

	int getId() const;
	string getNombre() const;
	int getOrden() const;

	void setId(const int id);
	void setNombre(const string nom);
	void setOrden(const int orden);

	friend ostream &operator<<(ostream &os, const Categoria &c);
};

ostream &operator<<(ostream &os, const Categoria &c) 
{ 
     os << "ID:" << c.id << " " << c.nombre << ", Orden: " << c.orden << endl;
     return os;
}

#endif
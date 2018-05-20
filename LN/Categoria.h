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

	int getId() const;
	string getNombre() const;
	int getOrden() const;
};

ostream &operator<<(ostream &os, const Categoria &c);

#endif
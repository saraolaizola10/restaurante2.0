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
	Categoria(const Categoria &c);
	virtual ~Categoria();
};

#endif
#include "Camarero.h"
#include <iostream>
#include <string.h>
using namespace std;

Camarero::Camarero(const string nombre, const string apellido, int dni, int tel, float salario): Persona(nombre, apellido, dni, tel)
{
	this-> salario = 100;
}

float Camarero::getSalario() const
{
	return this->salario;
}

ostream &operator<<(ostream &os, const Camarero &c) 
{ 
     os << c.getNombre() << " " << c.getApellido() << ", dni: " << c.getDni() << ", tel: "<< c.getTel() << ". Salario: "<< c.getSalario() << char(156);
     return os;
}
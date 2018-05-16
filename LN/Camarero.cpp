#include "Camarero.h"
#include <iostream>
using namespace std;

Camarero::Camarero(const string nombre, const string apellido, int dni, int tel,float salario): Persona(nombre, apellido, dni, tel)
{
	this-> salario = salario;
}

void Camarero::diPuesto()
{
	cout << "Camarero" << endl;
}

#include "Camarero.h"
#include <iostream>
using namespace std;

Camarero::Camarero(const string nombre, const string apellido, int tel, int dni,float salario): Persona(nombre, apellido, tel, dni)
{
	this-> salario = salario;
}

void Camarero::diPuesto()
{
	cout << "Camarero" << endl;
}

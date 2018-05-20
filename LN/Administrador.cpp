#include "Administrador.h"
#include <iostream>
#include <string.h>
using namespace std;

Administrador::Administrador(const string nombre, const string apellido, int dni, int tel/*, float salario*/): Persona(nombre, apellido, dni, tel)
{
	//this-> salario = 100;
}

//string Administrador::getNombre() const
//{
//	return this->nombre;
//}
//string Administrador::getApellido() const
//{
//	return this->apellido;
//}
//int Administrador::getDni() const
//{
//	return this->dni;
//}
//int Administrador::getTel() const
//{
//	return this->tel;
//}
//float Administrador::getSalario() const
//{
//	return this->salario;
//}

ostream &operator<<(ostream &os, const Administrador &a) 
{ 
     os << "Nombre:" << a.getNombre() << " " << a.getApellido() << ", dni: " << a.getDni() << ". Tel: "<< a.getTel();
     return os;
}
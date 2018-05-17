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

//void Administrador::setNombre(const string nom)
//{
//	this->nombre=nom;
//}
//void Administrador::setApellido(const string ape)
//{
//	this->apellido=ape;
//}
//void Administrador::setDni(int dni)
//{
//	this->dni=dni;
//}
//void Administrador::setTel(int tel)
//{
//	this->tel=tel;
//}
//void Administrador::setSalario(float salario)
//{
//	this->salario=salario;
//}
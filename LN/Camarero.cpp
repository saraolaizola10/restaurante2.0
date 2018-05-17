#include "Camarero.h"
#include <iostream>
#include <string.h>
using namespace std;

Camarero::Camarero(const string nombre, const string apellido, int dni, int tel, float salario): Persona(nombre, apellido, dni, tel)
{
	this-> salario = 100;
}

//string Camarero::getNombre()
//{
//	return this->nombre;
//}
//string Camarero::getApellido()
//{
//	return this->apellido;
//}
//int Camarero::getDni()
//{
//	return this->dni;
//}
//int Camarero::getTel()
//{
//	return this->tel;
//}
float Camarero::getSalario() const
{
	return this->salario;
}

//void Camarero::setNombre(const string nom)
//{
//	this->nombre=nom;
//}
//void Camarero::setApellido(const string ape)
//{
//	this->apellido=ape;
//}
//void Camarero::setDni(int dni)
//{
//	this->dni=dni;
//}
//void Camarero::setTel(int tel)
//{
//	this->tel=tel;
//}
//void Camarero::setSalario(float salario)
//{
//	this->salario=salario;
//}
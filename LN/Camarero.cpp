#include "Camarero.h"
#include <iostream>
using namespace std;

Camarero::Camarero(const string nombre, const string apellido, int dni, int tel,float salario): Persona(nombre, apellido, dni, tel), salario(salario){}

/*Camarero::Camarero(const Camarero &c)
{
	this->nombre = c.nombre;
	this->apellido = c.apellido;
	this->dni = c.dni;
	this->tel = c.tel;
	this->salario = c.salario;
}*/

Camarero::~Camarero()
{

}

void Camarero::diPuesto()
{
	cout << "Camarero" << endl;
}

string Camarero::getNombre()
{
	return this->nombre;
}
string Camarero::getApellido()
{
	return this->apellido;
}
int Camarero::getDni()
{
	return this->dni;
}
int Camarero::getTel()
{
	return this->tel;
}
float Camarero::getSalario()
{
	return this->salario;
}
	
void Camarero::setNombre(const string nom)
{
	this->nombre=nom;
}
void Camarero::setApellido(const string ape)
{
	this->apellido=ape;
}
void Camarero::setDni(const int dni)
{
	this->dni=dni;
}
void Camarero::setTel(const int tel)
{
	this->tel=tel;
}
void Camarero::setSalario(const float salario)
{
	this->salario=salario;
}
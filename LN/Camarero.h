#ifndef _CAMARERO_H
#define _CAMARERO_H

#include "Persona.h"
#include <iostream>
using namespace std;

class Camarero: public Persona
{
	private:
		string nombre;
		string apellido;
		int tel;
		int dni;
		float salario;

	public:
		Camarero(const string nombre, const string apellido, int dni, int tel, float salario);

		//string getNombre();
		//string getApellido();
		//int getDni();
		//int getTel();
		float getSalario() const;

		//void setNombre(const string nom);
		//void setApellido(const string ape);
		//void setDni(int dni);
		//void setTel(int tel);
		//void setSalario(float salario);

		friend ostream &operator<<(ostream &os, const Camarero &c);
};

ostream &operator<<(ostream &os, const Camarero &c) 
{ 
     os << "Nombre:" << c.nombre << " " << c.apellido << ", dni: " << c.dni << ". Tel: "<< c.tel << ". Salario: "<< c.salario << "€" << endl;
     return os;
}

#endif
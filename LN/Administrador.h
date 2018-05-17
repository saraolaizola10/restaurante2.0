#ifndef _ADMINISTRADOR_H
#define _ADMINISTRADOR_H

#include "Persona.h"
#include <iostream>
using namespace std;

class Administrador: public Persona
{
	private:
		string nombre;
		string apellido;
		int tel;
		int dni;
		//float salario;

	public:
		Administrador(const string nombre, const string apellido, int dni, int tel/*, float salario*/);
		virtual ~Administrador();
		//string getNombre() const;
		//string getApellido() const;
		//int getDni() const;
		//int getTel() const;
		//float getSalario() const;

		//void setNombre(const string nom);
		//void setApellido(const string ape);
		//void setDni(int dni);
		//void setTel(int tel);
		//void setSalario(float salario);

		friend ostream &operator<<(ostream &os, const Administrador &a);
};

ostream &operator<<(ostream &os, const Administrador &a) 
{ 
     os << "Nombre:" << a.nombre << " " << a.apellido << ", dni: " << a.dni << ". Tel: "<< a.tel << endl;
     return os;
}

#endif
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
		float getSalario();

		//void setNombre(const string nom);
		//void setApellido(const string ape);
		//void setDni(int dni);
		//void setTel(int tel);
		//void setSalario(float salario);


};

#endif
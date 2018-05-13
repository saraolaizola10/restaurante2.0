#ifndef _PERSONA_H
#define _PERSONA_H

#include <iostream>
using namespace std;

class Persona
{
private:
	string nombre;
	string apellido;
	int tel;
	int dni;
	
public:
	Persona(const string nombre, const string apellido, int tel, int dni);
	Persona(const Persona &p);
	virtual ~Persona();

	const string getNombre();
	const string getApellido();
	int getTel();
	int getDni();

};

#endif
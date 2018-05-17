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
	Persona(const string nombre, const string apellido, int dni, int tel);

	friend std::ostream &operator<<(std::ostream &os, Persona const &p) 
	{ 
        return os << p.nombre << " " << p.apellido << " , dni: " << p.dni << " tel: "<< p.tel << endl;
    }

	const string getNombre();
	const string getApellido();
	int getTel();
	int getDni();
};

#endif
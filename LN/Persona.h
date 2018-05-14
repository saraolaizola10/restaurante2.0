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

	friend std::ostream &operator<<(std::ostream &os, Persona const &p) 
	{ 
        return os << p.nombre << " " << p.apellido << " , tel: " << p.tel << " dni: "<< p.dni << endl;
    }

    virtual void diPuesto();

	const string getNombre();
	const string getApellido();
	int getTel();
	int getDni();
};

#endif
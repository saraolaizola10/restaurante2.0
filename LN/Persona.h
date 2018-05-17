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

	string getNombre() const;
	string getApellido() const;
	int getTel() const;
	int getDni() const;

	//friend ostream &operator<<(ostream &os, const Persona &p);
};

//ostream &operator<<(ostream &os, const Persona &p) 
//{ 
//     os << "Nombre:" << p.nombre << " " << p.apellido << ", dni: " << p.dni << ". Tel: "<< p.tel << endl;
//     return os;
//}

#endif
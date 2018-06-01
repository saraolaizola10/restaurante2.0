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
	float sueldo;
	
public:
	Persona(const string nombre, const string apellido, int dni, int tel, float sueldo);
	Persona(){};
	string getNombre() const;
	string getApellido() const;
	int getTel() const;
	int getDni() const;

	void setNombre(string nombre);
	void setApellido(string apellido);
	void setTel(int tel);
	void setDni(int dni);
	void setSueldo(float sueldo);
	
	virtual void bienvenido(Persona *p);
	virtual float getSueldo();
	virtual void diPuesto()=0;

	
	
};

ostream &operator<<(ostream &os, const Persona &p);


#endif
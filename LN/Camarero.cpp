#include "Camarero.h"
#include "../LP/frAdministrador.h"
#include "../LP/frComun.h"
#include "../LP/frDatos.h"
#include "../COMUN/Utilidades.h"
#include "../LD/EscrituraBD.h"
#include "../LD/LecturaBD.h"
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

#define SUELDO 1000.00


Camarero::Camarero(const string nombre, const string apellido, int dni, int tel, const string turno, float sueldo): Persona(nombre, apellido, dni, tel,sueldo)
{
	this->turno = turno;
}

string Camarero::getTurno() const
{
	return this->turno;
}

void Camarero::setTurno(string turno)
{
	this->turno=turno;
}


ostream &operator<<(ostream &os, const Camarero &c) 
{ 
     os << c.getNombre() << " " << c.getApellido() << ", dni: " << c.getDni() << ", tel: "<< c.getTel() << ". Turno de "<< c.getTurno();
     return os;
}

istream& operator>> (istream& in, Camarero &c)
{
	string  nombre, apellido,turno;
	int dni,tel,unica,t;
	float sueldo;

	cout << "\n\n ** ALTA CAMARERO **" << endl;

	cin.ignore();
	cout << "Nombre: " << endl;
	getline(cin, nombre);
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(),::toupper);
	
	cout << "Apellido: " << endl;
	getline(cin, apellido);
	cin.clear();
	transform(apellido.begin(), apellido.end(), apellido.begin(),::toupper);
	
	cout << "DNI (sin letra): " << endl;
	do
	{
		dni = pedirNumero(8);
		//unica = nuevoCamarero(db,dni);
		if (unica!=0)
		{
			cout << "Error. DNI ya existente. "<<endl;
		}
	} while (unica!=0);

	cout << "Telefono:" <<endl;
	tel = pedirNumero(9);

	cout << "Turno de \n 1. MEDIODIA \n 2. NOCHE \n 3. COMPLETO" << endl;
	t = introducirOpcion(3);
	switch (t)
	{
		case 1:		turno="MEDIODIA";
					break;

		case 2:		turno="NOCHE";
					break;

		case 3:		turno="COMPLETO";
					break;
	}

	if (t==3)
		sueldo = SUELDO;
	else
		sueldo = SUELDO/2;
		
	c.setNombre(nombre);
	c.setApellido(apellido);
	c.setDni(dni);
	c.setTel(tel);
	c.setTurno(turno);
	c.setSueldo(sueldo);
	return in;
}

void Camarero::diPuesto()
{
	cout << "CAMARERO";
}

void Camarero::bienvenido(Persona *p)
{
	cout<<"Bienvenido camarero, "<<p->getNombre()<<endl;
}
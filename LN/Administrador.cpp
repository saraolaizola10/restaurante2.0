#include "Administrador.h"
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

Administrador::Administrador(const string nombre, const string apellido, int dni, int tel, const string cargo, float sueldo): Persona(nombre, apellido, dni, tel,sueldo)
{
	this-> cargo = cargo;
}

string Administrador::getCargo() const
{
	return this->cargo;
}

void Administrador::setCargo(string cargo)
{
	this->cargo=cargo;
}

ostream &operator<<(ostream &os, const Administrador &a) 
{ 
     os << a.getNombre() << " " << a.getApellido() << ", "<< a.getCargo() << ". Sueldo: "<<a.getSueldo() << char(36)<<". Tel: "<< a.getTel();
     return os;
}

istream& operator>> (istream& in, Administrador &a)
{
	string nombre, apellido,cargo;
	int dni,tel,unica,t;
	float sueldo;

	cout << "\n\n ** ALTA ADMINISTRADOR **" << endl;

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
	
	dni = pedirNumero(8);
		
	cout << "Telefono:" <<endl;
	tel = pedirNumero(9);

	cin.ignore();
	cout << "Cargo \n 1. DIRECTOR \n 2. RRHH \n 3. COMERCIAL" << endl;
	t = introducirOpcion(3);
	switch (t)
	{
		case 1:		cargo="DIRECTOR";
					break;

		case 2:		cargo="RRHH";
					break;

		case 3:		cargo="COMERCIAL";
					break;
	}

	cout << "Sueldo:" << endl;
	sueldo=pedirFloat();
	
	a.setNombre(nombre);
	a.setApellido(apellido);
	a.setDni(dni);
	a.setTel(tel);
	a.setCargo(cargo);
	a.setSueldo(sueldo);	

	return in;
}

void Administrador::diPuesto()
{
	cout << this->getCargo();
}

void Administrador::bienvenido()
{
	cout<< "BIENVENIDO "<<this->getCargo()<< " " <<this->getNombre() << endl;
}

int Administrador::tieneAcceso(string area)
{
	if (this->getCargo()=="DIRECTOR")
		return 1;

	if ((this->getCargo()=="RRHH")&&(area=="PLANTILLA"))
		return 1;

	if ((this->getCargo()=="COMERCIAL")&&(area=="OFERTA"))
		return 1;

	else if(area=="ADMINISTRACION")
		return 1;

	else
		return 0;
}
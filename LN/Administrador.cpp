#include "Administrador.h"
#include <iostream>
#include <string.h>

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
     os << "Nombre:" << a.getNombre() << " " << a.getApellido() << ", dni: " << a.getDni() << ". Tel: "<< a.getTel();
     return os;
}

istream& operator>> (istream& in, const Administrador &a)
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
	do
	{
		dni = pedirNumero(8);
		//unica = nuevoCamarero(db,dni);
		if (unica!=0)
		{
			//FALLAAAAA
			cout << "Error. DNI ya existente. "<<endl;
		}
	} while (unica!=0);

	cout << "Telefono:" <<endl;
	tel = pedirNumero(9);

	cin.ignore();
	cout << "Cargo:" << endl;
	getline(cin, cargo);
	cin.clear();
	transform(cargo.begin(), cargo.end(), cargo.begin(),::toupper);

	cout << "Sueldo:" << endl;
	sueldo=pedirFloat();
	
	a.setNombre(nombre);
	a.setApellido(apellido);
	a.setDni(dni);
	a.setTel(tel);
	a.setCargo(cargo);
	a.setSueldo(sueldo);	

	altaAdministrador(db,dni,nombre,apellido,tel,cargo,sueldo);
}

void Administrador::diPuesto()
{
	cout << "ADMINISTRADOR";
}

void Administrador::bienvenido(Persona *p)
{
	cout<< "Bienvenido administrador, "<<p->getNombre()<<endl;
}
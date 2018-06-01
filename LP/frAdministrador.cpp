#include "frAdministrador.h"
#include "frComun.h"
#include "frDatos.h"
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

int comprobarClave()
{
	string line, clave;
	ifstream myfile("clave.txt");
	
	cout << "Introducir clave administrador:" << endl;
	cin >> clave;
	cin.clear();

	while (getline(myfile,line))
	{
		if (line==clave)
		{
			myfile.close();
			return 0;

		}
		else
		{
			myfile.close();
			cout << "Error, la clave no conicide" << endl;
			return -1;
		}
	}
}

void cambiarClave()
{
	ofstream myfile("clave.txt");
	int clave;

	cout << "Introducir nueva clave: \n" << endl;
	cin >> clave;
	cin.clear();

	myfile << clave;
	myfile.close();
}

int pedirDNIa(sqlite3 *db)
{
	int dni;

	list <Administrador> administradores = getAdministradores(db);

	cout << " Introduzca su DNI:" << endl;
	cin >> dni;
	cin.clear();

	for (auto a: administradores)
	{
		if (a.getDni() == dni)
		{
			return dni;
		}
	}
	cout << " Error. No coincide con ningun DNI" << endl;
	return 0;
}

void AltaCamarero(sqlite3 *db)
{
	string nombre, apellido,turno;
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
		unica = nuevoCamarero(db,dni);
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
		
	altaCamarero(db,dni,nombre,apellido,tel,turno,sueldo);
}

void AltaAdministrador(sqlite3 *db)
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
		unica = nuevoCamarero(db,dni);
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
		
	altaAdministrador(db,dni,nombre,apellido,tel,cargo,sueldo);
}

void AltaCategoria(sqlite3 *db)
{
	int orden,total,id;
	string nombre;

	total = totalCategorias(db);
	id = ultimoIDCategoria(db)+1;

	cout << "\n\n ** ALTA CATEGORIA **" << endl;

	cin.ignore();
	cout << "Nombre:" << endl;
	getline(cin, nombre);
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	if (total!=0)
	{
		do 
		{
			mostrarCategorias(db);
			cout << "Orden de la nueva categoria (1-" << total+1 << "):" << endl;
			cin >> orden;
			cin.clear();
			if ((orden<0)||(orden>(total+1)))
			{
				cout << "Error. No hay tantas categorias" << endl;
			}
		} while ((orden<0)||(orden>(total+1)));
		
		if(orden>total)
		{
			altaCategoria (db,id,nombre,orden);
		}
		else
		{
			Categoria newCat (id,nombre,orden);
			ordenarCategorias (db,newCat);
		}
	}
	else
		altaCategoria (db,id,nombre,1);
}

void AltaProducto(sqlite3 *db)
{
	string nombre,categoria;
	float precio;
	int id,catnum,totalCat;

	cout << "\n\n ** ALTA PRODUCTO **" << endl;

	cin.ignore();
	id = ultimoIDProducto(db)+1;

	cout << "Nombre:" << endl;
	getline(cin, nombre);
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	cout << "Precio:" <<endl;
	precio = pedirFloat();

	//FALTA: confirmar que esta dentro del total
	cout << "Introduce el numero de la categoria deseada:" << endl;
	mostrarCategorias(db);
	totalCat = totalCategorias(db);
	catnum = introducirOpcion(totalCat);
	cin.clear();
	categoria = getNombreCategoria(db,catnum);

	altaProducto (db,id,nombre,categoria,precio);
}

void EditarProducto(sqlite3 *db)
{
	int totalP, num, id, catnum;
	string nombre, categoria;
	float precio;

	mostrarProductos(db);
	totalP = totalProductos(db);
	num = introducirOpcion(totalP)-1;

	cin.ignore();
	cout << "Nombre:" << endl;
	getline(cin, nombre);
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	cout << "Precio:" <<endl;
	precio = pedirFloat();
	
	cout << "Introduce el numero de la categoria deseada:" << endl;
	mostrarCategorias(db);
	cin >> catnum;
	//nombre categoria correspondiente al orden
	//categoria = cat

	//BD: editar producto
}

void EliminarProducto(sqlite3 *db)
{
	int num;
	int totalP;

	mostrarProductos(db);
	totalP = totalProductos(db);
	num = introducirOpcion(totalP)-1;

	//BD: eliminar producto
}
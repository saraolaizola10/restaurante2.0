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
	
	cout <<"Introducir clave administrador:" << endl;
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
	int id,num,totalP;
	string nombre;
	float precio;

	cout << "Introduzca el numero del producto deseado:\n" << endl;
	mostrarProductos(db);
	totalP = totalProductos(db);
	num = introducirOpcion(totalP);
	id = getIdProducto(db,num-1);

	cin.ignore();
	cout << "Nombre:" << endl;
	getline(cin, nombre);
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	cout << "Precio:" <<endl;
	precio = pedirFloat();
	
	updateProducto(db,id,nombre,precio);
}

void EditarAdministrador(sqlite3 *db)
{
	int dni,tel,totalA,num;
	string cargo;
	float sueldo;

	cout << "Introduzca el numero del administrador deseado:\n" << endl;
	mostrarAdministradores(db);
	totalA = totalAdministradores(db);
	num = introducirOpcion(totalA);
	dni = getAdministrador(db,num-1);

	cin.ignore();
	cout << "Cargo \n 1. DIRECTOR \n 2. RRHH \n 3. COMERCIAL" << endl;
	int t = introducirOpcion(3);
	switch (t)
	{
		case 1:		cargo="DIRECTOR";
					break;

		case 2:		cargo="RRHH";
					break;

		case 3:		cargo="COMERCIAL";
					break;
	}
	
	cout << "Sueldo:" <<endl;
	sueldo = pedirFloat();

	cout << "Telefono:" <<endl;
	tel = pedirNumero(9);

	updateAdministrador(db,dni,tel,cargo,sueldo);
}

void EliminarProducto(sqlite3 *db)
{
	int id,totalP,num;

	cout << "Introduzca el numero del producto a eliminar:\n" << endl;
	mostrarProductos(db);
	totalP = totalProductos(db);
	num = introducirOpcion(totalP);
	id = getIdProducto(db,num-1);
	deleteProducto(db, id);
}

void EliminarCamarero(sqlite3 *db)
{
	int dni,num,totalC;

	cout << "Introduzca el numero del camarero deseado:\n" << endl;
	mostrarCamareros(db);
	totalC = totalCamareros(db);
	num = introducirOpcion(totalC);
	dni = getCamarero(db,num-1);
	deleteCamarero(db, dni);
}
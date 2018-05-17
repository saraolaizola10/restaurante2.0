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
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

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
			return 0;
		}
		else
		{
			cout << "Error, la clave no conicide" << endl;
			return -1;
		}
	}
	myfile.close();
}

void cambiarClave()
{
	ofstream myfile("clave.txt");
	int clave;

	cout << "Introducir nueva clave: \n" << endl;
	cin >> clave;
	cin.clear();

	//NO ENTRAA
	myfile << clave;
	myfile.close();
}

void AltaCamarero(sqlite3 *db)
{
	string nombre, apellido;
	int dni,tel,unica;
	float sueldo;

	cout << "Nombre: " << endl;
	cin >> nombre;
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(),::toupper);
	
	cout << "Apellido: " << endl;
	cin >> apellido;
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

	altaCamarero(db,dni,nombre,apellido,tel);
}

void AltaCategoria()
{
	int orden;
	int total;
	string nombre;

	total = totalCategorias(db);
	//id = ultimo id bd +1

	cout << "Nombre:" << endl;
	cin >> nombre;
	cin.clear();
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
		
		if ((orden<total)||(orden==total))
		{
			//OrdenarCategorias(categorias,orden,total);
			//en la base de datos
		}
	}
	else
		orden = 1;

	altaCategoria (db,id,nombre,orden);
}

void AltaProducto(sqlite3 *db)
{
	string nombre,categoria;
	float precio;
	int id,catnum;

	//BD: id = GET ultimo id + 1

	cout << "Nombre:" << endl;
	cin >> nombre;
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	cout << "Precio:" <<endl;
	precio = pedirFloat();

	cout << "Introduce el numero de la categoria deseada:" << endl;
	mostrarCategorias(db);
	cin >> catnum;
	cin.clear();
	//nombre categoria correspondiente al orden
	//categoria = cat

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

	cout << "Nombre:" << endl;
	cin >> nombre;
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

void EliminarProducto()
{
	int num;
	int totalP;

	mostrarProductos(db);
	totalP = totalProductos(db);
	num = introducirOpcion(totalP)-1;

	//BD: eliminar producto
}
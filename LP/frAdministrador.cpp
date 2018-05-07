#include "frAdministrador.h"
#include "../COMUN/Utilidades.h"
#include "../LN/Persona.h"
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int introducirOpcion(int opciones)
{
	int n;
	
	cout << "Introduzca opcion (1-" << opciones << "): " << endl;
	do
	{
		n = pedirNumero(0);

		if ((n<0)||(n>opciones))
		{
			cout << "Error. Introducir valor valido\n" << endl;
		}
	} while ((n<0)||(n>opciones));
	return n;
}

int comprobarClave()
{
	string line, clave;
	ifstream myfile("clave.txt");
	
	cout << "Introducir clave administrador:" << endl;
	cin >> clave;
	cin.clear();

	//NO ENTRAA
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

void AltaCamarero()
{
	string nombre, apellido;
	int dni,tel,unica;
	float sueldo;

	cout << "Nombre: " << endl;
	cin >> nombre;
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);
	
	cout << "Apellido: " << endl;
	cin >> apellido;
	cin.clear();
	transform(apellido.begin(), apellido.end(), apellido.begin(), ::toupper);
	
	cout << "DNI (sin letra): " << endl;
	//do
	//{
		dni = pedirNumero(8);

		// BD: COMPROBAR EN BASE DE DATOS SI EL DNI ES UNICO (0 UNICA, 1 EXISTE)
		//if (unica!=0)
		//{
		//	<< cout << "Error. DNI ya existente. "<<endl;
		//}
	//} while (unica!=0);

	cout << "Telefono:" <<endl;
	tel = pedirNumero(9);

	//BD: GUARDAR EN BASE DE DATOS
}

void AltaCategoria()
{
	int total,orden;
	string nombre;

	//total = las categorias que tenemos
	//id = ultimo id bd +1

	cout << "Nombre:" << endl;
	cin >> nombre;
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	if (total!=0)
	{
		do 
		{
			//MostrarCategorias;
			cout << "Orden de la nueva categoria (1-" << total+1 << "):" << endl;
			cin >> orden;
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
	{
		orden = 1;
	}
}

void AltaProducto()
{
	string nombre,categoria;
	float precio;
	int id,catnum;

	//id = el ultimo BD + 1

	cout << "Nombre:" << endl;
	cin >> nombre;
	cin.clear();
	transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	cout << "Precio:" <<endl;
	precio = pedirFloat();

	cout << "Introduce el numero de la categoria deseada:" << endl;
	//MostrarCategorias;
	cin >> catnum;
	//nombre categoria correspondiente al orden
	//categoria = cat

	//BD: GUARDAR EN BASE DE DATOS
}

void EditarProducto()
{
	
}
#include "frDatos.h"
#include "../COMUN/Utilidades.h"
#include "../LN/Persona.h"
#include "../LN/Camarero.h"
#include "../LN/Comanda.h"
#include "../LN/Cuenta.h"
#include "../LN/Producto.h"
#include "../LN/Categoria.h"
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

int totalCamareros (sqlite3 *db)
{
	list <Camarero> camareros = getCamareros(db);
	int total = camareros.size();
	return total;
}

//0 si es nuevo, sino ya existe
int nuevoCamarero (sqlite3 *db, int dni)
{
	int nuevo=0;
	list <Camarero> camareros = getCamareros(db);
	
	for (auto c: camareros)
	{
		if (dni == c.getDni())
		{
			nuevo++;
		}
	}
	return nuevo;
}

void mostrarCamareros(sqlite3 *db)
{
	list <Camarero> camareros = getCamareros(db);

	for (auto c: camareros)
	{
		cout << c << endl;
	}
}

int MesaOcupada(int *cuentas[],int mesa,int nueva)
{
	if (cuentas[mesa][0]==0)		//!cuentas[mesa][0]) //saber que esta vacio sin que deje de funcionar
	{
		if (nueva==0)
		{
			cout << "Error. Mesa vacia" << endl;
		}
		return 0;
	}
	else
	{
		if (nueva==1)
		{
			cout << "Error. Mesa ocupada" << endl;
		}
		return 1;
	}
}

int MostrarProductosxCategoria (sqlite3 *db,string categoria)
{
	int num = 1;
	
	list <Producto> productos;

	linea();
	cout << "    ** categoria **   \n" << endl;
	for (auto p: productos)
	{
		if (categoria == p.getCategoria())
		{
			cout << num << ". " << p.getNombre() << endl;
			num++;
		}
	}	
	cout << num << ". Pasar a siguiente categoria\n" << endl;
	return (num-1);
}

int getProducto(sqlite3 *db,string categoria, int opcion)
{
	char str [50];
	char *nombre;
	int num=1;
	int id;

	list <Producto> productos; //BD: get productos

	for (auto p: productos)
	{
		if (categoria == p.getCategoria())
		{
			if (num==opcion)
			{
				id = p.getId();
			}
			num++;
		}
	}	
	return id;
}

void ImprimirCuenta (sqlite3 *db,int **cuentas, int mesa)
{
	int posicion,id,cantidad;
	float total;
    list <Producto> productos; //BD: get productos

   	linea();
	cout << "\n ** RESTAURANTE MISAJO 2.0 ** " << endl;
	cout << "    Cuenta de la mesa "<< mesa+1 << endl;
   //Utilidades: imprimir fecha
	linea();
	
	posicion=cuentas[mesa][0];
	for(int i=1; i<posicion+1; i++)
    {
    	id=cuentas[mesa][i];
    	cantidad=cuentas[mesa][i+1];
    	i++;
    	for (auto p: productos)
    	{
    		if(id==p.getId())
    		{
    			cout << " - " << p.getNombre() << " (x" << cantidad << ") " << p.getPrecio()*cantidad << char(36) << endl;
    		}
    	}	
    }
    total = totalCuenta(cuentas,mesa);
    linea();
    cout << "     TOTAL = "<< total << char(36) << endl; 
   	linea();
}


float totalCuenta(sqlite3 *db,int **cuentas, int mesa)
{
	float total=0;
	int posicion = cuentas[mesa][0];
	int id,cantidad;

	list <Producto> productos; //BD: get productos

    for(int i=1; i<posicion+1; i++)
    {
    	id = cuentas[mesa][i];
    	cantidad = cuentas[mesa][i+1];

    	for (auto p: productos)
    	{
    		if (id==p.getId())
    		{
    			total += p.getPrecio() * cantidad;
    		}
    	}
    	i++;
    }
    return total;
}
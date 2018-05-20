#include "frCamarero.h"
#include "frComun.h"
#include "frDatos.h"
#include "../COMUN/Utilidades.h"
#include "../LD/sqlite3.h"
#include "../LD/LecturaBD.h"
#include "../LD/EscrituraBD.h"
#include "../LN/Camarero.h"
#include "../LN/Producto.h"
#include "../LN/Comanda.h"
#include "../LN/Categoria.h"
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;

int pedirDNI(sqlite3 *db)
{
	int dni;

	list <Camarero> camareros = getCamareros(db);

	cout << " Introduzca su DNI:" << endl;
	cin >> dni;
	cin.clear();

	for (auto c: camareros)
	{
		cout << c.getDni();
		if (c.getDni() == dni)
		{
			return dni;
		}
	}
	cout << " Error. No coincide con ningun DNI" << endl;
	return 0;
}

int getNumeroMesa(int MESAS)
{
	int mesa,n;
	cout << "Introducir el numero de la mesa (1-" << MESAS << "):" << endl;
	do
	{
		mesa = pedirNumero(0);
		if ((mesa<0)||(mesa>MESAS))
		{
			cout << "Error. Introducir un valor valido" << endl;
		}
	} while ((mesa<0)||(mesa>MESAS));
	mesa = mesa-1; 
	return mesa;
}

void AtenderMesa(sqlite3 *db,int *cuentas[],int mesa)
{
	int opcion,id,totalPxCat,cantidad;
	char str [4];

	list <Producto> productos = getProductos(db);
	list <Categoria> categorias = getCategorias(db);

	int posicion = (cuentas[mesa][0]);

	for (auto c: categorias)
	{
		do
		{
			totalPxCat = MostrarProductosxCategoria(db,c.getNombre());

			opcion = introducirOpcion(totalPxCat+1);
			cin.clear();
			
			if ((totalPxCat+1)!=opcion)
			{
				id = getProducto(db,c.getNombre(),opcion);
				posicion++;
				cuentas[mesa][posicion]=id; 	
				posicion++;
				cout << " Cantidad: " << endl;
				cantidad = pedirNumero(0);
				cuentas[mesa][posicion]=cantidad;	
			}
		} while ((totalPxCat+1)!=opcion);
	}
	cuentas[mesa][0]=posicion;
}

void AltaComanda(sqlite3 *db,int dni,int **cuentas, int mesa)
{
	float total=0;
    float nota;

    int fechayhora = getHora();
    cin.ignore();
    cout << "Nota media del servicio (1-10):"<< endl;
    do
    {   
        nota = pedirFloat();
        if ((nota<0)||(nota>10))
        {
            cout << "Error. Introducir valor valido" << endl;
        }
    } while ((nota<0)||(nota>10));
    
   	total = totalCuenta(db,cuentas,mesa);


    altaComanda (db,dni,fechayhora,total,nota); 
}
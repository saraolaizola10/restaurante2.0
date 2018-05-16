#include "frCamarero.h"
#include "frComun.h"
#include "../COMUN/Utilidades.h"
#include "../LD/sqlite3.h"
#include "../LD/LecturaBD.h"
#include "../LN/Camarero.h"
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

	for (auto c: camareros)
	{
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
		mesa = pedirNumero();
		if ((mesa<0)||(mesa>MESAS))
		{
			cout << "Error. Introducir un valor valido" << endl;
		}
	} while ((mesa<0)||(mesa>MESAS));
	mesa = mesa-1; 
	return mesa;
}

void AtenderMesa(int *cuentas[],int mesa)
{
	int opcion,id,totalPxCat,cantidad;
	char str [4];

	list <Producto> productos; //BD: get productos
	list <Categoria> categorias; //BD: get categorias

	int posicion = (cuentas[mesa][0]);

	for (auto c: categorias)
	{
		do
		{
			totalPxCat = MostrarProductosxCategoria(c.getNombre());
			opcion = introducirOpcion(totalPxCat+1);
			
			if ((totalPxCat+1)!=opcion)
			{
				id = getProducto(c.getNombre(),opcion);
				posicion++;
				cuentas[mesa][posicion]=id; 	
				posicion++;
				cout << " Cantidad: " << endl;
				cantidad = pedirNumero();
				cuentas[mesa][posicion]=cantidad;	
			}
		} while ((totalPxCat+1)!=opcion);
	}
	cuentas[mesa][0]=posicion;
}

void AltaComanda(int dni)
{
	time_t now;
	float total=0;
    float nota;

    now = time(0);
    fechayhora=(int)now;

    cout << "Nota media del servicio (1-10):"<< endl;
    do
    {   
        nota = pedirFloat();
        if ((nota<0)||(nota>10))
        {
            cout << "Error. Introducir valor valido" << endl;
        }
    } while ((nota<0)||(nota>10));
    
   	//total = calcular total de la cuenta  total = totalCuenta(cuentas,mesa,p,totalP);
    //BD: dar de alta la comanda
}
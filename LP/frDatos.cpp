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
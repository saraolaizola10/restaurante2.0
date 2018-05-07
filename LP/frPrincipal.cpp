#include "frPrincipal.h"
#include "utilidades.h"
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
		n = pedirNumero();
		if ((n<0)||(n>opciones))
		{
			cout << "Error. Introducir valor valido\n" << endl;
		}
	} while ((n<0)||(n>opciones));
	
	return n;
}

int comprobarClave()
{
	FILE *f;
	int clave;
	char str [10];

	cout << "\n Introducir clave administrador: \n" << endl;
	fgets(str,10,stdin);
	sscanf(str,"%d",&clave);
	clear_if_needed(str);

	f = fopen("clave.txt","r");

	if (!f)
	{
		cout << "No se ha podido abrir el fichero\n" << endl;
	}
	else
	{
		int d;
		char str [10];
		while (fgets(str,10,f))	//mientras me devuelva algo
		{
			sscanf(str,"%d",&d);
			if(d!=clave)
			{
				cout << "Error, la clave no coincide" << endl;
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}

void cambiarClave()
{
	FILE* f;
	int clave;
	char str [10];

	cout << "Introducir nueva clave: \n" << endl;
	fgets(str,10,stdin);
	sscanf(str,"%d",&clave);
	clear_if_needed(str);

	if (!f)
	{
		cout << "No se ha podido abrir el fichero\n" << endl;
	}
	else
	{
		f = fopen("clave.txt","w");

		fprintf(f,"%d", clave);

		fclose(f);
	}
}
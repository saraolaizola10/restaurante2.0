#include "Persona.h"
#include "Camarero.h"
#include "utilidades.h"
#include "Pantalla.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define PARAM "admin"

int main (int argc, char *argv[])
{
	int dni,n,m,mesa,c;

	cout << "Bienvenido al Restaurante" << endl;
	
	if (((argc < 2)||strcmp(argv[1],PARAM)!=0))
	{
		//pedir dni 
		//if (dni!=0)
		//{
			do
			{
				cout << "\n 1. Nueva comanda" << endl;
				cout <<"\n 2. A" << char(164) << "adir a comanda" << endl;
				cout <<"\n 3. Imprimir cuenta" << endl;
				cout <<"\n 4. Salir" << endl;

				n=introducirOpcion(4);

				switch (n)
				{
					case 1:
					break;

					case 2:
					break;

					case 3:
					break;
				}
			} while (n!=4);
		//}
	}
	else
	{
		c = comprobarClave();
				
		if (c==0)
		{
			do
			{
				cout << "\n 1. Consultar estad "<< char(161) << "sticas" << endl;
				cout <<"\n 2. A"<< char(164) << "adir camarero" << endl;
				cout <<"\n 3. A"<< char(164) << "adir categoria" << endl;
				cout <<"\n 4. A"<< char(164) << "adir producto"<< endl;
				cout <<"\n 5. Editar producto"<< endl;
				cout <<"\n 6. Eliminar producto"<< endl;
				cout <<"\n 7. Cambiar clave"<< endl;
				cout <<"\n 8. Salir"<< endl;
			
				n=introducirOpcion(8);
				switch (n)
				{
					case 1:
					do
					{
						cout <<"\n 1. Lista de los camareros"<< endl;
						cout <<"\n 2. Nota media camareros"<< endl;
						cout <<"\n 3. Actividad camareros"<< endl;
						cout <<"\n 4. Precio medio gastado por mesa"<< endl;
						cout <<"\n 5. Media del servicio del restaurante"<< endl;
						cout <<"\n 6. Ingresos por mes"<< endl;
						cout <<"\n 7. Media de precios por categoria"<< endl;
						cout <<"\n 8. Salir"<< endl;
						m = introducirOpcion(8);
						switch(m)
						{
							case 1:
							
							break;

							case 2:
							
							break;

							case 3:
							
							break;

							case 4:
							
							break;

							case 5:
							
							break;

							case 6:
							
							break;

							case 7:
							
							break;
						}
					}while(m!=8);
					break;

					case 2:
					
					break;

					case 3:
					
					break;

					case 4:	
					
					break;

					case 5:
					
					break;

					case 6:
					
					break;

					case 7:
					
					break;
				}
			} while (n!=8);
		}
	}	

	return 0;
}
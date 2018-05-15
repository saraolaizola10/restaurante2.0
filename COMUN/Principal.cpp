#include "Utilidades.h"
#include "../LN/Persona.h"
#include "../LN/Camarero.h"
#include "../LP/frAdministrador.h"
#include "../LP/frComun.h"
#include "../LP/frCamarero.h"
#include "../LD/EscrituraBD.h"
#include "../LD/LecturaBD.h"
#include "../LD/sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

#define PARAM "admin"

int main (int argc, char *argv[])
{
	int dni,n,m,mesa,c;

	sqlite3 *db;

	int result = sqlite3_open("BD.sqlite", &db);
	if (result != SQLITE_OK) 
	{
		cout << "Error opening database\n" << endl;
		return result;
	}
	else
	{
		cout << "Database Opened successfully\n" << endl;
  	}

	iniciarBD(db);

	//crearTablaCamarero();

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
		//c = comprobarClave();	//NO FUNCIONA
		//if (c==0)	
		{
			do
			{
				cout << "\n 1. Consultar estad"<< char(161) << "sticas" << endl;
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
					AltaCamarero(db);
					break;

					case 3:
					AltaCategoria();
					break;

					case 4:	
					AltaProducto();
					break;

					case 5:
					EditarProducto();
					break;

					case 6:
					EliminarProducto();
					break;

					case 7:
					cambiarClave();
					break;
				}

			} while (n!=8);
		}
	}	

	//result = sqlite3_close(db);
	//if (result != SQLITE_OK) 
	//{
	//	printf("Error opening database\n");
	//	printf("%s\n", sqlite3_errmsg(db));
	//	return result;
	//}

	return 0;
}
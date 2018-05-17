#include "Utilidades.h"
#include "../LP/frAdministrador.h"
#include "../LP/frComun.h"
#include "../LP/frCamarero.h"
#include "../LP/frDatos.h"
#include "../LD/EscrituraBD.h"
#include "../LD/LecturaBD.h"
#include "../LD/sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

#define PARAM "admin"
#define MESAS 20
#define POSICIONES 50

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
	iniciarBD(db);//CREACION DE TABLAS BD

	int **cuentas;
	cuentas = (int **) malloc (MESAS * sizeof (int*));
	for (int i= 0; i<MESAS; i++)
	{
		cuentas[i] = (int*) malloc (POSICIONES *sizeof (int));
		cuentas[i][0] = 0; 
	}

	cout << "Bienvenido al Restaurante" << endl;
	
	if (((argc < 2)||strcmp(argv[1],PARAM)!=0))
	{
		dni = pedirDNI(db);
		if (dni!=0)
		{
			do
			{
				cout << "\n 1. Nueva comanda";
				cout <<"\n 2. A" << char(164) << "adir a comanda";
				cout <<"\n 3. Imprimir cuenta";
				cout <<"\n 4. Salir" << endl;

				n=introducirOpcion(4);

				switch (n)
				{
					case 1:
					mesa = getNumeroMesa(MESAS);
					if (MesaOcupada(cuentas,mesa,1)==0)
					{
						AtenderMesa(db,cuentas,mesa);
					}
					break;

					case 2:
					mesa = getNumeroMesa(MESAS);
					if (MesaOcupada(cuentas,mesa,0)==1)
					{
						AtenderMesa(db,cuentas,mesa);
					}
					break;

					case 3:
					mesa=getNumeroMesa(MESAS);
					if (MesaOcupada(cuentas,mesa,0)==1)
					{
						AltaComanda(db,dni,cuentas,mesa);
						ImprimirCuenta(db,cuentas,mesa);
						for (int i=0;i<POSICIONES;i++)
						{
							cuentas[mesa][i]=0;
						}
					}
					break;
				}
			} while (n!=4);
		}
	}
	else
	{
		c = comprobarClave();	//NO FUNCIONA
		if (c==0)	
		{
			do
			{
				cout << "\n 1. Consultar estad"<< char(161) << "sticas" ;
				cout <<"\n 2. A"<< char(164) << "adir camarero" ;
				cout <<"\n 3. A"<< char(164) << "adir categoria" ;
				cout <<"\n 4. A"<< char(164) << "adir producto";
				cout <<"\n 5. Editar producto";
				cout <<"\n 6. Eliminar producto";
				cout <<"\n 7. Cambiar clave";
				cout <<"\n 8. Salir"<< endl;
			
				n=introducirOpcion(8);
				switch (n)
				{
					case 1:
					do
					{
						cout <<"\n 1. Lista de los camareros";
						cout <<"\n 2. Nota media camareros";
						cout <<"\n 3. Actividad camareros";
						cout <<"\n 4. Precio medio gastado por mesa";
						cout <<"\n 5. Media del servicio del restaurante";
						cout <<"\n 6. Ingresos por mes";
						cout <<"\n 7. Media de precios por categoria";
						cout <<"\n 8. Salir"<< endl;
						m = introducirOpcion(8);
						switch(m)
						{
							case 1:
							mostrarCamareros(db);
							break;

							case 2:
							//Nota media por camarero
							break;

							case 3:
							//Actividad camareros
							break;

							case 4:
							//Precio medio por mesa
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
					AltaCategoria(db);
					break;

					case 4:	
					AltaProducto(db);
					break;

					case 5:
					EditarProducto(db);
					break;

					case 6:
					EliminarProducto(db);
					break;

					case 7:
					cambiarClave();
					break;
				}

			} while (n!=8);
		}
	}	

	sqlite3_close(db);

	return 0;
}
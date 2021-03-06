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
	int dni,n,m,x,mesa,c;

	sqlite3 *db;
	int result = sqlite3_open("BD.sqlite", &db);
	if (result != SQLITE_OK) 
	{
		cout << "Error al abrir la base de datos\n" << endl;
		return result;
	}
	iniciarBD(db);
	altaDirector(db);

	int **cuentas;
	cuentas = (int **) malloc (MESAS * sizeof (int*));
	for (int i= 0; i<MESAS; i++)
	{
		cuentas[i] = (int*) malloc (POSICIONES *sizeof (int));
		cuentas[i][0] = 0; 
	}

	linea();

	cout << "\n\n ** BIENVENIDO A MISAJO 2.0 ** \n" << endl;
	
	if (((argc < 2)||strcmp(argv[1],PARAM)!=0))
	{
		
		dni = pedirDNI(db);

		if (dni!=0)
		{
			Persona *p= getPersona(db,dni);
			if (p->tieneAcceso("SERVICIO"))
			{
				cout << "\n\n";
				p->bienvenido();
				do
				{
					cout << "\n   --    MENU    -- " << endl;
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
			else
			{
				accesoDenegado();
			}
		}
	}
	else
	{
	   	c = comprobarClave();
		if (c==0)	
		{
		  	dni = pedirDNI(db);
		  	
		  	if(dni==0)
		  	{
		  		return 1;
			}
			
			Persona *p= getPersona(db,dni);

			if (p->tieneAcceso("ADMINISTRACION")==0)
			{
				accesoDenegado();
				return 1;
			}	
			cout << "\n\n";
			p->bienvenido();
			
			do
			{
				cout << "\n   --    MENU    -- \n" << endl;
				cout << " 1. Consultar estad"<< char(161) << "sticas" << endl;
				cout << " 2. Gestionar plantilla" << endl;
				cout << " 3. Gestionar oferta" << endl;
				cout << " 4. Cambiar clave" << endl;
				cout << " 5. Salir" << endl;
				n=introducirOpcion(5);

				switch(n)
				{
					case 1:
					do 
					{
						cout << "\n\n  -- Estad"<<char(161)<<"sticas -- "<<endl;
						cout <<"\n 1. Ver plantilla";
						cout <<"\n 2. Nota media camareros";
						cout <<"\n 3. Actividad camareros";
						cout <<"\n 4. Precio medio gastado por mesa";
						cout <<"\n 5. Salarios de la plantilla";
						cout <<"\n 6. Ingresos por mes";
						cout <<"\n 7. Ingresos por dia";
						cout <<"\n 8. Actividad del dia";
						cout <<"\n 9. Media de precios por categoria";
						cout <<"\n 10. Atras"<< endl;
						m = introducirOpcion(10);
						switch(m)
						{
							case 1:
							mostrarPlantilla(db);
							break;

							case 2:
							mediaCamarero(db);
							break;

							case 3:
							actividadCamarero(db);
							break;

							case 4:
							valorMedioComandas(db);
							break;

							case 5:
							mostrarSalarios(db);
							break;

							case 6:
							importeXmes(db);
							break;

							case 7:
							importeXdias(db);
							break;

							case 8:
							comandasHoy(db);
							break;

							case 9:
							PrecioMedioProductosxCategoria(db);
							break;
						}
					}while(m!=10);
					break;
					
					case 2:
					if (p->tieneAcceso("PLANTILLA"))
					{
						do
						{
							cout << "\n\n   --    MENU    -- " << endl;
							cout <<"\n 1. A"<< char(164) << "adir nuevo empleado";
							cout <<"\n 2. Cambiar datos administrador";
							cout <<"\n 3. Dar de baja camarero";
							cout <<"\n 4. Atras" << endl;
							m=introducirOpcion(4);
							switch(m)
							{
								case 1:
								nuevoEmpleado(db);
								break;

								case 2:
								if (totalAdministradores(db)!=0)
									EditarAdministrador(db);
								else
									cout<<"Error. No hay administradores."<< endl;
								break;

								case 3:
								if (totalCamareros(db)!=0)
									EliminarCamarero(db);
								else
									cout<<"Error. No hay camareros."<< endl;
								break;
							}
						} while(m!=4);
					}
					else
						accesoDenegado();
					break;

					case 3:
					if (p->tieneAcceso("OFERTA"))
					{
						cout << endl;
						do
						{
							cout << "\n\n   --    MENU    -- " << endl;
							cout <<"\n 1. A"<< char(164) << "adir categoria";
							cout <<"\n 2. A"<< char(164) << "adir producto";
							cout <<"\n 3. Editar producto";
							cout <<"\n 4. Eliminar producto";
							cout <<"\n 5. Atras"<<endl;
							m=introducirOpcion(5);
							switch(m)
							{
								case 1:
								AltaCategoria(db);
								break;

								case 2:
								if (totalCategorias(db)!=0)
									AltaProducto(db);
								else
									cout << "Error. Debes a"<<char(164)<<"adir alguna categoria." << endl;
								break;

								case 3:
								if (totalProductos(db)!=0)
									EditarProducto(db);
								else
									cout<<"Error. No hay productos."<<endl;
								break;

								case 4:
								if (totalProductos(db)!=0)
									EliminarProducto(db);
								else
									cout<<"Error. No hay productos."<< endl;
								break;
							}
						} while (m!=5);
					}
					else
						accesoDenegado();
					break;

					case 4:
					if (p->tieneAcceso("CLAVES"))
						cambiarClave();
					else
						accesoDenegado();
				}
			} while (n!=5);
		}
	}	

	sqlite3_close(db);

	return 0;
}
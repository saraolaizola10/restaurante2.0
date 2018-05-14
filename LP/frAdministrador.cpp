#include "frAdministrador.h"
#include "../COMUN/Utilidades.h"
#include "../LN/Persona.h"
#include "../LN/Camarero.h"
#include "../LN/Comanda.h"
#include "../LN/Cuenta.h"
#include "../LN/Producto.h"
#include "../LN/Categoria.h"
#include "frComun.h"
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

int comprobarClave()
{
	string line, clave;
	ifstream myfile("clave.txt");
	
	cout << "Introducir clave administrador:" << endl;
	cin >> clave;
	cin.clear();

	//while (!myfile)
	//{
	//	in >> clave;
	//
	//	if (line==clave)
	//	{
	//		return 0;
	//	}
	//	else
	//	{
	//		cout << "Error, la clave no conicide" << endl;
	//		return -1;
	//	}
	//}
	//NO ENTRAA
	while (getline(myfile,line))
	{
		cout << "entro"<< endl;
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

	//BD: GUARDAR EN BASE DE DATOS
}

void AltaProducto()
{
	string nombre,categoria;
	float precio;
	int id,catnum;

	//BD: id = GET ultimo id + 1

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
	int totalP, num, id, catnum;
	string nombre, categoria;
	float precio;

	//BD: Mostrar productos
	//BD: get total productos
	num = introducirOpcion(totalP)-1;

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

	//BD: editar producto
}

void EliminarProducto()
{
	int num;
	int totalP;
	//BD: Mostrar productos
	//BD: get total productos
	num = introducirOpcion(totalP)-1;

	//BD: eliminar producto
}

// ESTADISTICAS

void listaPlantilla()
{
	list <Persona> personas;

	for (auto p: personas)
	{
		cout << p;
		p.diPuesto();
		cout << "\n" << endl;
	}
}

void mediaCamarero()
{
    int dni,cantidad;
    float total;

    list <Camarero> camareros;
    list <Comanda> comandas;
    //BD: get listas 

    linea();
    cout << "\n   ** NOTA MEDIA DE LOS CAMAREROS ** \n\n" << endl;

	for (auto c: camareros)
	{
        dni = c.getDni();
        cantidad=0;
        total=0,0;

		for (auto co: comandas) 
        {
            if(dni==co.getDni())
            {
                total += co.getMedia();   
                cantidad++;    
            }
        }
        total= total/cantidad;
        cout << c.getNombre() << " " << c.getApellido() << " " << total << endl;
	}
    linea();
}

void actividadCamarero ()
{
    int dni,cantidad;
    float total;

    list <Camarero> camareros;
    list <Comanda> comandas;

    //BD: inicializar y totales

    linea();
  	cout << "\n  ** ACTIVIDAD DE LOS CAMAREROS ** \n" << endl;
    cout << " (Camarero/Num.Comandas/Imp.Total)\n\n" << endl;

    for (auto c: camareros)
    {
        dni = c.getDni();
        cantidad=0;
        total=0,0;

        for (auto co: comandas) 
        {
            if(dni==co.getDni())
            {
                total += co.getTotal();   
                cantidad++;    
            }
        }
        cout << c.getNombre() << " " << c.getApellido() <<"   x"<< cantidad << " " << total << "char(36)" << endl;
    }
    linea();
}

void valorMedioComandas ()
{
    float total, precio;
 	
    list <Comanda> comandas;
    //BD: inicializar

    linea();
    cout << "\n  ** PRECIO MEDIO GASTADO POR MESA ** \n\n" << endl;
        
    total=0,0;

    for (auto c: comandas)
	{
		total += c.getTotal();
	}

    precio= total/comandas.size();

    cout << "\n  HAN GASTADO UNA MEDIA DE " << precio << " POR MESA \n" << endl;
    linea();
}

void mediaServicio ()
{
    float total, media;
    
    list <Comanda> comandas;
    //BD: inicializar

    linea();
    cout << "\n  ** MEDIA DEL SERVICIO DEL RESTAURANTE ** \n\n" << endl;
        
    total=0,0;

    for (auto c: comandas)
    {
        total+=c.getMedia();
        
    }
    media= total/comandas.size();

    cout << " La valoracion del servicio por parte de los \n cliente ha logrado un "<< media/10 <<" de media \n" << endl;
    linea();
}

void importeXmes ()
{
	//POR HACER
}

void PrecioMedioProductosxCategoria ()
{
    int cant;
    float med, precioTot;

    list <Producto> productos;
    list <Categoria> categorias;
    //BD: inicializar

    linea();
    cout << "\n   ** PRECIO MEDIO DE PRODUCTOS POR CATEGORIA ** \n\n" << endl;
    
    for (auto c: categorias)
    {
        med=0;
        cant=0;
        precioTot=0;

        for (auto p: productos)
        {
            if ( strcmp(c.getNombre(),p.getCategoria())==0)
            {
                precioTot += p.getPrecio();
                cant++;
            }
        }
        med = precioTot/cant;
        cout << " " <<c.getNombre() << " : " << med << char(36) << endl;
    }

    linea();
}
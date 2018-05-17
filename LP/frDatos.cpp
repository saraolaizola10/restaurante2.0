#include "frDatos.h"
#include "frComun.h"
#include "../COMUN/Utilidades.h"
#include "../LN/Persona.h"
#include "../LN/Camarero.h"
#include "../LN/Comanda.h"
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

//CAMAREROS

int totalCamareros (sqlite3 *db)
{
	int total=0;

	list <Camarero> camareros = getCamareros(db);
	
	if(!camareros.empty())
		total = camareros.size();
	
	return total;
}

//0 si es nuevo, sino ya existe
int nuevoCamarero (sqlite3 *db, int dni)
{
	int nuevo=0;
	list <Camarero> camareros = getCamareros(db);
	
	if(!camareros.empty())
	{
		for (auto c: camareros)
		{
			if (dni==c.getDni())
			{
				nuevo++;
			}
		}
	}
}

void mostrarCamareros(sqlite3 *db)
{
	list <Camarero> camareros = getCamareros(db);

	if(!camareros.empty())
	{
		for (auto c: camareros)
		{
			cout << c.getNombre() << endl;
		}
	}
}

//PRODUCTOS

int totalProductos (sqlite3 *db)
{
	int total = 0;

	list <Producto> productos = getProductos(db);
	
	if (!productos.empty())
		total = productos.size();
	
	return total;
}

void mostrarProductos(sqlite3 *db)
{
	list <Producto> productos = getProductos(db);

	if(!productos.empty())
	{
		for (auto p: productos)
		{
			cout << p.getNombre() << endl;
		}
	}
	//CLASES: falta cambiar el metodo
}

//CATEGORIA

int totalCategorias (sqlite3 *db)
{
	int total = 0;

	list <Categoria> categorias = getCategorias(db);

	if (!categorias.empty())
		total = categorias.size();
	
	return total;
}

void mostrarCategorias (sqlite3 *db)
{
	list <Categoria> categorias = getCategorias(db);

	if(!categorias.empty())
	{
		for (auto c: categorias)
		{
			cout << c.getNombre() << endl;
		}
	}
	//CLASES: falta cambiar el metodo
}

//METODOS ADMINISTRADOR

int ultimoIDProducto (sqlite3 *db)
{
	int id=0;

	list <Producto> productos = getProductos(db);

	if (!productos.empty())
	{
		Producto a = productos.back();
		id = a.getId();
	}
	return id;
}

int ultimoIDCategoria (sqlite3 *db)
{
	int id=0;

	list <Categoria> categorias = getCategorias(db);

	if (!categorias.empty())
	{
		Categoria a = categorias.back();
		id=a.getId();
	}
	return id;
}

// ESTADISTICAS

void listaPlantilla(sqlite3 *db)
{
	list <Persona> personas;

	for (auto p: personas)
	{
        cout << p;
		cout << "\n" << endl;
	}
}

void mediaCamarero(sqlite3 *db)
{
    int dni,cantidad;
    float total;
    list <Camarero> camareros = getCamareros(db);
    list <Comanda> comandas = getComandas(db);

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

void actividadCamarero (sqlite3 *db)
{
    int dni,cantidad;
    float total;
    list <Camarero> camareros = getCamareros(db);
    list <Comanda> comandas = getComandas(db);

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

void valorMedioComandas (sqlite3 *db)
{
    float total, precio;
    list <Comanda> comandas = getComandas(db);

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

void mediaServicio (sqlite3 *db)
{
    float total, media;
    list <Comanda> comandas = getComandas(db);

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

void importeXmes (sqlite3 *db)
{
	//POR HACER
}

void PrecioMedioProductosxCategoria (sqlite3 *db)
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
            if (c.getNombre()==p.getCategoria())
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


//METODOS CAMARERO

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
	cout << "    ** "<< categoria << " **   \n" << endl;
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

	list <Producto> productos = getProductos(db);

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
    list <Producto> productos = getProductos(db);

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
    total = totalCuenta(db,cuentas,mesa);
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
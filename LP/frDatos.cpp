#include "frDatos.h"
#include "frComun.h"
#include "../COMUN/Utilidades.h"
#include "../LN/Persona.h"
#include "../LN/Administrador.h"
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

void mostrarCamareros(sqlite3 *db)
{
	int i=1;
	list <Camarero> camareros = getCamareros(db);

	if(!camareros.empty())
	{
		for (auto c: camareros)
		{
			cout << i << ". "<< c << endl;
			i++;
		}
	}
}

int totalAdministradores (sqlite3 *db)
{
	int total=0;

	list <Administrador> administradores = getAdministradores(db);
	
	if(!administradores.empty())
		total = administradores.size();
	
	return total;
}

void mostrarAdministradores(sqlite3 *db)
{
	int i=1;
	list <Administrador> administradores = getAdministradores(db);

	if(!administradores.empty())
	{
		for (auto a: administradores)
		{
			cout << i << ". " << a << endl;
			i++;
		}
	}
}

void mostrarPersonas (sqlite3 *db)
{
	int i=1;
	vector <Persona*> personas = getPersonas(db);
	
	if(!personas.empty())
	{
		for (auto p: personas)
		{
			cout << i << ". " << (*p) << endl;
			i++;
		}
	}
}


Persona* getPersona(sqlite3 *db,int dni)
{
	vector <Persona*> personas = getPersonas(db);

	if(!personas.empty())
	{
		for (auto p: personas)
		{
			if(dni==p->getDni())
				return p;
		}
	}
	return NULL;
}

int getCamarero(sqlite3 *db,int opcion)
{
	int num=0;
	int dni;
	list <Camarero> camareros = getCamareros(db);

	if(!camareros.empty())
	{
		for (auto c: camareros)
		{
			if (num==opcion)
				dni = c.getDni();
			num++;
		}
	}
	return dni;
}

int getAdministrador(sqlite3 *db,int opcion)
{
	int num=0;
	int dni;
	list <Administrador> administradores = getAdministradores(db);

	if(!administradores.empty())
	{
		for (auto a: administradores)
		{
			if (num==opcion)
				dni = a.getDni();
			num++;
		}
	}
	return dni;
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
	int i=1;
	list <Producto> productos = getProductos(db);

	if(!productos.empty())
	{
		for (auto p: productos)
		{
			cout << i << ". " << p << endl;
			i++;
		}
	}
}

int getIdProducto(sqlite3 *db, int opcion)
{
	int num=0;
	int id;

	list <Producto> productos = getProductos(db);

	for (auto p: productos)
	{
		if (num==opcion)
		{
			id = p.getId();
		}
		num++;
	}	
	return id;
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
			cout << c << endl; 
		}
	}
}

string getNombreCategoria (sqlite3 *db, int orden)
{
	list <Categoria> categorias = getCategorias(db);

	if(!categorias.empty())
	{
		for (auto c: categorias)
		{
			if (c.getOrden()==orden)
			{
				string nombre = c.getNombre();
				return nombre;
			}
		}
	}
	return 0;
}

//METODOS ADMINISTRADOR

int ultimoIDProducto (sqlite3 *db)
{
	int id=0;

	list <Producto> productos = getProductos(db);

	if(!productos.empty())
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

	for (auto c: categorias)
	{
		if (c.getId()>id)
			id=c.getId();
	}
	return id;
}

// ESTADISTICAS

void mostrarPlantilla (sqlite3 *db)
{
	vector <Persona*> personas = getPersonas(db);

	linea();

	cout << "\n       ** EMPLEADOS ** \n" << endl;
	if(!personas.empty())
	{
		for (auto p: personas)
		{
			cout << " - " << p->getNombre() << " "<< p->getApellido() << ", ";
			p->diPuesto();
			cout << endl;
		}
	}

	linea();
}

void mediaCamarero(sqlite3 *db)
{
    int dni,cantidad;
    float total;
    list <Camarero> camareros = getCamareros(db);
    list <Comanda> comandas = getComandas(db);

    linea();
    cout << "\n ** NOTA MEDIA DE LOS CAMAREROS ** \n\n" << endl;

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
        cout <<" - "<< c.getNombre() << " " << c.getApellido() << " " << total << endl;
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
  	cout << "\n ** ACTIVIDAD DE LOS CAMAREROS ** \n" << endl;
    cout << " (Camarero/Num.Comandas/Imp.Total)\n\n" << endl;

    for (auto c: camareros)
    {
        dni = c.getDni();
        cantidad=0;
        total=0.0;

        for (auto co: comandas) 
        {
            if(dni==co.getDni())
            {
                total += co.getTotal();   
                cantidad++;    
            }
        }
        cout << " - " << c.getNombre() << " " << c.getApellido() <<"   x"<< cantidad << " " << total << char(36) << endl;
    }
    linea();
}

void valorMedioComandas (sqlite3 *db)
{
    float total, precio;
    list <Comanda> comandas = getComandas(db);

    linea();
    cout << "\n ** PRECIO MEDIO POR COMANDA ** \n\n" << endl;
        
    total=0,0;

    for (auto c: comandas)
	{
		total += c.getTotal();
	}

    precio= total/comandas.size();

    cout << "  Han gastado una media de " << precio << char(36) << "\n por mesa \n" << endl;
    linea();
}

void mediaServicio (sqlite3 *db)
{
    float total, media;
    list <Comanda> comandas = getComandas(db);

    linea();
    cout << "\n  ** MEDIA DEL SERVICIO ** \n\n" << endl;
        
    total=0.0;

    for (auto c: comandas)
    {
        total+=c.getMedia();
        
    }
    media= total/comandas.size();
    
    cout << " La valoracion del servicio \n por parte de los cliente ha \n logrado un "<< media<<"/10" <<" de media \n" << endl;
    linea();
}

void PrecioMedioProductosxCategoria (sqlite3 *db)
{
    int cant;
    float med, precioTot;

    list <Producto> productos = getProductos(db);
    list <Categoria> categorias = getCategorias(db);

    linea();
    cout << "\n ** PRECIO MEDIO DE PRODUCTOS ** \n\n" << endl;
    
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
        cout << " - " <<c.getNombre() << " : " << med << char(36) << endl;
    }

    linea();
}

void importeXmes (sqlite3 *db)
{
    float total=0;
    int f,mes1,mes2;
    string meses[] = {"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};

    list <Comanda> comandas = getComandas(db);

    if (!comandas.empty())
    {
    	Comanda a = comandas.front();
    	f = a.getFechayhora();
    	mes1 = getMes(f);
    }

    linea();
    cout << "\n  ** INGRESOS POR MES ** \n\n" << endl;

    for (auto c: comandas)
    {
    	f = c.getFechayhora();
        mes2 = getMes(f);

        if (mes2==mes1)
        {
            total += c.getTotal();
        }
        else
        {
        	cout << " - " << meses[mes2] << " ";
        	mostrarAnyo(f);
        	cout << " : " << total << char(36)<< endl;
            mes1=mes2;
            total=0;
        }
    }

    if (!comandas.empty())
    {
    	Comanda b = comandas.back();
    	f = b.getFechayhora();
    	mes2 = getMes(f);
    	cout << " - " << meses[mes2] << " ";
    	mostrarAnyo(f);
   		cout << " : " << total << char(36)<< endl;
	    linea();
    }
}

void importeXdias (sqlite3 *db)
{
    float total=0;
    int f, hoy, dia1, dia2, mes1,mes2;
    string meses[] = {"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};

    list <Comanda> comandas = getComandas(db);

    if (!comandas.empty())
    {
    	Comanda a = comandas.front();
    	f = a.getFechayhora();
    	dia1= getDia(f);
    	mes1 = getMes(f);

    	hoy = getHora();
    	mes2=getMes(hoy);

    	if (mes1==mes2)
    	{
    		 linea();
  			 cout << "\n  ** INGRESOS POR DIAS ** \n\n" << endl;

    		for (auto c: comandas)
    		{
    			f = c.getFechayhora();
       			 dia2 = getDia(f);

       			if (dia2==dia1)
       			{
           		 total += c.getTotal();
      		 	}
       			else
       		 	{
        			cout << " - "<< dia1 << " de " << meses[mes1] << " : "<< total<<char(36)<<endl;
        		
          	  		dia1=dia2;
         	   		total=0;
       		 	}
  			}

  			cout<<" - "<< dia1 << " de " << meses[mes1] << " : "<< total<<char(36)<<endl;
			linea();
		}
		else
		{
			cout<<"Por ahora no hay actividad en "<< meses[mes1]<<endl;
		}
    }

   
}

void comandasHoy (sqlite3 *db)
{
    float total=0;
    int f,hoy,dia;
   
    list <Comanda> comandas = getComandas(db);


    if (!comandas.empty())
    {
    	f = getHora();
        hoy = getDia(f);
    
        linea();  
        cout << "\n  ** COMANDAS DE HOY,"; 
        mostrarDia();   
        cout << " ***" << endl;
        for (auto c: comandas)
        {
            f = c.getFechayhora();
            if (getDia(f)==hoy)
            {
                mostrarHorayMinuto(f);
                cout << " " << c.getTotal() << char(36) << " Valoracion "<<c.getMedia() << endl;
            }
        }
        linea();
    }
}

void mostrarSalarios (sqlite3 *db)
{
	float sueldo;
	vector <Persona*> personas = getPersonas(db);

	linea();

	cout << "\n ** SUELDO DE LOS EMPLEADOS ** \n\n" << endl;
	
	if(!personas.empty())
	{
		for (auto p: personas)
		{
			cout << " - " << p->getNombre() << " " << p->getApellido() << " : "<< p->getSueldo() << char(36) << endl;
		}
	}

	linea();
}

//METODOS CAMARERO

int MesaOcupada(int *cuentas[],int mesa,int nueva)
{
	if (cuentas[mesa][0]==0)		
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
	
	list <Producto> productos = getProductos(db);

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
	cout << "     Cuenta de la mesa "<< mesa+1 << endl;
   	cout << "   ";
   	mostrarHora();
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
    cout << "        TOTAL = "<< total << char(36) ; 
   	linea();
}


float totalCuenta(sqlite3 *db,int **cuentas, int mesa)
{
	float total=0;
	int posicion = cuentas[mesa][0];
	int id,cantidad;

	list <Producto> productos = getProductos(db);

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
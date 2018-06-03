#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../LD/EscrituraBD.h"
#include "../LD/LecturaBD.h"
#include "../LN/Camarero.h"
#include "../COMUN/Utilidades.h"
#include "frComun.h"
#include "../LD/sqlite3.h"
#include "frAdministrador.h"
#include "frCamarero.h"
using namespace std;

void nuevoEmpleado(sqlite3 *db)
{
    int opcion;

    cout << "\n\n El nuevo empleado es...\n" << endl;
    cout << " 1. Administrador" << endl;
    cout << " 2. Camarero\n" << endl;

    opcion = introducirOpcion (2);

    if (opcion==1)
    {
        Administrador *a=new Administrador();
        cin>> *a;
        altaAdministrador(db,a->getDni(),a->getNombre(),a->getApellido(),a->getTel(),a->getCargo(),a->getSueldo());
        delete a;
    }
    else
    {
        Camarero *c=new Camarero();
        cin>> *c;
        altaCamarero(db,c->getDni(),c->getNombre(),c->getApellido(),c->getTel(),c->getTurno(),c->getSueldo());
        delete c;
    }
}

void linea()
{
    cout << "\n__________________________________\n" << endl;
}

void accesoDenegado()
{
    cout << "Error. Acceso denegado" << endl;
}


int introducirOpcion(int opciones)
{
    int n;
    cout << "Introduzca opcion (1-" << opciones << "): " << endl;
    do
    {
        n=pedirNumero(0);
        if((n<0)||(n>opciones))
            cout << "Error. Introducir un numero entre 1 y "<<opciones<< "." << endl;
    } while ((n<0)||(n>opciones));
    return n;
}

int pedirDNI(sqlite3 *db)
{
    int dni;

    vector <Persona*> personas = getPersonas(db);

    cout << "Introduzca su DNI:" << endl;
    cin >> dni;
    cin.clear();

    for (auto p: personas)
    {
        if (p->getDni() == dni)
        {
            return dni;
        }
    }
    cout << " Error. No coincide con ningun DNI" << endl;
    return 0;
}

float pedirFloat()
{
    string str;
    int ok;
    float num;
    char *cstr;

    do 
    {
        ok=0;
        cin >> str;
        cin.clear();

        cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        cstr = ComaAPunto (cstr);

        if(sscanf(cstr,"%f",&num)!=1)
        {
            ok++;
            cout << "Error. Asegurate de introducir solo numeros"<<endl;
        }

    } while (ok!=0);

    return num;
}

int pedirNumero(int condicion)
{
    string str;
    int num,ok;

    do 
    {
        ok=0;
        cin >> str;
        cin.clear();

        const char *c = str.c_str();

        if ((condicion!=0)&&(str.size()!=condicion))
        {
            ok++;
            cout<<"Error. Asegurate de introducir "<<condicion<<" numeros"<<endl;
        }    
        if(sscanf(c,"%d",&num)!=1)
        {
            ok++;
            cout << "Error. Asegurate de introducir solo numeros"<<endl;
        }
    } while (ok!=0);

    return num;
}

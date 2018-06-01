#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
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
    cout << "1. Administrador" << endl;
    cout << "2. Camarero\n" << endl;

    opcion = introducirOpcion (2);

    if (opcion==1)
        AltaAdministrador(db);
    else
    {
        Camarero *a=new Camarero();
        cin>> *a;
        altaCamarero(db,a->getDni(),a->getNombre(),a->getApellido(),a->getTel(),a->getTurno(),a->getSueldo());
        delete a;
    }
}

void linea()
{
    cout << "\n__________________________________\n" << endl;
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
            break;
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
            break;
        }    
        if(sscanf(c,"%d",&num)!=1)
        {
            ok++;
            cout << "Error. Asegurate de introducir solo numeros"<<endl;
            break;
        }

    } while (ok!=0);

    return num;
}

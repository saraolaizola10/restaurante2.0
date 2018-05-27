#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
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
        AltaCamarero(db);
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

    } while ((n<0)||(n>opciones));
    return n;
}


float pedirFloat()
{
    string str;
    float d;
    int v;
    char *cstr;
    do
    {
        v=0;
        getline(cin, str);
        
        cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        cstr = ComaAPunto (cstr);
        string s (cstr);
        stringstream ss(s);

        //float d = atof(after);
            if (ss >> d)
            {
                if (ss.eof())
                {   
                    break;
                }
            }
            cout << "Error. Introducir valor valido" << std::endl;
            v++;
    } while(v!=0);

    delete[]cstr;
    cin.clear();
    return d;
}

int pedirNumero(int condicion)
{
    string line;
    int d, v;
    cin>>d;
    //do
    //{
    //    v=0;
    //    cin.ignore();
        //while (getline(cin, line))
        //{
        //    stringstream ss(line) ;
        //    if (ss >> d)
        //    {
        //        if (ss.eof())
        //        {   
        //            if (condicion!=0)
        //            {
        //                if (getLongitud(d)!=condicion)
        //                    cout << "Error. Introducir "<<condicion<<" digitos"<<endl;
        //                else
        //                    break;
        //            }
        //            else
        //                break;
        //        }
        //    }
        //    cout << "Error. Introducir valor valido" << endl;
        //    v++;
        //}
    //} while (v!=0);

    cin.clear();
    return d;
}

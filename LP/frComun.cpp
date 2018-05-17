#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "../COMUN/Utilidades.h"
using namespace std;

void linea()
{
    cout << "\n_______________________________________\n" << endl;
}


int introducirOpcion(int opciones)
{
    int n=0;
    cout << "Introduzca opcion (1-" << opciones << "): " << endl;
    do
    {
        n = pedirNumero(0);
        if ((n<0)||(n>opciones))
        {
            cout << "Error. Introducir valor valido" << endl;
        }
    } while ((n<0)||(n>opciones));
    return n;
}
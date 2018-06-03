#ifndef _FRCOMUN_H
#define _FRCOMUN_H

#include "../LD/sqlite3.h"

void nuevoEmpleado(sqlite3 *db);
void linea();
void accesoDenegado();
int pedirDNI(sqlite3 *db);
int introducirOpcion(int opciones);
int pedirNumero(int condicion);
float pedirFloat();

#endif
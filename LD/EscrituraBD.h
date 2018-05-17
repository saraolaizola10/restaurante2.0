#ifndef _ESCRITURABD_H
#define _ESCRITURABD_H

#include <string.h>
#include <iostream>
#include "../LD/sqlite3.h"
using namespace std;

void iniciarBD(sqlite3 *db);
int altaCamarero (sqlite3 *db,int dni, string nombre, string apellido, int tel);
int altaPersona (sqlite3 *db,int dni, string nombre,string apellido, int tel) ;
int altaProducto (sqlite3 *db,int id, string nombre,string categoria, float precio);
int altaCategoria (sqlite3 *db,int id, string nombre, int orden);
int altaComanda (sqlite3 *db,int dni, int fechayhora, float total, float media);

#endif
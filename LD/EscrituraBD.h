#ifndef _ESCRITURABD_H
#define _ESCRITURABD_H

#include <string.h>
#include <iostream>
#include "../LN/Categoria.h"
#include "../LD/sqlite3.h"
using namespace std;

void iniciarBD(sqlite3 *db);

int altaCamarero (sqlite3 *db,int dni, string nombre, string apellido, int tel, string turno, float sueldo);
int altaAdministrador (sqlite3 *db,int dni, string nombre,string apellido, int tel,string cargo, float sueldo);
int altaProducto (sqlite3 *db,int id, string nombre,string categoria, float precio);
int altaCategoria (sqlite3 *db,int id, string nombre, int orden);
int ordenarCategorias (sqlite3 *db,Categoria newCat);
int altaComanda (sqlite3 *db,int dni, int fechayhora, float total, float media);
int updateProducto (sqlite3 *db,int id, string nombre, float precio);
int updateAdministrador (sqlite3 *db,int dni, int tel,string cargo, float sueldo);

#endif
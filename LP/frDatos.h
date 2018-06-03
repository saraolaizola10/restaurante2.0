#ifndef _FRDATOS_H
#define _FRDATOS_H

#include "../LD/sqlite3.h"
#include "../LN/Camarero.h"
#include "../LN/Administrador.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int totalCamareros (sqlite3 *db);
void mostrarCamareros(sqlite3 *db);

int totalAdministradores (sqlite3 *db);
void mostrarAdministradores(sqlite3 *db);

void mostrarPersonas (sqlite3 *db);
Persona* getPersona(sqlite3 *db,int dni);

int getCamarero(sqlite3 *db,int opcion);
int getAdministrador(sqlite3 *db,int opcion);

int totalComandas (sqlite3 *db);
void mostrarComandas(sqlite3 *db);

int totalProductos (sqlite3 *db);
void mostrarProductos(sqlite3 *db);
int getIdProducto(sqlite3 *db, int opcion);

int totalCategorias (sqlite3 *db);
void mostrarCategorias(sqlite3 *db);
string getNombreCategoria (sqlite3 *db, int id);

int ultimoIDProducto (sqlite3 *db);
int ultimoIDCategoria (sqlite3 *db);
int getProducto(sqlite3 *db,std::string categoria, int opcion);
int MesaOcupada(int *cuentas[],int mesa,int nueva);
int MostrarProductosxCategoria (sqlite3 *db,std::string categoria);
void ImprimirCuenta (sqlite3 *db,int **cuentas, int mesa);
float totalCuenta(sqlite3 *db,int **cuentas, int mesa);

void mostrarPlantilla (sqlite3 *db);
void mediaCamarero (sqlite3 *db);
void actividadCamarero (sqlite3 *db);
void valorMedioComandas (sqlite3 *db);
void mediaServicio (sqlite3 *db);
void PrecioMedioProductosxCategoria (sqlite3 *db);
void importeXmes (sqlite3 *db);
void comandasHoy (sqlite3 *db);
void mostrarSalarios(sqlite3 *db);

#endif